#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 200

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
    {
	if(tab1[i] > tab2[i])
	    return 1;

	else if(tab1[i] < tab2[i])
	    return -1 ;

	else
	    if(i == nb-1)
		return 0 ;
    }
}


void search(FILE *fichier , char *fonction)
{
    int i , controle = 0 ;
    char chaine[TAILLE_MAX] ;

    rewind(fichier);

    while(!feof(fichier))
    {
	init_chaine(chaine) ;
	fgets(chaine , TAILLE_MAX - 2 , fichier) ;

	if(!compare(chaine , fonction , strlen(fonction)))
	{
	    controle = 1 ;
	    break ;
	}
    }

    if(!controle)
	printf("\n La fonction n'st pas dans le fichier") ;

}


void print(FILE *fichier , char *fonction)
{
    char chaine[TAILLE_MAX] , fin[4]= "FiN" ;

    init_chaine(chaine) ;

    search(fichier , fonction) ;
    
    while(compare(chaine , fin , 3))
    {
	init_chaine(chaine) ;
	fgets(chaine , TAILLE_MAX - 2 , fichier) ;

	if(compare(chaine , fin , 3))
	    printf("%s" , chaine) ;
    }

}


int main()
{
    FILE *fichier = NULL ;
    char fonction[30] = "Fonction isalpha" ;

    fichier = fopen("ctype.txt" , "r") ;

    if(fichier != NULL)
	print(fichier , fonction) ;

    fclose(fichier) ;

    return 0 ;

}
