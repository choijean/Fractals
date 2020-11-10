#include "FPToolkit.c"

/*

       Y+
       |
       |    * (y,z)
       |  
<------+--------Z+
   D   |
       |
       |


y'    y
- =  ---
D    D+z

H = D*tan(halfangle) ;

with the x-axis perpendicular to this plane.

*/

#define M 700000
double Wsize = 600  ; // window size ... choose 600 for repl
double X[M],Y[M],Z[M] ;
double Xplot[M],Yplot[M] ;
int N = 0 ;


int translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}



int rotate_x(double degrees)
// Y[] and Z[] will change but X[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*Y[i] - s*Z[i] ;
    Z[i] =  s*Y[i] + c*Z[i] ;
    Y[i] = temp ;
  }
}




int rotate_y(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
  }
}



int rotate_z(double degrees)
// X[] and Y[] will change but Z[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] - s*Y[i] ;
    Y[i] =  s*X[i] + c*Y[i] ;
    X[i] = temp ;
  }
}



int project(double observer_distance, double halfangle_degrees)
{
  int i ;
  double D,tanhalf,Whalf ;

  D = observer_distance ;
  tanhalf = tan( halfangle_degrees*M_PI/180 ) ;
  Whalf = Wsize/2 ;
  
  for (i = 0 ; i < N ; i++) {
    Xplot[i] = (X[i]/(D + Z[i]))  * (Whalf/tanhalf) + Whalf ;
    Yplot[i] = (Y[i]/(D + Z[i]))  * (Whalf/tanhalf) + Whalf ;
  }
  
}


int draw()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }

}



int print_object()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf, %lf)   (%lf, %lf, %lf)\n", 
	   X[i],Y[i],Z[i],  X[i+1],Y[i+1],Z[i+1]) ;
  }

  printf("===============================\n") ;
  
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf)   (%lf, %lf)\n", 
	   Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }  
}



int save_line(double xs, double ys, double zs,
	      double xe, double ye, double ze)
{
  // about to add items at slots N and N+1 :
  if (N+1 >= M) {
    printf("full\n") ;
    return 0 ;
  }
  
  X[N] = xs ; Y[N] = ys ; Z[N] = zs ; N++ ;
  X[N] = xe ; Y[N] = ye ; Z[N] = ze ; N++ ;

  return 1 ;
}




int build_pyramid()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 4 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  yv = -1 ;
  for (k = 0; k < n ; k++) {
    save_line(0,2,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
  
}




int tetra_fractal(double x0, double y0, double z0,
                  double x1, double y1, double z1,
	                double x2, double y2, double z2,
	                double x3, double y3, double z3,
	                int depth){

  if (depth == 0) {
  
    save_line(x0,y0,z0,  x1,y1,z1) ;
    save_line(x0,y0,z0,  x2,y2,z2) ;      
    save_line(x0,y0,z0,  x3,y3,z3) ;

    save_line(x1,y1,z1,  x2,y2,z2) ;
    save_line(x2,y2,z2,  x3,y3,z3) ;
    save_line(x3,y3,z3,  x1,y1,z1) ;     

    return 0 ;
  }


  double xa,ya,za,  xb,yb,zb,  xc,yc,zc ;
  
  xa = (x0 + x1)/2 ;
  ya = (y0 + y1)/2 ;
  za = (z0 + z1)/2 ;

  xb = (x0 + x2)/2 ;
  yb = (y0 + y2)/2 ;
  zb = (z0 + z2)/2 ;

  xc = (x0 + x3)/2 ;
  yc = (y0 + y3)/2 ;
  zc = (z0 + z3)/2 ;    

  tetra_fractal(x0,y0,z0, xa,ya,za,  xb,yb,zb,  xc,yc,zc, depth-1) ;


  xa = (x1 + x0)/2 ;
  ya = (y1 + y0)/2 ;
  za = (z1 + z0)/2 ;

  xb = (x1 + x2)/2 ;
  yb = (y1 + y2)/2 ;
  zb = (z1 + z2)/2 ;

  xc = (x1 + x3)/2 ;
  yc = (y1 + y3)/2 ;
  zc = (z1 + z3)/2 ;    

  tetra_fractal(x1,y1,z1, xa,ya,za,  xb,yb,zb,  xc,yc,zc, depth-1) ;


  xa = (x2 + x0)/2 ;
  ya = (y2 + y0)/2 ;
  za = (z2 + z0)/2 ;

  xb = (x2 + x1)/2 ;
  yb = (y2 + y1)/2 ;
  zb = (z2 + z1)/2 ;

  xc = (x2 + x3)/2 ;
  yc = (y2 + y3)/2 ;
  zc = (z2 + z3)/2 ;    

  tetra_fractal(x2,y2,z2, xa,ya,za,  xb,yb,zb,  xc,yc,zc, depth-1) ;


  xa = (x3 + x0)/2 ;
  ya = (y3 + y0)/2 ;
  za = (z3 + z0)/2 ;

  xb = (x3 + x1)/2 ;
  yb = (y3 + y1)/2 ;
  zb = (z3 + z1)/2 ;

  xc = (x3 + x2)/2 ;
  yc = (y3 + y2)/2 ;
  zc = (z3 + z2)/2 ;    

  tetra_fractal(x3,y3,z3, xa,ya,za,  xb,yb,zb,  xc,yc,zc, depth-1) ;      


  
  return 1 ;
}





int build_tetra_fractal()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 3 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  yv = -1 ;

  tetra_fractal(0,1,0,   x[0],yv,z[0],  x[1],yv,z[1],  x[2],yv,z[2], 3) ;
}







int test_tetra_fractal_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_tetra_fractal() ;  
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;

    project(3,30) ;
    draw() ;
    rotate_y(2) ;
    if (G_wait_key() == 'q') { break ; }
  }
  
}



int octa_fractal(double x0, double y0, double z0,
                  double x1, double y1, double z1,
	                double x2, double y2, double z2,
	                int depth){
  
  if( depth <= 0 ) {
    return 0;
  } else {
  double xa,ya,za,  xb,yb,zb,  xc,yc,zc ;
  
  xa = (x0 + x1)/2 ;
  ya = (y0 + y1)/2 ;
  za = (z0 + z1)/2 ;

  xb = (x0 + x2)/2 ;
  yb = (y0 + y2)/2 ;
  zb = (z0 + z2)/2 ;

  xc = (x1 + x2)/2 ;
  yc = (y1 + y2)/2 ;
  zc = (z1 + z2)/2 ;

  octa_fractal(x0,y0,z0,  xa,ya,za,  xb,yb,zb, depth-1);
  octa_fractal(xa,ya,za,  x1,y1,z1,  xc,yc,zc, depth-1);
  octa_fractal(xb,yb,zb,  xc,yc,zc,  x2,y2,z2, depth-1);
  
  // draw three lines of triangle
  save_line(x0,y0,z0,  x1,y1,z1) ;
  save_line(x0,y0,z0,  x2,y2,z2) ;      
  save_line(x1,y1,z1,  x2,y2,z2) ; 
  }
}


int build_octa_fractal()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 8 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  yv = -1 ;
  for (k = 0; k < n ; k++) {
    octa_fractal(0,1,0, x[k],yv,z[k], x[k+1],yv,z[k+1], 5);
  }  
}
  

int test_octa_fractal()
{
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;

  build_octa_fractal() ;
  project(3,45) ;
  draw() ;
  //print_object() ;
  
  G_wait_key() ;
}



int test_octa_fractal_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_octa_fractal() ;  
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;

    project(3,30) ;
    draw() ;
    rotate_x(2) ;
    if (G_wait_key() == 'q') { break ; }
  }
  
}


int main()
{
  G_choose_repl_display();
  G_init_graphics(Wsize, Wsize);

  //test_tetra_fractal_rotate() ;
  //test_octa_fractal();
  test_octa_fractal_rotate();
}
