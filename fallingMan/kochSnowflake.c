/*
* Jean Choi
*	7/13/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make the Koch Snowflake. 
* The user clicks two points of the screen that indicate 
* the start and end of one edge of the initial triangle,
* as well as how many level to the fractal.
*/

#include "FPToolkit.c"

#ifndef M_PI
#    define M_PI 3.1415926535897932
#endif


	
void koch(int n, double px, double py, double qx, double qy) {
	double rx, ry, sx, sy, tx, ty;
	double c = cos(60 * M_PI/180.0);
	double s = sin(60 * M_PI/180.0);
	if (n == 0) {
		return;
	} else {
		double dx = qx-px;	double dy = qy-py;
			rx = px + 1.0/3 * dx ;
			ry = py + 1.0/3 * dy ;
			sx = px + 2.0/3 * dx ;
			sy = py + 2.0/3 * dy ;
			tx = (sx-rx) * c - (sy-ry) * s + rx ;
			ty = (sx-rx) * s + (sy-ry) * c + ry ;
			G_line(px,py,rx,ry) ;		
			G_line(rx,ry,tx,ty) ;
			G_line(tx,ty,sx,sy) ;
			G_line(sx,sy,qx,qy) ;
			G_rgb(0.8,0.8,0.8) ;
			G_line(rx,ry,sx,sy) ;
			G_rgb(0.3,0.5,0.7) ;
			koch(n-1, px, py, rx, ry) ;
			koch(n-1, rx, ry, tx, ty) ;
			koch(n-1, tx, ty, sx, sy) ;
			koch(n-1, sx, sy, qx, qy) ;
			
	}
}

int main()
{
		int key ; 
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

  int n ;
  printf("\nPlease type in the number of levels: ");
  scanf("%d", &n);

	// user picks two points
	double p[2], q[2], o[2];
	G_wait_click(p);
	//G_fill_circle(p[0],p[1],2) ;
	G_wait_click(q);
	//G_fill_circle(q[0],q[1],2) ;

	// calculate third point of triangle, o[2]
	o[0] = (q[0]-p[0]) * cos(-60 * M_PI/180.0) - (q[1]-p[1]) * sin(-60 * M_PI/180.0) + p[0] ;
	o[1] = (q[0]-p[0]) * sin(-60 * M_PI/180.0) + (q[1]-p[1]) * cos(-60 * M_PI/180.0) + p[1] ;

	// call koch recursive function
	koch(n, p[0], p[1], q[0], q[1]);
	koch(n, q[0], q[1], o[0], o[1]);
	koch(n, o[0], o[1], p[0], p[1]);


	//===============================================
	
  
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("kochSnowflake.bmp") ;
}
