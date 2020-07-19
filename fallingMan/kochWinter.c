/*
* Jean Choi
*	7/13/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make the Koch Snowflake 
* in a winter wonderland from the indoor perspective.
* The user clicks two points of the screen that indicate 
* the start and end of one edge of the initial triangle,
* as well as telling the program how many levels there should be.
*/

#include "FPToolkit.c"

double c = cos(60 * M_PI/180.0);
double s = sin(60 * M_PI/180.0);
double c1 = cos(-60 * M_PI/180.0);
double s1 = sin(-60 * M_PI/180.0);


void kochSnowflake(int depth, double *p, double *q);
void koch(int n, double px, double py, double qx, double qy);
void pytree(double x0, double y0, double x1, double y1, int n, double scale, double height);
void drawWindow();
void background();
void signature(double x, double y, double len);
void drawJ(double x, double y, double len);
void drawE(double x, double y, double len);
void drawA(double x, double y, double len);
void drawN(double x, double y, double len);
void drawC(double x, double y, double len);
void drawH(double x, double y, double len);
void drawO(double x, double y, double len);
void drawI(double x, double y, double len);

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
	G_rgb (0.3, 0.5, 0.7) ;
  G_clear () ;
  background(); 

  // TREES
  pytree(350, 40, 430, 40, 15, 0.66, 1);

  // SNOWFLAKE

	// user picks two points and enters depth
	double p[2], q[2];
  int depth = 4;
  for (int i = 0; i < 10; i++) {
    G_wait_click(p);
    G_wait_click(q);
    kochSnowflake(depth, p, q);
  }

  // draw window
  drawWindow();

  // draw signature
  signature(470,10,3);
  

	//===============================================
	
  
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("kochWinter.bmp") ;
}

void kochSnowflake(int depth, double *p, double *q){
  double o[2];
  // calculate third point of triangle, o[2]
	o[0] = (q[0]-p[0]) * c1 - (q[1]-p[1]) * s1 + p[0] ;
	o[1] = (q[0]-p[0]) * s1 + (q[1]-p[1]) * c1 + p[1] ;

	// call koch recursive function on all three lines
	koch(depth, p[0], p[1], q[0], q[1]);
	koch(depth, q[0], q[1], o[0], o[1]);
	koch(depth, o[0], o[1], p[0], p[1]);
}

// recursive function to draw a koch curve above and below two given points
void koch(int n, double px, double py, double qx, double qy) {	
  G_rgb (0.8, 0.8, 0.8) ;
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

    koch(n-1, px, py, rx, ry) ;
    koch(n-1, rx, ry, tx, ty) ;
    koch(n-1, rx, ry, ux, uy) ; // for extra spicy snowflake
    koch(n-1, tx, ty, sx, sy) ;
    koch(n-1, ux, uy, sx, sy) ; // for extra spicy snowflake
    koch(n-1, sx, sy, qx, qy) ;

    G_rgb(0.8,0.8,0.8) ;
    if(n==1){
      G_line(px,py,rx,ry) ;	
      G_line(rx,ry,tx,ty) ;
      G_line(tx,ty,sx,sy) ;
      G_line(sx,sy,qx,qy) ;
    }
	}
}

// recursive function that draws a pythagoras tree
void pytree(double x0, double y0, double x1, double y1, int n, double scale, double height){

	// determine second set of points (x2, y2), (x3, y3)
	double x2, y2, x3, y3, x4, y4, xm, ym, g;
	x2 = x1 - (y1 - y0);						y2 = height * y1 + (x1 - x0);
	x3 = x0 - (y1 - y0);						y3 = height * y0 + (x1 - x0);

	// determine 3rd point (x4, y4) to make third point of right triangle,
	// using (x2, y2), (x3, y3) 
	g = sqrt(scale*(1-scale)) ;
	xm = x3 + scale * (x2 - x3) ;
	ym = y3 + scale * (y2 - y3) ;

	x4 = xm - g * (y2 - y3) ;
	y4 = ym + g * (x2 - x3) ;

  double boxX[4], boxY[4];
  boxX[0] = x0;     boxY[0] = y0;
  boxX[1] = x1;     boxY[1] = y1;
  boxX[2] = x2;     boxY[2] = y2;
  boxX[3] = x3;     boxY[3] = y3;
  double triangleX[3], triangleY[3];
  triangleX[0] = x3;    triangleY[0] = y3;
  triangleX[1] = x2;    triangleY[1] = y2;
  triangleX[2] = x4;    triangleY[2] = y4;

  // draw box
  G_rgb (0.163, 0.038, 0) ; //brown
  G_fill_polygon(boxX, boxY, 4);
  // draw triangle
  if(n == 1) 
    G_rgb(1,1,1) ;
  G_fill_polygon(triangleX, triangleY, 3);

	if(n <= 0){
		return;
	}
	else {
		pytree(x3, y3, x4, y4, n-1, scale, height);
		pytree(x4, y4, x2, y2, n-1, scale, height);
	};
}

// draws a window that changes colors
// based on dr. ely's color-fading.c
void drawWindow(){
  double x0,y0 , x1,y1, dx, dy ;
  double sf ;

  double r,g,b , sr,sg,sb , er,eg,eb ;
  y0 = 0 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  sr = 0.6 ;   sg = 0.167 ;    sb = 0.167 ;
  er = 0.2 ;   eg = 0.167 ;    eb = 0.167 ; 

    
  for(int k=y0;k<=y1;k++) {

    sf = (k-y0)/dy ;
    //sf = pow(sf,3) ;
    r = sr + sf*(er-sr) ;  g = sg + sf*(eg-sg) ;  b = sb + sf*(eb-sb) ;
    G_rgb(r,g,b) ;
    if ((0<=k && k<=2) || (598<=k && k<=600)){
      G_rgb(0,0,0) ;
      G_line(0,k,600,k);
    } else if ((38<=k && k<=40) || (280<=k && k<=282) || (318<=k && k<=320) || (560<=k && k<=562)) {
      G_line(0,k,600,k);
      G_rgb(0,0,0);
      G_line(0,k,2,k);
      G_line(38,k,282,k);
      G_line(318,k,562,k);
      G_line(598,k,600,k);
    } else if ((2 < k && k < 38) || (282 < k && k < 318) || (562 < k && k < 598)){
      G_line(0,k,600,k);
      G_rgb(0,0,0);
      G_line(0,k,2,k);
      G_line(598,k,600,k);
    } else {
    G_line(0,k,38,k) ;
    G_line(280,k,320,k) ;
    G_line(560,k,600,k) ;
    G_rgb(0,0,0);
    G_line(0,k,2,k);
    G_line(38,k,40,k);
    G_line(280,k,282,k);
    G_line(318,k,320,k);
    G_line(560,k,562,k);
    G_line(598,k,600,k);
    }
  }
}

// draws the background 
// based off of dr. ely's color-fading.c
void background(){
  double x0,y0 , x1,y1, dx, dy ;
  double sf ;

  double r,g,b , sr,sg,sb , er,eg,eb ;
  y0 = 350 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  sr = 0.117 ;  sg = 0.117 ;  sb = 0.263 ;
  er = 0.581 ;  eg = 0.180 ;  eb = 0 ; 

  for(int k=0;k<=y0;k++){
    G_rgb(sr,sg,sb) ;
    G_line(0,k,600,k) ;
  }

    
  for(int k=y0;k<=y1;k++) {
    sf = (k-y0)/dy ;
    //sf = pow(sf,3) ;
    r = sr + sf*(er-sr) ;  g = sg + sf*(eg-sg) ;  b = sb + sf*(eb-sb) ;
    G_rgb(r,g,b) ;
    G_line(0,k,600,k) ;
  }
}

// draws my signature
// (x,y) is the location of the lower left point of the 'J'
// len determines the size of each letter
void signature(double x, double y, double len) {
  double dx = len*4;
  G_rgb(1,1,1);
  drawJ(x,y,len);
  drawE(x+dx,y,len);
  drawA(x+dx*2,y,len);
  drawN(x+dx*3,y,len);
  drawC(x+dx*4.5,y,len);
  drawH(x+dx*5.5,y,len);
  drawO(x+dx*6.5,y,len);
  drawI(x+dx*7.5,y,len);
}

void drawJ(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 3;
  for(double i = y; i <= dy+y; i++){
    if(y <= i && i <= y+(0.142*dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.142*dy) < i && i <= y+(0.286*dy)) {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else if ((y+(0.286*dy) < i && i <= y+(0.714*dy)) ||
      (y+(0.857*dy) < i && i <= y+dy)){
      G_line(x+(0.66*dx), i, x+dx, i);
    } else {}    
  }
}

void drawE(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
  for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.4*dy) < i && i <= y+(0.6*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.2*dy) < i && i <= y+(0.4*dy)) {
      G_line(x, i, x+(0.33*dx), i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawA(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.4*dy) < i && i <= y+(0.6*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else if(y+(0.2*dy) < i && i <= y+(0.4*dy)) {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else {
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawN(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y+(0.8*dy) < i && i <= y+dy)) {
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawC(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) || 
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
    }
  }
}

void drawH(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if(y <= i && i <= y+(0.571*dy)){
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    } else if (y+(0.571*dy) < i && i <= y+(0.714*dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
    }
  }
}

void drawO(double x, double y, double len) {
  double dy = len * 5;
  double dx = len * 3;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.2*dy)) ||
    (y+(0.8*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
      G_line(x, i, x+(0.33*dx), i);
      G_line(x+(0.66*dx), i, x+dx, i);
    }
  }
}

void drawI(double x, double y, double len) {
  double dy = len * 7;
  double dx = len * 1;
   for(double i = y; i <= dy+y; i++){
    if((y <= i && i <= y+(0.714*dy)) ||
    (y+(0.857*dy) < i && i <= y+dy)){
      G_line(x, i, x+dx, i);
    } else {
    }
  }
}
 
