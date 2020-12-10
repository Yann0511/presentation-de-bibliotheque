#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"


void init_chaine(char *chaine)
{
    int i ;

    for(i = 0 ; i < TAILLE_MAX ; i++)
	chaine[i] = '\0' ;
}



int compare(char *tab1 , char *tab2 , int nb)
{
    int i ;

    for(i = 0 ; i < nb ; i++)
	if(tab1[i] > tab2[i] || tab1[i] < tab2[i] )
	    return 1 ;
    if( i > 0 )
	if(tab1[i-1] == tab2[i-1])
	    return 0 ;
    else
	return 1 ;
	    
}


void search(FILE *fichier , char *fonction)
{
    int i ;
    char chaine[TAILLE_MAX] ;

    rewind(fichier);

    while(!feof(fichier))
    {
	init_chaine(chaine) ;
	fgets(chaine , TAILLE_MAX - 2 , fichier) ;

	if(!compare(chaine , fonction , strlen(fonction)))
	    break ;
    }

}

void color(char *tab)
{
    if(!compare(tab , "BLANC\n" , 6))
    {
	init_chaine(tab) ;
	printf("\033[0m" );
    }

    else if(!compare(tab , "JAUNE\n" , 6))
    {
	init_chaine(tab) ;
	printf("\033[93m" );
    }

    else if(!compare(tab , "VERT\n" , 5))
    {
	init_chaine(tab) ;
	printf("\033[32m" );
    }

    else if(!compare(tab , "CYAN\n" , 5))
    {
	init_chaine(tab) ;
	printf("\033[36m" );
    }

    else if(!compare(tab , "BLEU\n" , 5))
    {
	init_chaine(tab) ;
	printf("\033[34m" );
    }

    else if(!compare(tab , "CLI\n" , 4))
    {
	init_chaine(tab) ;
	printf("\033[5m" );
    }
}

void print(FILE *fichier , char *fonction)
{
    char chaine[TAILLE_MAX] , fin[4]= "FiN" ;

    init_chaine(chaine) ;

    search(fichier , fonction) ;
    
    while(compare(chaine , fin , 3) && !feof(fichier))
    {
	init_chaine(chaine) ;
	fgets(chaine , TAILLE_MAX - 2 , fichier) ;

	if(compare(chaine , fin , 3))
	{
	    color(chaine) ;
	    printf("%s" , chaine) ;
	}
    }

}


int presentation_lib(char *tab , FILE *fichier)
{
    char *fonc = NULL ;
    
    if(!compare(tab , "ctype.h\n" , strlen(tab)))
    {
	print(fichier , "ctype.h\n");
	fonc = malloc(sizeof(char)*20) ;

	do
	{
	    printf("\033[7m" );
	    printf("\n\n\t Fonction a presenter ( c pour changer de librairie et q pour quitter) : ") ;
	    printf("\033[0m" );
	    fgets(fonc , 18 , stdin) ;
		    
	    presentation_fonctype(fonc , fichier) ;
	}while(compare(fonc , "c\n" , 2) && compare(fonc , "q\n" , 2)) ;

	if(!compare(fonc , "c\n" , 2))
	{
	    free(fonc) ;
	    return 1 ;
	}
	
	else
	{
	    free(fonc) ;
	    return 2 ;
	}
    }

    else if(!compare(tab , "limit.h\n" , 8))
    {
	print(fichier , "limit.h\n");
	test(LIMIT) ;
	return 1 ;
    }

    else if(!compare(tab , "q\n" , 2))
	return 2 ;
    else
    {
	printf("\n\n\t Cette librairie n'est pas dans la documentation") ;
	return 1 ;
    }
}


void presentation_fonctype(char *tab , FILE *fichier)
{
    
    if(!compare(tab , "isalnum\n", strlen(tab)))
    {
	print(fichier , "isalnum\n") ;
	test(ISALNUM) ;
    }
	
    else if(!compare(tab , "isalpha\n" , strlen(tab)))
    {
	print(fichier , "isalpha\n") ;
	test(ISALPHA) ;
    }

    else if(!compare(tab , "isblank\n" , strlen(tab)))
    {
	print(fichier , "isblank\n") ;
	test(ISBLANK) ;
    }

    else if(!compare(tab , "iscntrl\n" , strlen(tab)))
    {
	print(fichier , "iscntrl\n") ;
	test(ISCNTRL) ;
    }
	
    else if(!compare(tab , "isdigit\n" , strlen(tab)))
    {
	print(fichier , "isdigit\n") ;
	test(ISDIGIT) ;
    }

    else if(!compare(tab , "isgraph\n" , strlen(tab)))
    {
	print(fichier , "isgraph\n") ;
	test(ISGRAPH) ;
    }

    else if(!compare(tab , "islower\n" , strlen(tab)))
    {
	print(fichier , "islower\n") ;
	test(ISLOWER) ;
    }
    
    else if(!compare(tab , "isprint\n" , strlen(tab)))
    {
	print(fichier , "isprint\n") ;
	test(ISPRINT) ;
    }

    else if(!compare(tab , "ispunct\n" , strlen(tab)))
    {
	print(fichier ,"ispunct\n") ;
	test(ISPUNCT) ;
    }

    else if(!compare(tab , "isspace\n" , strlen(tab)))
    {
	print(fichier , "isspace\n") ;
	test(ISSPACE) ;
    }

    else if(!compare(tab , "isupper\n" , strlen(tab)))
    {
	print(fichier , "isupper\n") ;
	test(ISUPPER) ;
    }

    else if(!compare(tab , "isxdigit\n" , strlen(tab)))
    {
	print(fichier , "isxdigit\n") ;
	test(ISXDIGIT) ;
    }

    else if(!compare(tab , "tolower\n" , strlen(tab)))
    {
	print(fichier , "tolower\n") ;
	test(TOLOWER) ;
    }

    else if(!compare(tab , "toupper\n" , strlen(tab)))
    {
	print(fichier , "toupper\n") ;
	test(TOUPPER) ;
    }

    else if(!compare(tab , "c\n" , 2))
	printf("\n\n\t\t\t\t\t Changement de librairie") ;

    else if(!compare(tab , "q\n" , 2))
    {
    }
	 
    else
	printf("\n\n\t Cette fonction n'est pas dans la documentation") ;
}


void test(int id)
{
    char choix[3] ;

    printf("\033[7m" );
    printf("\n\n\t Voulez vous tester la fonction (y/n) : ") ;
    printf("\033[0m" );
    fgets(choix , 3 , stdin) ;
    

    while( choix[0] != 'n' && choix[0] != 'N')
    {
	switch (id)
	{
	case ISALNUM :
	    test_isalnum() ;
	    break ;

	case ISALPHA :
	    test_isalpha() ;
	    break ;

	case ISBLANK :
	    test_isblank ;
	    break ;

	case ISCNTRL :
	    test_iscntrl ;
	    break ;

	case ISDIGIT :
	    test_isdigit ;
	    break ;

	case ISGRAPH :
	    test_isgraph ;
	    break ;

	case ISLOWER :
	    test_islower ;
	    break ;

	case ISPRINT :
	    test_isprint() ;
	    break ;

	case ISPUNCT :
	    test_ispunct() ;
	    break ;

	case ISSPACE :
	    test_isspace() ;
	    break ;

	case ISUPPER :
	    test_isupper() ;
	    break ;

	case ISXDIGIT :
	    test_isxdigit() ;
	    break ;

	case TOLOWER :
	    test_tolower() ;
	    break ;

	case TOUPPER :
	    test_toupper() ;
	    break ;

	default :
	    break ;
	}

	printf("\033[7m" );
	printf("\n\n\t Voulez vous retester la fonction (y/n) : ") ;
	printf("\033[0m" );
	fgets(choix , 3 , stdin) ;
	

    }
}
       
