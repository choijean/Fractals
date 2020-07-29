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
void drawInnerTriangle(double x0, double y0, double x1, double y1, double x2, double y2);

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
	G_rgb (0, 0, 0.8) ;
	
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
	drawInnerTriangle(x0, y0, x1, y1, x2, y2);

	


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("triangleInTriangle.bmp") ;
}

// function finds the midpoints of a triangle with points 
// (x0, y0), (x1, y1), (x2, y2) and draws a triangle using those points
void drawInnerTriangle(double x0, double y0, double x1, double y1, double x2, double y2){

	double mx01 = x0 + (x1-x0)/2;	
	double my01 = y0 + (y1-y0)/2;
	double mx12 = x1 + (x2-x1)/2;
	double my12 = y1 + (y2-y1)/2;
	double mx20 = x2 + (x0-x2)/2;
	double my20 = y2 + (y0-y2)/2;
	double length = sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
	G_fill_triangle (mx01, my01, mx12, my12, mx20, my20) ;
	if (length <= 0){
		return;
	} else {
		//drawInnerTriangle(x0, y0, mx01, my01, mx20, my20);
		drawInnerTriangle(mx01, my01, x1, y1, mx12, my12);
		//drawInnerTriangle(mx20, my20, x2, y2, mx12, my12);
	}
}



