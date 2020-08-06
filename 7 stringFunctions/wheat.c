/*
* Jean Choi
*	7/16/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*/

#include "FPToolkit.c"

double swidth = 600;
double sheight = 600;

// for string builder
char v[1000000];
char u[1000000];
char temp[1000000];
typedef struct Production {
	char var ;
	char axiom[100] ;
	char rule[100] ;
} Production ;
const int rule_num = 0;

// for string interpreter
double cangle = 90;
double angle = 10;
double sx = 50;   
double sy = 50;  
double length = 5;

// for autoplacer
double minx, miny, maxx, maxy ;
double apx, apy, aplength;

// for stack
double x[1000000], y[1000000], z[1000000];
int top = -1;

int isempty() {
  return (top<=-1) ? 1: 0;
}

int isfull() {
  return (top>=1000000) ? 1 : 0;
}

void stackinfo(){
printf("top %d: %lf %lf %lf\n", top, x[top], y[top], z[top]);
}

double popx() {
  return !isempty() ? x[top] : printf("Stack X is empty.\n");
}

double popy() {
  return !isempty() ? y[top] : printf("Stack Y is empty.\n");
}

double popz() {
  return !isempty() ? z[top] : printf("Stack Z is empty.\n");
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


// builds a string based on a given axiom and rules
void buildString(int depth){
  struct Production prd[rule_num];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"A") ;
	rule_num++ ;
  // RULE 1
  prd[rule_num].var = 'A' ;
  strcpy(prd[rule_num].rule,"F-[A]--A++[++A]") ;
  rule_num++ ;
	// RULE 2
	prd[rule_num].var = 'F' ;
	strcpy(prd[rule_num].rule, "FF") ;
	rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      } else if( v[i] == prd[2].var) {
        strcat(u, prd[2].rule);
      } else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}


// debug function: drawing the bounding box of the original drawing
void printminmax() {
  printf("minx: %lf\t", minx);
  printf("maxx: %lf\n", maxx);
  printf("miny: %lf\t", miny);
  printf("maxy: %lf\n", maxy);
  G_line(minx,miny,maxx,miny);
  G_line(minx,miny,minx,maxy);
  G_line(maxx,maxy,maxx,miny);
  G_line(maxx,maxy,minx,maxy);
}

// resize and center image
void autoplacer(double sf) {
  //by the end of this function, sx, sy, length should change
  //set minx, miny, maxx, maxy to initial point
  minx = 0 ; maxx = 0 ; miny = 0 ; maxy = 0 ;
  apx = 0; apy = 0; aplength = 1;
  double nx, ny;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } else if (u[i] == '-') {
      cangle -= angle;
    } else if (u[i] == 'F' || u[i] == 'A') {
      nx = aplength * cos(cangle*M_PI/180.0) + apx;
      ny = aplength * sin(cangle*M_PI/180.0) + apy;
      if(nx < minx)
        minx = nx;
      if(nx > maxx)
        maxx = nx;
      if(ny < miny)
        miny = ny;
      if(ny > maxy)
        maxy = ny;
      apx = nx; apy = ny;
    } else if (u[i] == '[') { // push on stack
      //printf("push");
      push(apx,apy,cangle);
    } else if (u[i] == ']') { // pop off stack
      //printf("pop");
      apx = popx();
      apy = popy();
      cangle = popz();
      top--;
    } else {}
  }
  //printminmax();

  //calculate new bounding box
  double dx = maxx-minx;
  double dy = maxy-miny;
  double dnx, dny;
  if (dx > dy) {
    dnx = sf * swidth;
    dny = dnx * dy / dx;
  } else {
    dny = sf * sheight;
    dnx = dny * dx / dy;
  }
  // printf("dnx %lf\n", dnx);
  // printf("dny %lf\n", dny);

  // calculate new length
  double xmultiplier = dnx/dx;
  length = xmultiplier;

  //draw new bounding box
  // G_line(300-dnx/2, 300-dny/2, 300-dnx/2, 300+dny/2);
  // G_line(300-dnx/2, 300-dny/2, 300+dnx/2, 300-dny/2);
  // G_line(300+dnx/2, 300+dny/2, 300-dnx/2, 300+dny/2);
  // G_line(300+dnx/2, 300+dny/2, 300+dnx/2, 300-dny/2);
  // printf("nminx: %lf\t", 300-dnx/2);
  // printf("nmanx: %lf\n", 300+dnx/2);
  // printf("nminy: %lf\t", 300-dny/2);
  // printf("nmaxy: %lf\n", 300+dny/2);

  // find delta minx to 0, and delta miny to 0
  double dminx = 0-minx;
  double dminy = 0-miny;

  // calculate new sx, sy
  sx = (swidth-dnx)/2 + dminx * xmultiplier;
  sy = (sheight-dny)/2 + dminy * xmultiplier;
}

// decodes the string into a graphic
void stringInterpreter(double sx, double sy, double sf){
  double nx, ny;

  autoplacer(sf);

  double x = sx; double y = sy;
  cangle = 90;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } 
    if (u[i] == '-') {
      cangle -= angle;
    } 
    if (u[i] == 'F' || u[i] == 'A') {
      nx = length * cos(cangle*M_PI/180.0) + x;
      ny = length * sin(cangle*M_PI/180.0) + y ;
      G_rgb(0,0,0) ;
      G_line(x, y, nx, ny);
      x = nx; y = ny;
    } 
    if (u[i] == '[') { // push on stack
      push(x,y,cangle);
    } 
    if (u[i] == ']') { // pop off stack
      x = popx();
      y = popy();
      cangle = popz();
      top--;
    } 
  }
}

void background(){
  double x0,y0 , x1,y1, dx, dy ;
  double sf ;

  double r,g,b;
  double r1,g1,b1 ;
  double r2,g2,b2 ;
  y0 = 0 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  r1 = 0.254 ;  g1 = 0.412 ;  b1 = 0.557 ;
  // r2 = 0.286 ;  g2 = 0.490 ;  b2 = 0.667 ;
  r2 = 1.0; g2 = 0.0 ; b2 = 0.0;
    
  for(int k=y0;k<=y1;k++) {

    sf = (k-y0)/dy ;
    r = r1 + sf*(r2-r1) ;  g = g1 + sf*(b2-g1) ;  b = b1 + sf*(b2-b1) ;
    G_rgb(r,g,b) ;
    G_line(0,k,600,k) ;
      
  }
}

void bird1(int sx, int sy){
   G_rgb (0.0, 0.0, 0.0) ; // black
   double bx[6], by[6];
   bx[0] = sx ;        by[0] = sy ;
   bx[1] = bx[0]-5 ;   by[1] = by[0]+5 ;
   bx[2] = bx[1]-6 ;   by[2] = by[1]-1 ;
   bx[3] = bx[2]-4 ;   by[3] = by[2]-6 ;
   bx[4] = bx[3]+3 ;   by[4] = by[3]+9 ;
   bx[5] = bx[4]+7 ;   by[5] = by[4]+1 ;
   G_fill_polygon (bx,by,6) ;
   bx[0] = sx-2 ;        by[0] = sy ;
   bx[1] = bx[0]+5 ;   by[1] = by[0]+5 ;
   bx[2] = bx[1]+6 ;   by[2] = by[1]-1 ;
   bx[3] = bx[2]+4 ;   by[3] = by[2]-6 ;
   bx[4] = bx[3]-3 ;   by[4] = by[3]+9 ;
   bx[5] = bx[4]-7 ;   by[5] = by[4]+1 ;
   G_fill_polygon (bx,by,6) ;
}

void bird2(int sx, int sy){
   G_rgb (0.0, 0.0, 0.0) ; // black
   double bx[6], by[6];
   bx[0] = sx ;        by[0] = sy ;
   bx[1] = bx[0]-6 ;   by[1] = by[0]+6 ;
   bx[2] = bx[1]-8 ;   by[2] = by[1]-2 ;
   bx[3] = bx[2]-8 ;   by[3] = by[2]-7 ;
   bx[4] = bx[3]+6 ;   by[4] = by[3]+11 ;
   bx[5] = bx[4]+10 ;   by[5] = by[4]+2 ;
   G_fill_polygon (bx,by,6) ;
   bx[0] = sx-2 ;        by[0] = sy ;
   bx[1] = bx[0]+6 ;   by[1] = by[0]+6 ;
   bx[2] = bx[1]+8 ;   by[2] = by[1]-2 ;
   bx[3] = bx[2]+8 ;   by[3] = by[2]-7 ;
   bx[4] = bx[3]-6 ;   by[4] = by[3]+11 ;
   bx[5] = bx[4]-10 ;   by[5] = by[4]+2 ;
   G_fill_polygon (bx,by,6) ;
}

void border(){
  G_rgb(0,0,0);
  for(int i = 0; i <= 4; i++){
    G_line(0,i,600,i);
    G_line(i,0,i,600);
  }
  for(int i = 595; i <= 600; i++){
    G_line(0,i,600,i);
    G_line(i,0,i,600);
  }
}

int main()
{

  G_choose_repl_display() ;
  G_init_graphics(swidth, sheight) ;

  G_rgb(1,1,1) ;
  G_clear() ;

  //background color
  background();

  //sun
  G_rgb(0.8,0.8,0.65);
  G_fill_circle(450,475,40);

  //birds
  bird1(400, 350);
  bird2(375, 365);

  //border
  border();

  //plant
  cangle = 90;
  buildString(7);
  stringInterpreter(150,0,0.5);

  // save file
	G_save_to_bmp_file("wheat.bmp") ;
}

