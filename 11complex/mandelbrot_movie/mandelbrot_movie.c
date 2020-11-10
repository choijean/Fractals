/*
* Jean Choi
*	8/6/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*/

#include "FPToolkit.c"

#include <stdio.h>
#include <math.h>
#include <complex.h>

const int ssize = 600;
char fname[200];

int reps = 200;
double cx,cy ;
int xp, yp;
complex c, z;

double sr, sg, sb ;
double er, eg, eb ;
double r, g, b ;

void mandelbrot(double power) {
  sr = 0.0 ;  sg = 0.3 ;  sb = 0.3 ;
  er = 1.0 ;  eg = 0.3 ;  eb = 0.3 ;

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

  int count = 0;
  for(double i = 1.0; i < 10.0; i=i+0.1){
    mandelbrot(i);
    sprintf(fname, "mandelbrot_movie%04d.bmp", count) ;
    G_save_to_bmp_file(fname) ;
    count++ ;
  }
}