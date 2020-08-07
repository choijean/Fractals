/*
* Jean Choi
*	8/6/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
*/

#include "FPToolkit.c"

#include <stdio.h>
#include <math.h>
#include <complex.h>

const int ssize = 600;


// void translate (double dx, double dy)
// {
//   int i ;

//   i = 0 ;
//   while (i < n) {
//     x[i] = x[i] + dx ;
//     y[i] = y[i] + dy ;
//     i = i + 1 ;
//   }
// }


int main()
{
  // repl.it display
	G_choose_repl_display() ;
	
	// set dimensions
	G_init_graphics (ssize,ssize) ;

  int reps = 30;
  double cx,cy ;
  int xp, yp;
  complex c ;

  printf("how many reps ? ") ;
  scanf("%d",&reps) ;
  
  for (int x = 0; x < ssize; x++){
    for (int y = 0; y < ssize; y++) {
      cx = 2*((x-300)/300.0) ;
      cy = 2*((y-300)/300.0) ;
      c = cx + cy*I ;
      complex z = 0;
      for (int k = 0 ; k < reps ; k++) {
        z = z*z + c ;
      }    
      cabs(z) > 100 ? G_rgb(0.0,0.0,0.0) : G_rgb(0.0,0.0,1.0) ;
      G_point(x,y);
    }
  }


  //===================================
	int key ;   
	key =  G_wait_key() ; 

  // save file
	G_save_to_bmp_file("mandelbrot.bmp") ;

}
