#ifndef BIBLIO
#define BIBLIO

#define TAILLE_MAX 200
#define ISALNUM 1
#define ISALPHA 2
#define ISBLANK 3
#define ISCNTRL 4
#define ISDIGIT 5
#define ISGRAPH 6
#define ISLOWER 7
#define ISPRINT 8
#define ISPUNCT 9
#define ISSPACE 10
#define ISUPPER 11
#define ISXDIGIT 12
#define TOLOWER 13
#define TOUPPER 14
#define LIMITS 15

#include <assert.h>

void init_chaine(char *chaine) ;
 void test_limits();
int compare(char *tab1 , char *tab2 , int nb) ;

void search(FILE *fichier , char *fonction) ;

void print(FILE *fichier , char *fonction) ;

void presentation_fonctype(char *tab , FILE *fichier) ;

int presentation_lib(char *tab , FILE *fichier) ;

void color(char *tab) ;

void test(int id) ;

           /* fonction de test*/
void test_isalnum() ;

void  test_isalpha() ;

void test_isblank() ;

size_t strcpyWithoutControlCharacters( char * dest, const char * source ) ;

void test_iscntrl() ;

void test_isdigit() ;

void test_islower() ;

void test_isgraph() ;

void test_isprint() ;

void test_ispunct() ;

void test_isspace() ;

void test_isupper() ;

void test_isxdigit() ;

void test_tolower() ;

void test_toupper() ;

void test_isprint();

void test_ispunct();

void test_isspace();

void test_isupper();

void test_isxdigit();

char * strtolower( char * dest, const char * src );

void test_tolower();

char * strtoupper( char * dest, const char * src );

void test_toupper();

#endif

