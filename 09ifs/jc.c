/*
* Jean Choi
* 7/23/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to create my initials JC 
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
  const double n = 12.0;
  const double s = 30.0;
	const int swidth = 600 ;
	const int sheight = 600 ;
	G_init_graphics (swidth,sheight) ; 

	// clear the screen in a given colo‰ˇ
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;
	G_rgb (0.3, 0.5, 0.7) ; //light blue

  int j = 0;
  double r;
  double theta = M_PI/180.0;
  while (j < 100000000) {
    r = drand48() ; //random double s.t. 0 <= r < 1

    if (r < 1/n) {
      scale(9/s,10/s);
    } else if (r < 2/n) {
      scale(4/s, 2/s);
      translate(0, 10/s);
    } else if (r < 3/n) {
      scale(10/s, 4/s);
      rotate(90);
      translate(9/s, 10/s);
    } else if (r < 4/n) {
      scale(10/s, 10/s);
      translate(0, 20/s);
    } else if (r < 5/n) {
      scale(10/s, 4/s);
      rotate(90);
      translate(15/s, 20/s);
    } else if (r < 6/n) {
      scale(10/s, 4/s);
      rotate(90);
      translate(20/s, 20/s);
    } else if (r < 7/n) {
      scale(9/s, 4/s);
      translate(11/s, 16/s);
    } else if (r < 8/n) {
      scale(6/s, 4/s);
      rotate(90);
      translate(20/s, 10/s);
    } else if (r < 9/n) {
      scale(9/s, 10/s);
      translate(11/s, 0);
    } else if (r < 10/n) {
      scale(9/s, 10/s);
      translate(21/s, 20/s);
    } else if (r < 11/n) {
      scale(10/s, 5/s);
      rotate(90);
      translate(26/s, 10/s);
    } else {
      scale(9/s, 10/s);
      translate(21/s, 0);
    }
    G_point(swidth*x[0], sheight*y[0]);
    j++;
  }


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("jc.bmp") ;
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
