/*
* Jean Choi
*	8/13/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
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

double x_cen = -0.75;
double y_cen  = 0.1;
double rad = 2.0;
double x_0, y_0, x_1, y_1, x_2, y_2;

double p[2], q[2] ;

void mandelbrot_2() {
  sr = 0.0 ;  sg = 1.0 ;  sb = 1.0 ;
  er = 1.0 ;  eg = 0.0 ;  eb = 0.0 ;

  int key = 'g';
  while (1) {
    // iterate through each pixel of window
    for (int x = 0; x < ssize; x++){
      for (int y = 0; y < ssize; y++) {
  
        // map to coordinating complex number
        cx = rad*((x-(ssize/2.0))/(ssize/2.0)) + x_cen;
        cy = rad*((y-(ssize/2.0))/(ssize/2.0)) + y_cen;
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
  
    key = G_wait_key();
    if(key == 's') {
      break;
    } 
    if(key == 'n') {
      reps *= 2;
    }
    if(key == 'z') {
      G_wait_click(p);
      G_wait_click(q);
    
      x_0 = p[0];
      y_0 = p[1];
      x_1 = rad*((x_0-(ssize/2.0))/(ssize/2.0)) + x_cen;
      y_1 = rad*((y_0-(ssize/2.0))/(ssize/2.0)) + y_cen;
    
      x_0 = q[0];
      y_0 = q[1];
      x_2 = rad*((x_0-(ssize/2.0))/(ssize/2.0)) + x_cen;
      y_2 = rad*((y_0-(ssize/2.0))/(ssize/2.0)) + y_cen;
    
      x_cen = x_1; 
      y_cen = y_1;
      rad = sqrt(pow((x_2-x_1),2) + pow((y_2-y_1),2));
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

  mandelbrot_2();

  //===================================
	int key ;   
	key =  G_wait_key() ; 

  // save file
	G_save_to_bmp_file("mandelbrot_zoom.bmp") ;

}
