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

  double r,g,b , sr,sg,sb , er,eg,eb ;
  y0 = 0 ;
  y1 = 600 ;
  
  dy = y1-y0 ;

  sr = 0.117 ;  sg = 0.117 ;  sb = 0.263 ;
  er = 0.117 ;  eg = 0.351 ;  eb = 0 ; 

    
  for(int k=y0;k<=y1;k++) {

    sf = (k-y0)/dy ;
    //sf = pow(sf,3) ;
    r = sr + sf*(er-sr) ;  g = sg + sf*(eg-sg) ;  b = sb + sf*(eb-sb) ;
    G_rgb(r,g,b) ;
    G_line(0,k,600,k) ;
      
  }
}


int main()
{

		// repl.it display
	G_choose_repl_display() ;


  
  G_init_graphics(600,600) ;

  //colorFade();
  background();

  G_wait_key() ;
}
