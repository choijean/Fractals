
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
  printf("\nPlease type in the number of lines: \n");
  scanf("%d", &n);
  
  // clear the screen in a given color
  G_rgb (0.7, 0.7, 0.7) ; // dark gray
  G_clear () ;

	// calculate the gap
	int xgap, ygap;
	xgap = swidth/(n-1);
	ygap = sheight/(n-1);
 
	// draw lines
	for(int i = 0; i < n; i++){
 		G_rgb (0.0+1.0*i/n, 0.4, 0.4) ; // green
		int x1, y1, x2, y2;
		x1 = 0;
		y1 = swidth - 1 - (ygap * i);
		x2 = xgap * i;
		y2 = 0;	
	
  	G_line (x1, y1, x2, y2) ;
	}

  int key ;   
  key =  G_wait_key() ; // pause so user can see results

	// save file
  G_save_to_bmp_file("parabola.bmp") ;
}



