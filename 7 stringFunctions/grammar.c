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

char v[1000];
char u[1000];
char temp[1000];

typedef struct Production {
	char var ;
	char axiom[100] ;
	char rule[100] ;
} Production ;

const int numRules = 2;

int main()
{
  struct Production prd[numRules];
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
  printf("Please type in the depth: \n");
  scanf("%d", &n);

  // rule replace n times
  strcpy (u, prd[0].axiom);
  for(int j = 0; j < n; j++) {
    strcpy(v,u);
    memset(&u[0], 0, sizeof(u));
    for(int i = 0; i < strlen(v); i++) {
      if(v[i] == prd[1].var) {
        strcat(u, prd[1].rule);
      }
      else {
        temp[0] = v[i];
        temp[1] = '\0' ;
        strcat(u, temp);
      }
    }
  }
  printf("u: %s\n", u);


	//printf("\naxiom: %s\n", prd[0].axiom);
	





	//===============================================

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