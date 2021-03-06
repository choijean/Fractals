/*
* Jean Choi
* 6/28/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
*	The goal of this program is to create a line of tangent circles, 
* where there are n circles between any two points that the user clicks
* with the mouse. The user should be able to select the number of circles, n, 
* at the beginning of the program.
*/

#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>


int main()
{
	// must do this before G_init_graphics() if using repl.it
	G_choose_repl_display() ;
	
	// must do this before you do 'almost' any other graphical tasks 
	const int swidth = 600;
	const int sheight = 600;
	G_init_graphics (swidth,sheight) ;  // interactive graphics
	
	// number of lines
  int n;
  printf("\nPlease type in the number of circles: ");
  scanf("%d", &n);
	
	// clear the screen in a given color
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;

	// two points the user chooses and draw line between them
	G_rgb (0.318,0.5,0.732); // blue
	double p[2], q[2] ;
	G_wait_click(p);
	G_wait_click(q);
	G_line(p[0],p[1], q[0],q[1]) ;

	double distance = sqrt((p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]));
	double radius = distance/(2*n);

	double r[2], s[2];
	r[0]=p[0];
	r[1]=p[1];

	for (int i = 0; i < n; i++) {
		G_rgb (0.318,0.5*i/n,0.732);
		s[0]=r[0];
		s[1]=r[1];
		r[0] = p[0] + (q[0]-p[0]) * i/n + (q[0]-p[0])/(2*n);
		r[1] = p[1] + (q[1]-p[1]) * i/n + (q[1]-p[1])/(2*n);
		G_line(s[0], s[1], r[0], r[1]);
		G_fill_circle(r[0],r[1],2);
		G_circle (r[0], r[1], radius);
	}
	

	


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("tangentCirclesB.bmp") ;
}



