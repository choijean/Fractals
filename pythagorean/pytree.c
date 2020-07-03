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
	G_rgb (0.3, 0.5, 0.7) ; //light blue

	// 
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








	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("pytree.bmp") ;
}
