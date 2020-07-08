/*
* Jean Choi
*	***DATE
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* ***GOAL
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





	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("***file.bmp") ;
}
