/*
* Jean Choi
*	7/16/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to draw the turtle graphics
* for the rule replacement set:
* Axiom = F
* Rule  = F -> F+F--F+F 
*/

#include "FPToolkit.c"

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
double angle = (M_PI/3.0);
double sx = 300;
double sy = 50;
double length = 5;

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
  printf("u: %s\n", u);
}

void stringInterpreter(){
  double cangle = M_PI/2.0;
  double x = sx;
  double y = sy;
  double nx, ny;
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
  G_init_graphics(600, 600) ;

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

