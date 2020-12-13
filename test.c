#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


void test_isalnum()
{

    char buffer[80];
    bool isCorrect = true;
    size_t length ;
    
    printf( "Enter your login (only alpha-numeric characters) : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 

    length = strlen( buffer );
    for( int i=0; i<length; i++ )
    {
        if ( isalnum( buffer[i] ) == false )
            isCorrect = false;
    }

    if ( isCorrect )
        printf( "Your login is correct\n" );

    else
        printf( "Your login is not correct\n" );

}


void  test_isalpha()
{

    char buffer[80];
    bool isCorrect = true;
    size_t length ;

    printf( "Enter your last name : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 
    
    length = strlen( buffer );
    for( int i=0; i<length; i++ )
        if ( isalpha( buffer[i] ) == false && isblank( buffer[i] ) == false )
            isCorrect = false;

    if ( isCorrect )
        printf( "Your last name (%s) is correct\n", buffer );

    else
        printf( "Your last name (%s) is not correct\n", buffer );

}


void test_isblank()
{

    printf( "%d\n", isblank( ' ' ) );
    printf( "%d\n", isblank( '\t' ) );
    printf( "%d\n", isblank( '\n' ) );
    
}


size_t strcpyWithoutControlCharacters( char * dest, const char * source ) {

    size_t counter = 0;
    char currentCharacter;
    do {
        currentCharacter = *source++;
        if ( ! iscntrl( currentCharacter ) ) {
            *dest++ = currentCharacter;
            counter ++;
        }
    } while ( currentCharacter != '\0' );

    *dest = '\0';

    return counter;
}

void test_iscntrl()
{

    const char * original = "Hello\tWorld\nBye\r";
    char buffer[ 20 ];

    size_t length = strcpyWithoutControlCharacters( buffer, original );

    printf( "strlen(\"%s\") == %zu\n", buffer, length );

}


void test_isdigit()
{

    char buffer[80];
    bool isCorrect = true;
    size_t length ;
    
    printf( "Enter your text : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 
    
    length = strlen( buffer );
    for( int i=0; i<length; i++ )
        if ( ! isdigit( buffer[i] ) )
            isCorrect = false;

    if ( isCorrect )
        printf( "Your text (%s) is a number\n", buffer );

    else
        printf( "Your text (%s) is not a number\n", buffer );
    
}


void test_isgraph()
{

    char * originalString = "Hello\nWorld Final\tWord";
    size_t length = strlen( originalString );
    size_t counter = 0;

    for( size_t i=0; i<length; i++ ) 
        if ( isgraph( originalString[i] ) )
	{
            printf( "%c", originalString[i] );
            counter ++;
        }

    printf( "\n" );
    assert( counter == 19 );

}


void test_islower()
{

    char buffer[80];
    size_t length ;
    
    printf( "Enter your last name : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 
    
    length = strlen( buffer ) ;

    for( size_t i=0; i<length; i++ )
        if ( islower( buffer[i] ) )
            buffer[i] &= 223;  // equivalent à un appel à toupper

    printf( "Hello %s\n", buffer );

}


void test_isprint(){

        char * originalString = "Hello\nWorld Final\tWord";
        size_t length = strlen( originalString );

        for( size_t i=0; i<length; i++ )
            if ( isprint( originalString[i] ) )
                printf( "%c", originalString[i] );

        printf( "\n" );

}


void test_ispunct(){

    char * originalString = "Ceci est mon message : il est <<cool>>, n'est ce pas ?";
    size_t length = strlen( originalString );
    size_t counter = 0;

    for( size_t i=0; i<length; i++ )
        if ( ispunct( originalString[i] ) ) {
            printf( "%c", originalString[i] );
            counter ++;
        }

    printf( "\n" );

    assert( counter == 8 );

}


void test_isspace() {

    printf( "%d - %d\n", isblank( ' ' ), isspace( ' ' ) );
    printf( "%d - %d\n", isblank( '\t' ), isspace( '\t' ) );
    printf( "%d - %d\n", isblank( '\n' ), isspace( '\n' ) );
    printf( "%d - %d\n", isblank( 'a' ), isspace( 'a' ) );

}


void test_isupper(){

    char buffer[80];
    size_t length;
    printf( "Enter your last name : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 
    
   length = strlen( buffer );
   for( size_t i = 0; i < length; i++ )
       if ( isupper( buffer[i] ) ) {
           buffer[i] |= 32;  /*equivalent à un appel à tolower (buffer[i] += 32)*/
       }


   printf( "Hello %s\n", buffer );
}


void test_isxdigit(){

    char buffer[80];
    bool isCorrect = true;
    size_t length;

    printf( "Enter a hexadecimal value : " );
    scanf( "%[^\n]", buffer );
    getchar() ; 

    length = strlen( buffer );
    for( int i=0; i<length; i++ )
        if ( ! isxdigit( buffer[i] ) )
            isCorrect = false;

    if ( isCorrect ) {
        printf( "Your text (%s) is a hexadecimal number\n", buffer );
        unsigned long value = strtoul( buffer, 0, 16 );
        printf( "The corresponding decimal value is %zu\n", value );
    }
    else
        printf( "Your text (%s) is not a hexadecimal number\n", buffer );

}


char * strtolower( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = tolower( *src++ ) );
    return result;
}

void test_tolower(){

    char * input = "Diego De La Vega";
    char result[17];

    printf( "Result: %s\n", strtolower( result, input ) );
}


char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

void test_toupper() {

    char * input = "Diego De La Vega";
    char result[17];

    printf( "Result: %s\n", strtoupper( result, input ) );

}


void test_limits()
{

    printf("Le nombre de bits dans un byte est %d \n \n ", CHAR_BIT);

    printf("La valeur minimale d'un char signe est : SIGNED CHAR = %d \n\n ", SCHAR_MIN);

    printf("La valeur maximale d'un char signe est : SIGNED CHAR = %d \n \n", SCHAR_MAX);

    printf("La valeur maximale d'un char non signe est : UNSIGNED CHAR = %d \n\n ", UCHAR_MAX);

    printf("La valeur minimale d'un short int est : SHORT INT = %d \n \n ", SHRT_MIN);

    printf("La valeur maximale d'un short int est : SHORT INT = %d \n \n", SHRT_MAX);

    printf("La valeur minimale d'un int est : INT = %d \n \n", INT_MIN);

    printf("La valeur maximale d'un int est : INT = %d \n \n", INT_MAX);

    printf("La valeur minimale d'un char est : CHAR = %d \n \n", SCHAR_MIN);

    printf("La valeur  maximale d'un char est : CHAR = %d \n \n", SCHAR_MAX);

    printf("La valeur minimale d'un long est : LONG = %ld \n \n ", LONG_MIN);

    printf("La valeur maximale d'un long est : LONG = %ld \n \n", LONG_MAX);

}
