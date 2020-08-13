/*
* Jean Choi
*	8/11/2020
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
double cangle = 0;
double angle = 0;
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
void buildSeaweed2(int depth){
  struct Production prd[rule_num];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"F") ;
	rule_num++ ;
  // RULE 1
  prd[rule_num].var = 'F' ;
  strcpy(prd[rule_num].rule,"F[+F[+F-]][-F[++F]]F") ;
  rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      } else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}

void buildSeaweed(int depth){
  struct Production prd[rule_num];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"F") ;
	rule_num++ ;
  // RULE 1
  prd[rule_num].var = 'F' ;
  strcpy(prd[rule_num].rule,"F[--F[-F+]][+F[-F]]F") ;
  rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      } else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}

// builds a string based on a given axiom and rules
void buildStarfish(int depth){
  struct Production prd[rule_num];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"F-F-F-F-F") ;
	rule_num++ ;
  // RULE 1
  prd[rule_num].var = 'F' ;
  strcpy(prd[rule_num].rule,"F-F-F++F+F-F") ;
  rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      } else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}

void buildTree(int depth){
  struct Production prd[rule_num];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"F") ;
	rule_num++ ;
  // RULE 1
  prd[rule_num].var = 'F' ;
  strcpy(prd[rule_num].rule,"F[+FF][-FF]F[-F][+F]F") ;
  rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      } else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}

// resize and center image
void autoplacer(double deg, double sf) {
  //by the end of this function, sx, sy, length should change
  //set minx, miny, maxx, maxy to initial point
  minx = 0 ; maxx = 0 ; miny = 0 ; maxy = 0 ;
  apx = 0; apy = 0; aplength = 1;
  double nx, ny;

  cangle = deg;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } else if (u[i] == '-') {
      cangle -= angle;
    } else if (u[i] == 'F' || u[i] == 'A' || u[i] == 'B') {
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
void stringInterpreter(double sx, double sy, double deg, double sf){
  double nx, ny;

  autoplacer(deg, sf);

  double x = sx; double y = sy;

  // G_rgb(1,0,0);
  // G_fill_circle(x, y, 2);
  cangle = deg;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } 
    if (u[i] == '-') {
      cangle -= angle;
    } 
    if (u[i] == 'F' || u[i] == 'A' || u[i] == 'B') {
      nx = length * cos(cangle*M_PI/180.0) + x;
      ny = length * sin(cangle*M_PI/180.0) + y ;
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

// decodes the string into a graphic
void stringInterpreter2(double deg, double sf){
  double nx, ny;

  autoplacer(deg, sf);

  double x = sx; double y = sy;

  // G_rgb(1,0,0);
  // G_fill_circle(x, y, 2);
  cangle = deg;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } 
    if (u[i] == '-') {
      cangle -= angle;
    } 
    if (u[i] == 'F' || u[i] == 'A' || u[i] == 'B') {
      nx = length * cos(cangle*M_PI/180.0) + x;
      ny = length * sin(cangle*M_PI/180.0) + y ;
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


int main()
{

  G_choose_repl_display() ;
  G_init_graphics(swidth, sheight) ;

  G_rgb(1,1,1) ;
  G_clear() ;


  G_rgb(0,0,0);
  //seaweed right
  angle = 17;
  buildSeaweed2(5);
  // stringInterpreter(500, -150, 90, 1);
  stringInterpreter2(90, .8);

  // //seaweed left
  // angle = 15;
  // buildSeaweed(4);
  // // stringInterpreter(100, -150, 90, .8);
  // stringInterpreter2(90, .8);

  // //starfish
  // angle = 72;
  // buildStarfish(5);
  // // stringInterpreter(200, 475, 0, .07);
  // stringInterpreter2(90, .8);

  // //wave pt1
  // angle = 36 ;
  // buildTree(4);
  // // stringInterpreter(30, -385, 80, .8);
  // stringInterpreter2(90, .8);


  // //===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results


  // save file
	G_save_to_bmp_file("wave.bmp") ;
}

