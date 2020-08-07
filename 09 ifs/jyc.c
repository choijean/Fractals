/*
* Jean Choi
* 7/23/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to create my initials JYC 
* using Iterated Function Systems
*/

#include "FPToolkit.c"

double x[1] = {0} ;
double y[1] = {0} ;
int n = 1 ;


void scale (double xscale, double yscale);
void translate (double dx, double dy);
void rotate (double theta) ;
void background();


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
  background();

  G_rgb(0,0,0);

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
	G_save_to_bmp_file("jyc.bmp") ;
}


void background() {
  double x0,y0 , x1,y1, dx, dy ;
  double sf, sf2;

  double r,g,b;
  double rr,gg,bb;
  double r1,g1,b1 ;
  double r2,g2,b2 ;
  double r3,g3,b3 ;
  double r4,g4,b4 ;
  y0 = 0 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  r1 = 1.0 ;  g1 = 0.0 ;  b1 = 0.0 ;
  r2 = 1.0 ;  g2 = 1.0 ;  b2 = 0.0 ;
  r3 = 0.0 ;  g3 = 1.0 ;  b3 = 0.0 ;
  r4 = 0.0 ;  g4 = 1.0 ;  b4 = 1.0 ;
    
  for(int k=y0;k<=y1;k++) {
    sf = (k-y0)/dy ;
    r = r1 + sf*(r2-r1) ;
    g = g1 + sf*(g2-g1)  ;
    b = b1 + sf*(b2-b1) ;
    for(int j=y0; j<=y1; j++){
      sf2 = (j-y0)/dy;
      rr = r + sf2*(r4-r3);
      gg = g + sf2*(g4-g3);
      bb = b + sf2*(b4-b3);
      G_rgb(rr, gg, bb) ;
      G_point(j,k) ;
    }
  }

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
