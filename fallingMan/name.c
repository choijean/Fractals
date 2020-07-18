/*
* Jean Choi
*	7/13/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make the Koch Snowflake 
* in a winter wonderland from the indoor perspective.
* The user clicks two points of the screen that indicate 
* the start and end of one edge of the initial triangle,
* as well as telling the program how many levels there should be.
*/

#include "FPToolkit.c"


void drawJ(double x, double y, double len);
void drawE(double x, double y, double len);
void drawA(double x, double y, double len);
void drawN(double x, double y, double len);
void drawC(double x, double y, double len);
void drawH(double x, double y, double len);
void drawO(double x, double y, double len);
void drawI(double x, double y, double len);
void name(double x, double y, double len);

int main()
{
	int key ; 
	// repl.it display
	G_choose_repl_display() ;
	
	// set dimensions
	const int swidth = 600 ;
	const int sheight = 600 ;
	G_init_graphics (swidth,sheight) ; 

	// clear the screen in a given color
  G_rgb(1,1,1);
  G_clear () ;


  name(10,10,4);
  

	//===============================================
	
  
	key =  G_wait_key() ; // pause so user can see results
}

void name(double x, double y, double len) {
  double dx = len*4;
  G_rgb(0,0,1);
  drawJ(x,y,len);
  drawE(x+dx,y,len);
  drawA(x+dx*2,y,len);
  drawN(x+dx*3,y,len);
  drawC(x+dx*4.5,y,len);
  drawH(x+dx*5.5,y,len);
  drawO(x+dx*6.5,y,len);
  drawI(x+dx*7.5,y,len);
}

void drawJ(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 3;
  for(double i = y; i <= dy+y; i++){
    if(y <= i && i <= y+(0.142*dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.142*dy) < i && i <= y+(0.286*dy)) {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else if ((y+(0.286*dy) < i && i <= y+(0.714*dy)) ||
      (y+(0.857*dy) < i && i <= y+dy)){
      G_line(x+(0.66*dx), i, x+dx, i);
    } else {}    
  }
}

void drawE(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
  for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.4*dy) < i && i <= y+(0.6*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.2*dy) < i && i <= y+(0.4*dy)) {
      G_line(x, i, x+(0.33*dx), i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawA(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.4*dy) < i && i <= y+(0.6*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.2*dy) < i && i <= y+(0.4*dy)) {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else {
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawN(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y+(0.8*dy) < i && i <= y+dy)) {
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawC(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
    }
  }
}

void drawH(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if(y <= i && i <= y+(0.571*dy)){
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else if (y+(0.571*dy) < i && i <= y+(0.714*dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
    }
  }
}

void drawO(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawI(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 1;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.714*dy)) ||
    (y+(0.857*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
    }
  }
}

