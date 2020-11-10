/*
* Jean Choi
*7/23/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to draw the Barnsley fern
* using Iterated Function Systems
*/

#include "FPToolkit.c"

double x[2] = {0,0} ;
double y[2] = {0,0} ;
int n = 2 ;


void scale (double xxscale, double xyscale, double yxscale, double yyscale);
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
  while (j < 10000000) {
    r = drand48() ; //random double s.t. 0 <= r < 1

    if (r < 0.01) {
      scale(0,0,0,0.16);
    } else if (r < 0.86) {
      scale(0.85,0.04,-0.04,0.85);
      translate(0,1.6);
    } else if (r < 0.93) {
      scale(0.2,-0.26,0.23,+0.22);
      translate(0,1.6);
    } else {
      scale(-.15,0.28,0.26,+0.24);
      translate(0,0.44);
    }
    x[0] = ((x[0]+3)*swidth)/6;
    y[0] = sheight - ((y[0]+2)*sheight);
    //translate(1,1);
    G_point(x[0], y[0]);
    //printf("x: %lf, y: %lf\n", x[0], y[0]);
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

void scale (double xxscale, double xyscale, double yxscale, double yyscale) {

	for (int i = 0; i < n; i++) {
		x[i] = xxscale * x[i] + xyscale * y[i];
		y[i] = yxscale * x[i] + yyscale * y[i];
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
