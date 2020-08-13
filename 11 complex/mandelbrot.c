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

int reps = 200;
double cx,cy ;
int xp, yp;
complex c, z;

double sr, sg, sb ;
double er, eg, eb ;
double r, g, b ;

void mandelbrot_1() {

  printf("how many reps ? ") ;
  scanf("%d",&reps) ;

  // iterate through each pixel of window
  for (int x = 0; x < ssize; x++){
    for (int y = 0; y < ssize; y++) {

      // map to coordinating complex number
      cx = 2*((x-300)/300.0) ;
      cy = 2*((y-300)/300.0) ;
      c = cx + cy*I ;
      z = 0;
      for (int k = 0 ; k < reps ; k++) {
        z = z*z + c ;
      }    
      cabs(z) > 100 ? G_rgb(0.0,0.0,0.0) : G_rgb(0.0,0.0,1.0) ;
      G_point(x,y);
    }
  }
}

void mandelbrot_2() {
  sr = 0.0 ;  sg = 0.0 ;  sb = 0.0 ;
  er = 1.0 ;  eg = 1.0 ;  eb = 1.0 ;

  // iterate through each pixel of window
  for (int x = 0; x < ssize; x++){
    for (int y = 0; y < ssize; y++) {

      // map to coordinating complex number
      cx = 2*((x-(ssize/2.0))/(ssize/2.0)) ;
      cy = 2*((y-(ssize/2.0))/(ssize/2.0)) ;
      c = cx + cy*I ;
      z = 0;
      int k ;
      for (k = 0 ; k < reps ; k++) {
        z = cpow(z, 2) + c ;
        if (cabs(z) > 100) { // diverged to inf or -inf
          break ; 
        }    
      }
      double sf = 1.0*k/reps;
      sf = pow(sf,0.3) ;
      r = sr + sf*(er-sr) ;  
      g = sg + sf*(eg-sg) ;  
      b = sb + sf*(eb-sb) ;
      G_rgb(r,g,b) ;
      G_point(x,y);
    }
  }
}

void mandelbrot_3(double power) {
  sr = 0.0 ;  sg = 0.0 ;  sb = 0.0 ;
  er = 1.0 ;  eg = 1.0 ;  eb = 1.0 ;

  // iterate through each pixel of window
  for (int x = 0; x < ssize; x++){
    for (int y = 0; y < ssize; y++) {

      // map to coordinating complex number
      cx = 2*((x-(ssize/2.0))/(ssize/2.0)) ;
      cy = 2*((y-(ssize/2.0))/(ssize/2.0)) ;
      c = cx + cy*I ;
      z = 0;
      int k ;
      for (k = 0 ; k < reps ; k++) {
        z = cpow(z, power) + c ;
        if (cabs(z) > 100) { // diverged to inf or -inf
          break ; 
        }    
      }
      double sf = 1.0*k/reps;
      sf = pow(sf,0.3) ;
      r = sr + sf*(er-sr) ;  
      g = sg + sf*(eg-sg) ;  
      b = sb + sf*(eb-sb) ;
      G_rgb(r,g,b) ;
      G_point(x,y);
    }
  }
}


int main()
{
  // repl.it display
	G_choose_repl_display() ;
	
	// set dimensions
	G_init_graphics (ssize,ssize) ;
  G_rgb(1,1,1);
  G_clear();

  // mandelbrot_1();
  // mandelbrot_2();
  for(double i = 2.0; i < 8.0; i=i+0.1){
    mandelbrot_3(i);
    int wait = G_wait_key();
  }

  //===================================
	int key ;   
	key =  G_wait_key() ; 

  // save file
	G_save_to_bmp_file("mandelbrot2.bmp") ;

}
