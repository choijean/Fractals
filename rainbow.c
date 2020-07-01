
#include  "FPToolkit.c"

//	1 0 1
//			-
//	1	0	0
//		+		
//	1 1 0
//	-	
//  0 1 0
//			+
//	0 1 1
//		-
//	0 0 1
//	+

int main()
{
	// must do this before G_init_graphics() if using repl.it
  G_choose_repl_display() ;

	// must do this before you do 'almost' any other graphical tasks 
  const int swidth = 400 ; 
	const int sheight = 600 ;
  G_init_graphics (swidth, sheight) ;  // interactive graphics

   
  // clear the screen in a given color
  G_rgb (0.3, 0.3, 0.3) ; // dark gray
  G_clear () ;

	int r, g, b;
	int x = 50; int y = 50; //test dot coordinates
	char c = 'b'; // current color being changed
	int n = 12; // number of steps

	int increasing = 0; // 1 = increasing, 0 = decreasing
	double increment = increasing == 1 ? 6/(double)n : -6/(double)n;

	//start color at purple
	r = 1; g = 0; b = 1;

	for( int i = 0; i < 12; i++){
		G_rgb (r,g,b) ;
		G_fill_circle(x, y, 5);
		x += 10, y += 10;
	}


	
	
	
	
	
	int key ;   
  key =  G_wait_key() ; // pause so user can see results

	// save file
  G_save_to_bmp_file("rainbow.bmp") ;
}