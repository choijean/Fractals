#include "FPToolkit.c"

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



int main() 
{
  int q ;

  //  G_choose_repl_display() ;
  G_init_graphics(600, 600) ;

  G_rgb(0,0,0) ;
  G_clear() ;

  G_rgb(0,0,1) ;
  G_fill_polygon(x,y,n) ;
  q = G_wait_key() ;

  translate(150, 0) ;

  G_rgb(1,0,1) ;
  G_fill_polygon(x,y,n) ;
  q = G_wait_key() ;

}


