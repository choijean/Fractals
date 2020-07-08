/*
* Jean Choi
*	7/7/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make a circle centered at P0, 
* only using G_point()
*/

#include "FPToolkit.c"

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

  int n;
  printf("\nPlease type in the number: ");
  scanf("%d", &n);

	printf("\nClick two points on the screen: ");
	double p[2], q[2] ;
	double dx, dy;
	G_wait_click(p) ;
	G_wait_click(q) ;

	





	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("circle.bmp") ;
}
