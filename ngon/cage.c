/*
* Jean Choi
*	7/8/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this project is to create an animation of a twisting cage.
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
	double p[2], q[2], r[2], s[2];
	p[0] = 300 ;				p[1] = 75 ;
	q[0] = 375 ;				q[1] = 75 ;
	r[0] = 300 ;				r[1] = 525 ;
	s[0] = 375 ;				s[1] = 525 ;

	// create arrays to hold points 0 to n-1
	double fx[n], fy[n], gx[n], gy[n];

	// calculate radius
	double radius = sqrt((q[0]-p[0])*(q[0]-p[0]) + (q[1]-p[1])*(q[1]-p[1]));


	for (int i = 0 ; i < n ; i++) {
		G_rgb (0.8, 0.8, 0.8) ; // light gray
		G_clear () ;
		G_rgb (0.3, 0.5, 0.7) ; //light blue;

		for (int j = 0; j < n; j++ ){	
	
			fx[j] = 2 * cos(j*(2*M_PI)/n) * radius + p[0];
			fy[j] = .75 * sin(j*(2*M_PI)/n) * radius + p[1];
			gx[(j+i)%n] = 2 * cos(j*(2*M_PI)/n) * radius + r[0];
			gy[(j+i)%n] = .75 * sin(j*(2*M_PI)/n) * radius + r[1];

			G_fill_circle(fx[j],fy[j],2); 
			G_fill_circle(gx[j],gy[j],2);
		}

		// plot points ellipses
		double a[2], b[2];
		for(double i = 0; i <= (2*M_PI); i += .001) {
			b[0] = 2 * cos(i*(2*M_PI)) * radius + p[0] ;
			b[1] = .75 * sin(i*(2*M_PI)) * radius + p[1] ;
			a[0] = 2 * cos(i*(2*M_PI)) * radius + r[0] ;
			a[1] = .75 * sin(i*(2*M_PI)) * radius + r[1] ;
			G_point(a[0], a[1]) ;
			G_point(b[0], b[1]) ;
		}

		for (int j = 0; j < n; j++) {
			G_line(fx[j], fy[j], gx[j], gy[j]);
		}
		int key ;   
		key =  G_wait_key() ; // pause so user can see results

	}




	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("circle.bmp") ;
}

