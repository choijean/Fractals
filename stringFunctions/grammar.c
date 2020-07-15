/*
* Jean Choi
*	7/14/2020
* CS410P: Exploring Fractals, taught by Dr. David Ely
*
* The goal of this program is to make a simple rule replacement grammar
* Axiom = ++F
* Rule  = F -> -F+F-
*/

#include "FPToolkit.c"

char u[1000];

typedef struct Production {
	char var ;
	char axiom[100] ;
	char rule[100] ;
} Production ;

const int numRules = 2;
struct Production prd[numRules];

int main()
{
	u[0] = '\0';

	// AXIOM
	int rule_num = 0 ;
	strcpy(prd[rule_num].axiom,"++F") ;
	rule_num++ ;
	// RULE 1
	prd[rule_num].var = 'F' ;
	strcpy(prd[rule_num].rule, "-F+F-") ;
	rule_num++ ;

	// get depth from user 
  int n;
  printf("\nPlease type in the depth: ");
  scanf("%d", &n);

	


	printf("\naxiom: %s", prd[0].axiom);
	printf("\nu: %s", u);





	//===============================================
	
	int key ;   
	key =  G_wait_key() ; // pause so user can see results

	// save file
	G_save_to_bmp_file("grammar.bmp") ;
}


/*

rule_num = 0 ;

	strcpy(prd[rule_num].axiom,"A") ;
	rule_num++ ;

	prd[rule_num].var = 'A' ;
	strcpy(prd[rule_num].rule, "f-f-B") ;
	rule_num++ ;

	prd[rule_num].var = 'B' ;
	strcpy(prd[rule_num].rule, "f+f"A") ;
	rule_num++ ;

*/