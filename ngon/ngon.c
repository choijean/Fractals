/*
* Jean Choi
*	7/7/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The purpose of this program is to have create an n-gon within 
* a circle. The user will choose both the number of sides of the n-gon,
* as well two points that determine the center and radius of the circle.
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
 
	// choose number of sides
  int n ;
  printf("\nPlease type in the number of sides: ") ;
  scanf("%d", &n) ;

	// select two points
	printf("\nClick two points on the screen: ");
	double p[2], q[2] ;
	double dx, dy;
	G_wait_click(p) ;
	G_fill_circle(p[0],p[1],2) ;
	G_wait_click(q) ;
	G_fill_circle(q[0],q[1],2) ;

	double r = sqrt((q[0]-p[0])*(q[0]-p[0]) + (q[1]-p[1])*(q[1]-p[1]));
	//G_circle(p[0],p[1], r);


	// draw initial point
	double p0[2], s[2], t[2];
	p0[0] = t[0] = p[0] + r;
	p0[1] = t[1] = p[1];
	G_fill_circle(p0[0],p0[1],2);

	// draw each point of the n-gon
	for (int i = 1; i <= n; i++ ){	
		s[0] = cos(i*(2*M_PI)/n) * r + p[0];
		s[1] = sin(i*(2*M_PI)/n) * r + p[1];
		G_line(s[0],s[1],t[0],t[1]);
		G_fill_circle(s[0],s[1],2); 
		t[0] = s[0];
		t[1] = s[1];
	}







	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("ngon.bmp") ;
}
