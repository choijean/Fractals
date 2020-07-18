/*
* Jean Choi
*	7/16/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* MIDTERM: OPTION ONE
* Written for REPL
*/

#include "FPToolkit.c"

double swidth = 600;
double sheight = 600;

// for string builder
char v[1000];
char u[1000];
char temp[1000];
typedef struct Production {
	char var ;
	char axiom[100] ;
	char rule[100] ;
} Production ;
const int numRules = 2;

// for string interpreter
double cangle = M_PI/2.0;
double angle = (M_PI/3.0);
double sx = 50;   //turtle starts here
double sy = 50;   //turtle starts here
double length = 5;

// for autoplacer
double minx, miny, maxx, maxy ;
double apx, apy, aplength;

void buildString(int depth){
  struct Production prd[numRules];
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"F") ;
	rule_num++ ;
	// RULE 1
	prd[rule_num].var = 'F' ;
	strcpy(prd[rule_num].rule, "F+F--F+F") ;
	rule_num++ ;

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < depth; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      }
      else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  //printf("u: %s\n", u);
}


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

void autoplacer() {
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
    } else if (u[i] == 'F') {
      nx = aplength * cos(cangle) + apx;
      ny = aplength * sin(cangle) + apy;
      if(nx < minx)
        minx = nx;
      if(nx > maxx)
        maxx = nx;
      if(ny < miny)
        miny = ny;
      if(ny > maxy)
        maxy = ny;
      apx = nx; apy = ny;
    } else {}
  }
  //printminmax();

  //calculate new bounding box
  double dx = maxx-minx;
  double dy = maxy-miny;
  double dnx, dny;
  if (dx > dy) {
    dnx = 0.9 * swidth;
    dny = dnx * dy / dx;
  } else {
    dny = 0.9 * swidth;
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


void stringInterpreter(){
  double x = sx; double y = sy;
  double nx, ny;

  autoplacer();

  x = sx; y = sy;

  for(int i = 0; i < strlen(u); i++) {
    if(u[i] == '+') {
      cangle += angle;
    } else if (u[i] == '-') {
      cangle -= angle;
    } else if (u[i] == 'F') {
      nx = length * cos(cangle) + x;
      ny = length * sin(cangle) + y ;
      G_line(x, y, nx, ny);
      x = nx; y = ny;
    } else {}

  }
}

int main()
{

  G_choose_repl_display() ;
  G_init_graphics(swidth, sheight) ;

  G_rgb(1,1,1) ;
  G_clear() ;

  G_rgb(0,0,0) ;

	// get depth from user 
  int depth;
  printf("Please type in the depth: \n");
  scanf("%d", &depth);

  buildString(depth);
  stringInterpreter();

	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("turtleGraphic.bmp") ;


}

