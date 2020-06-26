/*
* Jean Choi
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
  printf("\nPlease type in the number of circles: \n");
  scanf("%d", &n);
	
	// clear the screen in a given color
	G_rgb (0.3, 0.3, 0.3) ; // dark gray
	G_clear () ;

	// two points the user chooses and draw line between them
	G_rgb (0,1,0); //green
	double p[2], q[2] ;
	G_wait_click(p);
	G_fill_circle(p[0],p[1],2);
	G_wait_click(q);
	G_fill_circle(q[0],q[1],2) ;
	G_line(p[0],p[1], q[0],q[1]) ;

	double distance = sqrt((p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]));
	double gap = distance/(n-1);

	double r[2];
	if (p[0] < q[0]) {
		if(p[1] < q[1]) {
			for (int i = 0; i < n-1; i++) {
				r[0] = p[0] + 
			}
		} else {

		}
	} else {
		if(p[1] < q[1]) {

		} else {

		}
	}

	

	;

	

	


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	G_save_to_bmp_file("demo.bmp") ;
}



