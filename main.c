#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"


int main()
{
    FILE *fichier = NULL ;
    char *lib = NULL ;

    fichier = fopen("lib.txt" , "r") ;
    
    if(fichier != NULL )
    {
	printf("\033[31m");
	print(fichier , "Presentation") ;
	
	lib = malloc(20*sizeof(char)) ;
	
	do
	{
	    printf("\033[7m" );
	    printf("\n\n\t Librairie a presenter (q pour quitter) : ") ;
	    printf("\033[0m" );
	    fgets(lib , 18 , stdin) ;
       
	}while(presentation_lib(lib , fichier) == 1) ;

	free(lib) ;
    }
    
    fclose(fichier) ;

    printf("\n Lien github du dépot : https://github.com/Yann0511/presentation-de-bibliotheque.git \n") ;

    return 0 ;
}
