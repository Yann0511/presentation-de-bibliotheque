#ifndef BIBLIO
#define BIBLIO
#define TAILLE_MAX 200


void init_chaine(char *chaine) ;

int compare(char *tab1 , char *tab2 , int nb) ;

void search(FILE *fichier , char *fonction) ;

void print(FILE *fichier , char *fonction) ;

void presentation_fonctype(char *tab , FILE *fichier) ;

int presentation_lib(char *tab , FILE *fichier) ;

void color(char *tab) ;
    
#endif

