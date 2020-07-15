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


	double c = cos(60 * M_PI/180.0);
	double s = sin(60 * M_PI/180.0);
	double c1 = cos(-60 * M_PI/180.0);
	double s1 = sin(-60 * M_PI/180.0);
	

void koch(int n, double px, double py, double qx, double qy) {
	double rx, ry, sx, sy, tx, ty, ux, uy;
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
			ux = (sx-rx) * c1 - (sy-ry) * s1 + rx ; // for extra spicy snowflake
			uy = (sx-rx) * s1 + (sy-ry) * c1 + ry ; // for extra spicy snowflake
			G_line(px,py,rx,ry) ;		
			G_line(rx,ry,tx,ty) ;
			G_line(tx,ty,sx,sy) ;
			G_line(sx,sy,qx,qy) ;
			G_rgb(0.8,0.8,0.8) ;
			G_line(rx,ry,sx,sy) ;
			G_rgb(0.3,0.5,0.7) ;
			koch(n-1, px, py, rx, ry) ;
			koch(n-1, rx, ry, tx, ty) ;
			koch(n-1, rx, ry, ux, uy) ; // for extra spicy snowflake
			koch(n-1, tx, ty, sx, sy) ;
			koch(n-1, ux, uy, sx, sy) ; // for extra spicy snowflake
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
	double p[2], q[2], o[2], m[2];
	G_wait_click(p);
	//G_fill_circle(p[0],p[1],2) ;
	G_wait_click(q);
	//G_fill_circle(q[0],q[1],2) ;

	// calculate third point of triangle, o[2]
	o[0] = (q[0]-p[0]) * c1 - (q[1]-p[1]) * s1 + p[0] ;
	o[1] = (q[0]-p[0]) * s1 + (q[1]-p[1]) * c1 + p[1] ;
	// m[0] = (q[0]-p[0]) * c - (q[1]-p[1]) * s + p[0] ;
	// m[1] = (q[0]-p[0]) * s + (q[1]-p[1]) * c + p[1] ;

	// call koch recursive function
	koch(n, p[0], p[1], q[0], q[1]);
	koch(n, q[0], q[1], o[0], o[1]);
	// koch(n, q[0], q[1], m[0], m[1]);
	koch(n, o[0], o[1], p[0], p[1]);
	// koch(n, m[0], m[1], p[0], p[1]);


	//===============================================
	
  
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("kochSnowflake2.bmp") ;
}
