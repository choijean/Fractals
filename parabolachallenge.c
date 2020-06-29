
#include  "FPToolkit.c"


int main()
{
  // must do this before G_init_graphics() if using repl.it
  G_choose_repl_display() ;

  // size of display
	const int swidth = 600;
	const int sheight = 600;
  G_init_graphics(swidth, sheight);

  // number of lines
  int n;
  printf("\nPlease type in the number of lines: ");
  scanf("%d", &n);
  
  // clear the screen in a given color
  G_rgb (0.3, 0.3, 0.3) ; // dark gray
  G_clear () ;

	// center coordinates
	int cx = swidth/2;
	int cy = sheight/2;

	// calculate the gap
  int	xgap = cx/(n-1);
	int ygap = cy/(n-1);
 
	/*
	* CHALLENGE
	*/

	const int numquadrants = 4;
	int quadrant = 1;

	for(int i = 0; i < n; i++){
		G_rgb (0.0+1.0*i/n, 0.4, 0.4) ; // green

		// quadrants 1, 2, 3, 4
		G_line (cx, swidth - 1 - (ygap*i), cx + xgap * i, cy) ;
		G_line (cx, swidth - 1 - (ygap * i), cx - xgap * i, cy);
		G_line (cx, ygap * i, cx - xgap * i, cy);
		G_line (cx, ygap * i, cx + xgap * i, cy);
	}


  int key ;   
  key =  G_wait_key() ; // pause so user can see results

  //   G_save_image_to_file("demo.xwd") ;
  G_save_to_bmp_file("demo.bmp") ;
}



