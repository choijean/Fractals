/*
* Jean Choi
*	7/7/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make a circle centered at P0, 
* only using G_point()
*/

#include "FPToolkit.c"

#ifndef M_PI
#    define M_PI 3.1415926535897932
#endif


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
 
	// select two points
	printf("\nClick two points on the screen: ");
	double p[2], q[2] ;
	double dx, dy;
	G_wait_click(p) ;
	G_fill_circle(p[0],p[1],2) ;
	G_wait_click(q) ;
	G_fill_circle(q[0],q[1],2) ;

	// calculate radius
	double r = sqrt((q[0]-p[0])*(q[0]-p[0]) + (q[1]-p[1])*(q[1]-p[1]));

	// plot points
	double x, y; 
	for(double i = 0; i <= (2*M_PI); i += .001){
		x = cos(i*(2*M_PI)) * r + p[0];
		y = sin(i*(2*M_PI)) * r + p[1];
		G_point(x, y);
	}




	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("circle.bmp") ;
}

