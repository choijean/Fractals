/*
* Jean Choi
*	7/2/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
*	The goal of this program is to a pythagorean diagram based on
* the two points of the hypotenuse of a right triangle.
*/

#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#    define M_PI 3.1415926535897932
#endif

double absd(double d) {
	return d < 0 ? -d : d ;
}

double min(double m1, double m2){
	return m1 < m2 ? m1 : m2;
}

double dist(double m1, double m2){
	return absd(m1 - m2);
}

void pytree(double x0, double y0, double x1, double y1, int n, double scale, double height){

	// determine second set of points (x2, y2), (x3, y3)
	double x2, y2, x3, y3, x4, y4, xm, ym, g;
	x2 = x1 - (y1 - y0);						y2 = height * y1 + (x1 - x0);
	x3 = x0 - (y1 - y0);						y3 = height * y0 + (x1 - x0);

	// determine 3rd point (x4, y4) to make third point of right triangle,
	// using (x2, y2), (x3, y3) 
	g = sqrt(scale*(1-scale)) ;
	xm = x3 + scale * (x2 - x3) ;
	ym = y3 + scale * (y2 - y3) ;

	x4 = xm - g * (y2 - y3) ;
	y4 = ym + g * (x2 - x3) ;

  double boxX[4], boxY[4];
  boxX[0] = x0;     boxY[0] = y0;
  boxX[1] = x1;     boxY[1] = y1;
  boxX[2] = x2;     boxY[2] = y2;
  boxX[3] = x3;     boxY[3] = y3;
  double triangleX[3], triangleY[3];
  triangleX[0] = x3;    triangleY[0] = y3;
  triangleX[1] = x2;    triangleY[1] = y2;
  triangleX[2] = x4;    triangleY[2] = y4;

  // draw box
  G_rgb (0.4, 0.167, 0.167) ; //brown
  G_fill_polygon(boxX, boxY, 4);
  // draw triangle
  G_rgb (0.5, 0.167, 0.167) ; //brown
  G_fill_polygon(triangleX, triangleY, 3);

	//draw lines for rectangle
  G_rgb (0,0,0) ; //black
	G_line(x0, y0, x1, y1) ;
	G_line(x0, y0, x3, y3) ;
	G_line(x1, y1, x2, y2) ;
	G_line(x2, y2, x3, y3) ;

  //draw lines for triangle
	G_line(x2, y2, x4, y4) ;
	G_line(x3, y3, x4, y4) ;

	if(n <= 0){
		return;
	}
	else {
		pytree(x3, y3, x4, y4, n-1, scale, height);
		pytree(x4, y4, x2, y2, n-1, scale, height);
	};
}

int main()
{
	// repl.it display
	G_choose_repl_display() ;
	
	// set dimensions
	const int swidth = 600 ;
	const int sheight = 600 ;
	G_init_graphics (swidth,sheight) ; 

	// clear the screen in a given color
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;


	// number of lines
  int n;
  printf("\nPlease type in the number of layers (depth): ");
  scanf("%d", &n);

	// two initial points (x0, y0), (x1, y1)
	double x0, y0, x1, y1, dx0, dy0;
  x0 = 350 ; 		y0 = 40;
	x1 = 430 ;		y1 = 40;



	pytree(x0, y0, x1, y1, n, 0.66, 1);








	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("pytree.bmp") ;
}
