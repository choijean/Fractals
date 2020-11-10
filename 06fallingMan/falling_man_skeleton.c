#include "FPToolkit.c"

#ifndef M_PI
#    define M_PI 3.1415926535897932
#endif

// points for stick man
// appropriate for a 600x600 window
double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
int n = 13 ;


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}

void scale (double scale) {

	for (int i = 0; i < n; i++) {
		x[i] = scale * x[i] ;
		y[i] = scale * y[i] ;
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



int main() 
{
  int q ;

  G_choose_repl_display() ;
  G_init_graphics(600, 600) ;

  G_rgb(0,0,0) ;
  G_clear() ;

  G_rgb(0,0,1) ;
  G_fill_polygon(x,y,n) ;
  q = G_wait_key() ; 	

  //translate(150, 0) ;

	// translate to the right at 1/3 size
	// translate(-300, -300) ;
	// scale (1.0/3.0);
	// translate (450, 300) ;

	double theta = 0.0;
	double scaleFactor = 1.0;
	int i = 1;
	while(q)	{
  G_rgb(0,0,0) ;
  G_clear() ;

	translate(-300, -300) ;
	scale (scaleFactor);
	rotate (theta);
	translate (300, 300) ;

  G_rgb(0,0,1) ;
  G_fill_polygon(x,y,n) ;

	scaleFactor -= 0.001;
	theta += (2 * M_PI)/200;

	q = G_wait_key();
	}


  G_rgb(1,0,1) ; 
  G_fill_polygon(x,y,n) ;
  q = G_wait_key() ; 

}


