#include <stdio.h>
#include <string.h>

// (FPToolkit.c includes these for you)

// convention :  strings in C are null-terminated character arrays

// useful string manipulation tools



int test01()
{
  // If the user inputs the word "dog" and then the word "food"
  // what does the program print?
  int n ;
  char a[100],b[100],c[100] ;

  printf("enter first word : ") ; 
  scanf("%s",a) ;
  printf("enter second word : ") ;   
  scanf("%s",b) ;
  strcpy(c, a) ; // copies a into c
  strcat(c, b) ; // concatenates b onto c.
  n = strlen(c) ;

  printf("The word %s has %d letters in it.\n",c,n) ;
}




int test02()
{
  char a[1000],b[1000],c[1000],d[1000] ;
  int length ;
  
  printf("enter first word : ") ;
  scanf("%s",a) ;
  printf("enter second word : ") ;  
  scanf("%s",b) ;
  printf("enter third word : ") ;    
  scanf("%s",c) ;

  strcpy(d,a) ;
  strcat(d,"_and_") ;
  strcat(d,b) ;
  strcat(d,"_and_") ;
  strcat(d,c) ;  

  length = strlen(d) ;
  printf("The string $%s$ has %d letters in it.\n",
	 d,length) ;

}

int test03() {
	char a[1000] , b[1000];
	b[0] = '\0';
	char temp[1000] ;
	int length ;

	printf("Enter a word:\n") ;
	scanf("%s",a) ;
	length = strlen(a) ;

	// replace all vowels with "zzz"
	for(int i = 0; i < length; i++) {
		switch (a[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I': 
			case 'O':
			case 'U':
			  strcat(b, "zzz");
				break;
			default:
				temp[0] = a[i];
				temp[1] = '\0' ;
				strcat(b, temp);
		}
	}
  printf("New string: %s\n", b) ;
}


int main()
{
  //test01() ;
  //test02() ;
	test03() ;
}



