#include "FPToolkit.c"

typedef struct Production
{

  char var ;
  char axiom[100] ;
  char rule[100] ;

} Production ;

Production prd[10] ;
int rule_num = 0 ;

char u[1000000], v[1000000] ;
double angle, gangle, flen ;
int depth ;

double x[1000000], y[1000000], z[1000000];
int top = -1;

int isempty() {
  return (top <= -1) ? 1: 0;
}
   
int isfull() {
  return (top >= 1000000) ? 1 : 0;
}

void stackinfo(){
printf("top %d: %lf %lf %lf\n", top, x[top], y[top], z[top]);
}

double popx() {
  double data;
   if(!isempty()) {
      data = x[top];
      return data;
   } else {
      printf("Could not retrieve data, Stack X is empty.\n");
   }
}

double popy() {
  double data;
   if(!isempty()) {
      data = y[top];
      return data;
   } else {
      printf("Could not retrieve data, Stack Y is empty.\n");
   }
}

double popz() {
  double data;
   if(!isempty()) {
      data = z[top];
      return data;
   } else {
      printf("Could not retrieve data, Stack Z is empty.\n");
   }
}

void push(double xd, double yd, double zd) {
   if(!isfull()) {
      top++;  
      x[top] = xd;
      y[top] = yd;
      z[top] = zd;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

/*
//  plant requires a global stack to be implemented because 
//  [ means put turtle's current location and angular 
//  direction on the stack, and ] means pop info from stack and 
//  position the turtle according to the location and angular 
//  information popped.
*/
void plant()
{

  gangle = 90 ;
  angle = 22.5 ;

  strcpy(prd[rule_num].axiom,"A") ;

  rule_num++ ;

  prd[rule_num].var = 'A' ;
  strcpy(prd[rule_num].rule,"F-[[A]+A]+F[+FA]-A") ;
  rule_num++ ;

  prd[rule_num].var = 'F' ;
  strcpy(prd[rule_num].rule,"FF") ;
  rule_num++ ;

}


void square_wave()
{

  gangle = 90 ; // initial angle
  angle = 90 ;  // angle change for '+' and '-'
  // flen = 50 ;  // how far a forward movement goes, determined by autoplacer now
  
  rule_num = 0 ;

  strcpy(prd[rule_num].axiom,"A") ;
  rule_num++ ;

  prd[rule_num].var = 'A' ;
  strcpy(prd[rule_num].rule,"f-f-B") ;
  rule_num++ ;

  prd[rule_num].var = 'B' ;
  strcpy(prd[rule_num].rule,"f+f+A") ;
  rule_num++ ;

}


void print_string(char *u)
{

  int k ;
  k = 0 ;
  while(u[k] != '\0') {
    printf("%c",u[k]) ;
    k++ ;
  }
  printf("\n") ;
}


int find_rule(char s)
{
  int k ;
  for(k=1;k<rule_num;k++) {
    if(prd[k].var == s) { return k ; }
  }
  return -1 ;
}


void string_builder()
{
  int k, c, loc ;
  
  // build array u
  u[0] = '\0' ;
  strcat(u,prd[0].axiom) ;
  print_string(u) ;


  // recur depth times to build string
  
  
  for(c=0;c<depth;c++) {
    v[0] = '\0' ;
    k = 0 ;
    while(u[k] != '\0') {
      
      // if symbol is a variable
      loc = find_rule(u[k]) ;
      if(loc != -1) {
	strcat(v,prd[loc].rule) ;
      }
      
      // if symbol is not a variable
      else {
	char temp[2] ;
	temp[0] = u[k] ;  temp[1] = '\0' ;
	strcat(v,temp) ;
      }
      
      k++ ;
    }
    strcpy(u,v) ;
    print_string(u) ;
    printf("\n") ;
  }
  
    // print_string(u) ;
    // printf("\n") ;
}


void autoplacer(int swidth, int sheight, double *p)
{
  printf("autoplace");
  int k ;
  double x0,y0, x1,y1;
  double cur_angle = gangle ;
  double cur_locx, cur_locy ;
  double minx, maxx, miny, maxy = 0;
  x0 = y0 = 0; flen = 1;

  k = 0 ;
  while(u[k] != '\0') {
    if(u[k] == '+') { cur_angle += angle ; }
    if(u[k] == '-') { cur_angle -= angle ; }
    if(u[k] == 'f' || (u[k] >= 'A' && u[k] <= 'Z')) { 
      x1 = x0 + flen*cos(cur_angle*M_PI/180.0) ;
      y1 = y0 + flen*sin(cur_angle*M_PI/180.0) ;
      x0 = x1 ;  y0 = y1 ;
      if(x1<minx)
        minx = x1 ;
      if(x1>maxx)
        maxx = x1 ;
      if(y1<miny)
        miny = y1 ;
      if(y1>maxy)
        maxy = y1 ;
      x0 = x1 ; y0 = y1 ;
    }
    if (u[k] == '[') { //push on stack
      // printf("%d: \n", k);
      push(x0, y0, cur_angle);
      //stackinfo();
    }
    if (u[k] == ']') { //pop stack
      // printf("%d: ", k);
      x0 = popx();
      y0 = popy();
      cur_angle = popz();
      top--;
      //stackinfo();
    }
    k++ ;
  }

  // calculate new bounding box;
  double dx = maxx-minx;
  double dy = maxy-miny;
  double dnx, dny;
  if (dx > dy) {
    dnx = 0.9 * swidth;
    dny = dnx * dy / dx;
  } else {
    dny = 0.9 * sheight;
    dnx = dny * dx / dy;
  }

  // calculate new length 
  double multiplier = dnx/dx ; // or dny/dy
  p[2] = multiplier ;

  // find delta minx to 0, and delta miny to 0
  double dminx = 0-minx ;
  double dminy = 0-miny ;

  // calculate new x,y ;
  p[0] = (swidth-dnx)/2 + dminx * multiplier;
  p[1] = (sheight-dny)/2 + dminy * multiplier;
}


void string_interpreter()  // like an etch-a-sketch
{
  int k ;
  double x0,y0, x1,y1, p[3] ;

  int swidth, sheight ;
  double cur_angle = gangle ;
  double cur_locx, cur_locy ;
  
  swidth = 600 ;  sheight = 600 ;
  //  swidth = 800 ;  sheight = 800 ;
  //  swidth = 800 ;  sheight = 300 ;  
  //  swidth = 300 ;  sheight = 800 ;
  
  autoplacer(swidth, sheight, p) ;
  x0 = p[0] ;
  y0 = p[1] ;
  flen = p[2] ;

  // if autoplace doesn't work
  // x0 = swidth/2.0 ;
  // y0 = sheight/2.0 ;
  // flen = 10 ;
  
  G_init_graphics(swidth, sheight) ;

  G_rgb(1,0,0) ;
  // G_fill_circle(swidth/2,swidth/2,5) ;
  G_rgb(0,0,0) ;


  k = 0 ;
  while(u[k] != '\0') {
    if(u[k] == '+') { cur_angle += angle ; }
    if(u[k] == '-') { cur_angle -= angle ; }
    if(u[k] == 'f' || (u[k] >= 'A' && u[k] <= 'Z')) { 
      x1 = x0 + flen*cos(cur_angle*M_PI/180.0) ;
      y1 = y0 + flen*sin(cur_angle*M_PI/180.0) ;
      G_rgb(0,0,0) ;
      G_line(x0,y0,x1,y1) ;
      x0 = x1 ;  y0 = y1 ;
    }
    if (u[k] == '[') { //push on stack
      push(x0, y0, cur_angle);
    }
    if (u[k] == ']') { //pop stack
      x0 = popx();
      y0 = popy();
      cur_angle = popz();
      top--;
    }
    k++ ;
  }
}



int main()
{
  G_choose_repl_display();

  printf("Please specify the level of depth for the l-system: ") ;
  scanf("%d",&depth) ;
  
  //square_wave() ;
  plant() ;
  
  string_builder() ;
  string_interpreter() ;

  //===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

  // save file
	G_save_to_bmp_file("plant.bmp");


}
