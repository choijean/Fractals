/*
* Jean Choi
*7/23/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to draw Sierpinski's Pyramid
* using Iterated Function Systems
*/

#include "FPToolkit.c"

double x[1] = {0} ;
double y[1] = {0} ;
int n = 1 ;


void scale (double xscale, double yscale);
void translate (double dx, double dy);
void rotate (double theta) ;


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

  int j = 0;
  double r;
  while (j < 1000000) {
    r = drand48() ; //random double s.t. 0 <= r < 1

    if (r < 1/9.0) {
      scale(0.5,0.5);
    } else if (r < 2/9.0) {
      scale(0.5,0.5);
      translate(0.5, 0);
    } else if (r < 3/9.0) {
      scale(0.5,0.5);
      translate(0.25, sqrt(pow(0.5,2)-pow(0.25,2)));
    } else if (r < 4/9.0) {
      scale(1/3.0,1/3.0);
      rotate(45);
    } else if (r < 5/9.0) {
    } else if (r < 6/9.0) {
    } else if (r < 7/9.0) {
    } else if (r < 8/9.0) {
    } else  {
    }
    G_point(swidth*x[0], sheight*y[0]);
    j++;
  }


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("sierpinskiTriIFS.bmp") ;
}


void translate (double dx, double dy) {
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}

void scale (double xscale, double yscale) {

	for (int i = 0; i < n; i++) {
		x[i] = xscale * x[i] ;
		y[i] = yscale * y[i] ;
	}
}

void rotate (double theta) {
	double temp ;
	double radians = theta*M_PI/180.0 ;
	for (int i = 0; i < n; i++) {
		temp = x[i]*cos(radians) - y[i]*sin(radians) ;
		y[i] = x[i]*sin(radians) + y[i]*cos(radians) ;
		x[i] = temp ;
	}
}
