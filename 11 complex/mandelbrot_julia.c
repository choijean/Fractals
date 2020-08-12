/*
* Jean Choi
*	8/11/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
*/

#include "FPToolkit.c"

#include <stdio.h>
#include <math.h>
#include <complex.h>

const int swidth = 600;
const int sheight = 300;

//mandelbrot variables
int reps = 50;
double cx,cy ;
int xp, yp;
complex c, z;
double sr, sg, sb ;
double er, eg, eb ;
double r, g, b ;

//point coordinates
double p[2];

void mandelbrot() {
  sr = 0.0 ;  sg = 0.0 ;  sb = 0.0 ;
  er = 1.0 ;  sg = 1.0 ;  sb = 1.0 ;

  // iterate through each pixel of window
  for (int x = 0; x < swidth/2; x++){
    for (int y = 0; y < sheight; y++) {

      // map to coordinating complex number
      cx = 2*((x-(swidth/4.0))/(swidth/4.0)) ;
      cy = 2*((y-(sheight/2.0))/(sheight/2.0)) ;
      c = cx + cy*I ;
      z = 0;
      int k ;
      for (k = 0 ; k < reps ; k++) {
        z = z*z + c ;
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

void julia() {
  sr = 0.0 ;  sg = 0.0 ;  sb = 0.0 ;
  er = 1.0 ;  sg = 1.0 ;  sb = 1.0 ;

  // iterate through each pixel of window
  for (int x = 0; x < swidth/2; x++){
    for (int y = 0; y < sheight; y++) {

      // map to coordinating complex number
      cx = 2*((p[0]-(swidth/4.0))/(swidth/4.0)) ;
      cy = 2*((p[1]-(sheight/2.0))/(sheight/2.0)) ;
      
      c = cx + cy*I ;
      z = 0;
      int k ;
      for (k = 0 ; k < reps ; k++) {
        z = z*z + c ;
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
      G_point(x+(swidth/2),y);
    }
  }
}


int main()
{
  // repl.it display
	G_choose_repl_display() ;
	
	// set dimensions
	G_init_graphics (swidth,sheight) ;
  G_rgb(1,1,1);
  G_clear();

  mandelbrot();

  while(1) {
	G_wait_click(p);
  G_rgb(0,0,0);
	G_fill_circle(p[0],p[1],2);

  julia();
  }

  //===================================
	int key ;   
	key =  G_wait_key() ; 

  // save file
	G_save_to_bmp_file("mandelbrot_julia.bmp") ;

}
