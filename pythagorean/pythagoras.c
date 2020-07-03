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

double absf(double q);

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
	G_rgb (0.3, 0.5, 0.7) ;

	// two points the user chooses and draw line between them
	double p0[2], p1[2] ;
	G_wait_click(p0) ;
	G_fill_circle(p0[0], p0[1], 2) ;
	G_wait_click(p1);
	G_fill_circle(p1[0], p1[1], 2) ;
	G_line(p0[0],p0[1], p1[0], p1[1]) ;

	// calculate p2
	double p2[2];
	p2[1] = p0[1];
	p2[0] = p1[0];
	G_fill_circle(p2[0], p2[1],2) ;
	G_line(p0[0], p0[1], p2[0], p2[1]) ;
	G_line(p1[0], p1[1], p2[0], p2[1]) ;

	// calculate length a and b
	double a = p1[1] - p0[1];
	double b = p1[0] - p0[0];

	// calculate points for box a
	int numxy = 4;
	double ax[numxy];
	double ay[numxy];
	ax[0] = p2[0];									ay[0] = p2[1];
	ax[1] = p1[0];  								ay[1] = p1[1];
	ax[2] = ax[1] + absf(ay[1]-ay[0]);	ay[2] = ay[1];
	ax[3] = ax[2]; 									ay[3] = ay[0];
	Gi_rgb (38, 130, 142);
	G_fill_polygon(ax, ay, numxy);
	

	// calculate points for box b
	double bx[numxy];
	double by[numxy];
	bx[0] = p0[0];									by[0] = p0[1];
	bx[1] = p2[0];  								by[1] = p2[1];
	bx[2] = bx[1];									by[2] = by[1] - absf(bx[1]-bx[0]);
	bx[3] = bx[0]; 									by[3] = by[2];
	Gi_rgb (49,104, 142) ;
	G_fill_polygon(bx, by, numxy);

	// calculate points for box c
	double cx[numxy];
	double cy[numxy];
	cx[0] = p0[0];									cy[0] = p0[1];
	cx[1] = p1[0];									cy[1] = p1[1];
	cx[2] = cx[1] - a;							cy[2] = cy[1] + b;
	cx[3] = cx[0] - a;							cy[3] = cy[0] + b;
	Gi_rgb (62, 74, 137) ;
	G_fill_polygon(cx, cy, numxy);



	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("pythagoras.bmp") ;
}

double absf(double q){
	return q < 0 ? -q : q; 
}