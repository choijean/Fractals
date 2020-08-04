#include "FPToolkit.c"

void colorFade(){
  double x0,y0 , x1,y1, dx, dy ;
  double sf ;

  double r,g,b , sr,sg,sb , er,eg,eb ;
  y0 = 80 ;
  y1 = 400 ;
  
  dy = y1-y0 ;

  sr = 139/255.0 ;  sg = 0/255.0 ;    sb = 100/255.0 ;
  er = 64/255.0 ;   eg = 224/255.0 ;  eb = 208/255.0 ; 

    
  for(int k=y0;k<=y1;k++) {

    sf = (k-y0)/dy ;
    //sf = pow(sf,3) ;
    r = sr + sf*(er-sr) ;  g = sg + sf*(eg-sg) ;  b = sb + sf*(eb-sb) ;
    G_rgb(r,g,b) ;
    G_line(0,k,600,k) ;
      
  }
}


void background(){
  double x0,y0 , x1,y1, dx, dy ;
  double sf ;

  double r,g,b;
  double r1,g1,b1 ;
  double r2,g2,b2 ;
  y0 = 0 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  r1 = 1.0 ;  g1 = 0.0 ;  b1 = 0.0 ;
  r2 = 1.0 ;  g2 = 1.0 ;  b2 = 0.0 ;
    
  for(int k=y0;k<=y1;k++) {

    sf = (k-y0)/dy ;
    r = r1 + sf*(r2-r1) ;  g = g1 + sf*(b2-g1) ;  b = b1 + sf*(b2-b1) ;
    G_rgb(r,g,b) ;
    G_line(0,k,600,k) ;
      
  }
}

void background2() {
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


int main()
{

		// repl.it display
	G_choose_repl_display() ;

  
  G_init_graphics(600,600) ;

  //colorFade();
  //background();
  background2();

  G_wait_key() ;
}
