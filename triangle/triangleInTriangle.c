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
  printf("\nPlease type in the number of levels: ");
  scanf("%d", &n);
	
	// clear the screen in a given color
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;

	
	

	


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("../images/triangleInTriangle.bmp") ;
}



