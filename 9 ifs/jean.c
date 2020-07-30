/*
* Jean Choi
* 7/23/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to create my name, JEAN, 
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
  const double n = 119.0; // number of blocks
  const double s = 20.0;
	const double swidth = 600 ;
	const double sheight = 600 ;
	G_init_graphics (swidth,sheight) ; 

	// clear the screen in a given colo‰ˇ
	G_rgb (0.8, 0.8, 0.8) ; // light gray
	G_clear () ;
	G_rgb (0.3, 0.5, 0.7) ; //light blue

  int j = 0;
  double r;
  double theta = M_PI/180.0;
  while (j < 100000000) {
    int r = (rand() % 120)+ 1; //random integers

    (1 <= r && r <= 100) ? scale(1/s, 1/s) : scale(2/s, 2/s);

    switch(r) {
      case 1 :                    //top line start
        translate(0/s, 19/s);
        break;
      case 2 :
        translate(1/s, 19/s);
        break;
      case 3 :
        translate(2/s, 19/s);
        break;
      case 4 :        
        translate(3/s, 19/s);
        break;
      case 5 :        
        translate(4/s, 19/s);
        break;
      case 6 :        
        translate(5/s, 19/s);
        break;
      case 7 :
        translate(6/s, 19/s);
        break;
      case 8 :
        translate(7/s, 19/s);
        break;
      case 9 :
        translate(8/s, 19/s);
        break;
      case 10 :
        translate(9/s, 19/s);
        break;
      case 11 :
        translate(10/s, 19/s);
        break;
      case 12 :
        translate(11/s, 19/s);
        break;
      case 13 :
        translate(12/s, 19/s);
        break;
      case 14 :
        translate(13/s, 19/s);
        break;
      case 15 :
        translate(14/s, 19/s);
        break;
      case 16 :
        translate(15/s, 19/s);
        break;
      case 17 :
        translate(16/s, 19/s);
        break;
      case 18 :
        translate(17/s, 19/s);
        break;
      case 19 :
        translate(18/s, 19/s);
        break;
      case 20 :
        translate(19/s, 19/s);
        break;
      case 21 :                     // going down right side
        translate(19/s, 18/s);
        break;
      case 22 :
        translate(19/s, 17/s);
        break;
      case 23 :
        translate(19/s, 16/s);
        break;
      case 24 :
        translate(19/s, 15/s);
        break;
      case 25 :
        translate(19/s, 14/s);
        break;
      case 26 :
        translate(19/s, 13/s);
        break;
      case 27 :
        translate(19/s, 12/s);
        break;
      case 28 :
        translate(19/s, 11/s);
        break;
      case 29 :
        translate(19/s, 10/s);
        break;
      case 30 :
        translate(19/s, 9/s);
        break;
      case 31 :
        translate(19/s, 8/s);
        break;
      case 32 :
        translate(19/s, 7/s);
        break;
      case 33 :
        translate(19/s, 6/s);
        break;
      case 34 :
        translate(19/s, 5/s);
        break;
      case 35 :
        translate(19/s, 4/s);
        break;
      case 36 :
        translate(19/s, 3/s);
        break;
      case 37 :
        translate(19/s, 2/s);
        break;
      case 38 :
        translate(19/s, 1/s);
        break;
      case 39 :
        translate(19/s, 0/s);
        break;
      case 40 :                   // going backwards on bottom row
        translate(18/s, 0/s);
        break;
      case 41 :
        translate(17/s, 0/s);
        break;
      case 42 :
        translate(16/s, 0/s);
        break;
      case 43 :
        translate(15/s, 0/s);
        break;
      case 44 :
        translate(14/s, 0/s);
        break;
      case 45 :
        translate(13/s, 0/s);
        break;
      case 46 :
        translate(12/s, 0/s);
        break;
      case 47 :
        translate(11/s, 0/s);
        break;
      case 48 :
        translate(10/s, 0/s);
        break;
      case 49 :
        translate(9/s, 0/s);
        break;
      case 50 :
        translate(8/s, 0/s);
        break;
      case 51 :
        translate(7/s, 0/s);
        break;
      case 52 :
        translate(6/s, 0/s);
        break;
      case 53 :
        translate(5/s, 0/s);
        break;
      case 54 :
        translate(4/s, 0/s);
        break;
      case 55 :
        translate(3/s, 0/s);
        break;
      case 56 :
        translate(2/s, 0/s);
        break;
      case 57 :
        translate(1/s, 0/s);
        break;
      case 58 :
        translate(0/s, 0/s);
        break;
      case 59 :                     // going back up on left side
        translate(0/s, 1/s);
        break;
      case 60 :
        translate(0/s, 2/s);
        break;
      case 61 :
        translate(0/s, 3/s);
        break;
      case 62 :
        translate(0/s, 4/s);
        break;
      case 63 :
        translate(0/s, 5/s);
        break;
      case 64 :
        translate(0/s, 6/s);
        break;
      case 65 : translate(0/s, 7/s); break;
      case 66 : translate(0/s, 8/s); break;
      case 67 : translate(0/s, 9/s); break;
      case 68 : translate(0/s, 10/s); break;
      case 69 : translate(0/s, 11/s); break;
      case 70 : translate(0/s, 12/s); break;
      case 71 : translate(0/s, 13/s); break;
      case 72 : translate(0/s, 14/s); break;
      case 73 : translate(0/s, 15/s); break;
      case 74 : translate(0/s, 16/s); break;
      case 75 : translate(0/s, 17/s); break;
      case 76 : translate(0/s, 18/s); break;
      case 77 : translate(1/s, 15/s); break; // J negative space
      case 78 : translate(2/s, 15/s); break;
      case 79 : translate(3/s, 15/s); break;
      case 80 : translate(4/s, 15/s); break;
      case 81 : translate(5/s, 15/s); break;
      case 82 : translate(5/s, 14/s); break;
      case 83 : translate(14/s, 16/s); break; // E negative space top
      case 84 : translate(15/s, 16/s); break;
      case 85 : translate(16/s, 16/s); break;
      case 86 : translate(17/s, 16/s); break;
      case 87 : translate(18/s, 16/s); break;
      case 88 : translate(14/s, 13/s); break; // E negative space bottom
      case 89 : translate(15/s, 13/s); break;
      case 90 : translate(16/s, 13/s); break;
      case 91 : translate(17/s, 13/s); break;
      case 92 : translate(18/s, 13/s); break;
      case 93 : translate(16/s, 8/s); break; // N negative space top
      case 94 : translate(16/s, 7/s); break;
      case 95 : translate(16/s, 6/s); break;
      case 96 : translate(16/s, 5/s); break;
      case 97 : translate(13/s, 4/s); break; // N negative space bottom
      case 98 : translate(13/s, 3/s); break;
      case 99 : translate(13/s, 2/s); break;
      case 100 : translate(13/s, 1/s); break;
      case 101 : translate(4/s, 5/s); break; // A negative space
      case 102 : translate(4/s, 1/s); break;
      case 103 : translate(9/s, 17/s); break; // vert space between letters
      case 104 : translate(9/s, 15/s); break;
      case 105 : translate(9/s, 13/s); break;
      case 106 : translate(9/s, 11/s); break;
      case 107 : translate(9/s, 9/s); break;
      case 108 : translate(9/s, 7/s); break;
      case 109 : translate(9/s, 5/s); break;
      case 110 : translate(9/s, 3/s); break;
      case 111 : translate(9/s, 1/s); break;
      case 112 : translate(1/s, 9/s); break; // horizontal space between letters
      case 113 : translate(3/s, 9/s); break;
      case 114 : translate(5/s, 9/s); break;
      case 115 : translate(7/s, 9/s); break;
      case 116 : translate(11/s, 9/s); break;
      case 117 : translate(13/s, 9/s); break;
      case 118 : translate(15/s, 9/s); break;
      default : translate(17/s, 9/s);
    }

    G_point(swidth*x[0], sheight*y[0]);
    j++;
  }


	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("jean.bmp") ;
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
