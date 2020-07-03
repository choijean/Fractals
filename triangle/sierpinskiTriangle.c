/*
* Jean Choi
*	6/30/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
*	The goal of this program is to create an equilateral triangle 
* that sits insde another equilateral triangle, using the midpoints
* of the larger triangle as the new points.
*/

#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>

// declare functions
void sierpinski(int n, double x0, double y0, double x1, double y1, double x2, double y2, double colorFactor);
double midpoint(double i, double j);

int main()
{
	// must do this before G_init_graphics() if using repl.it
	G_choose_repl_display() ;
	
	// must do this before you do 'almost' any other graphical tasks 
	const int swidth = 600;
	const int sheight = 600;
	G_init_graphics (swidth,sheight) ;  // interactive graphics

	// clear the screen in a given color
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;
	G_rgb (0.318,0.5,0.732);

	// number of lines
  int n;
  printf("\nPlease type in the number of layers (depth): ");
  scanf("%d", &n);

	double colorFactor = 1;
	
	// initial two points of triangle
	double x0 = 50;
	double y0 = 50;
	double x1 = 550;
	double y1 = 50;
	double x2 = (x0+x1)/2;
	double y2 = sqrt((x1-x0)*(x1-x0) - x2*x2);


	// draw initial triangle
	G_triangle(x0, y0, x1, y1, x2, y2);

	// call recursive function to draw inner triangles
	sierpinski(n, x0, y0, x1, y1, x2, y2, colorFactor);

	


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("sierpinskiTriangle.bmp") ;
}

// function finds the midpoints of a triangle with points 
// (x0, y0), (x1, y1), (x2, y2) and draws a triangle using those points
void sierpinski(int n, double x0, double y0, double x1, double y1, double x2, double y2, double colorFactor){

	// find the length of the triangle using two points
	double length = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
	

	if (n <= 0 || length <= 0){
		return;
	} else {
		sierpinski(n-1, midpoint(x0, x1), midpoint(y0, y1), x1, y1, midpoint(x1, x2), midpoint(y1, y2), colorFactor-(1/n));
		sierpinski(n-1, x0, y0, midpoint(x0, x1), midpoint(y0, y1),  midpoint(x0, x2), midpoint(y0, y2), colorFactor);
		sierpinski(n-1, midpoint(x2, x0), midpoint(y2, y0), x2, y2, midpoint(x1, x2), midpoint(y1, y2), colorFactor);

		//choose color
		G_rgb (0.318,0.5*(colorFactor-(1/n)),0.732);
		G_fill_triangle (midpoint(x0, x1), midpoint(y0, y1), midpoint(x1, x2), midpoint(y1, y2), midpoint(x2, x0), midpoint(y2, y0));
	}
;
}

// function determines the midpoint between two values
double midpoint(double i, double j){
	return (i+j)/2;
}



