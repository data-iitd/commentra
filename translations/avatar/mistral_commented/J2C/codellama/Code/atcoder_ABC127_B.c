
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// A structure for reading input
typedef struct {
    FILE *in ;
    char buffer[BUFFER_SIZE] ;
    int buffer_size ;
    int buffer_index ;
    int eof ;
} SimpleScanner ;

// A function for initializing the SimpleScanner object
void init_scanner ( SimpleScanner *scanner, FILE *in ) {
    scanner->in = in ;
    scanner->buffer_size = 0 ;
    scanner->buffer_index = 0 ;
    scanner->eof = 0 ;
}

// A function for reading a single character from the input stream
char read_char ( SimpleScanner *scanner ) {
    // If the character buffer is empty, refill it
    if ( scanner->buffer_index == scanner->buffer_size ) {
        scanner->buffer_size = fread ( scanner->buffer, sizeof ( char ), BUFFER_SIZE, scanner->in ) ;
        scanner->buffer_index = 0 ;
    }
    // Return the current character from the character buffer
    return scanner->buffer[scanner->buffer_index++] ;
}

// A function for checking the end-of-file condition
void check_eof ( SimpleScanner *scanner ) {
    if ( scanner->eof ) {
        fprintf ( stderr, "Error: End of file reached.\n" ) ;
        exit ( 1 ) ;
    }
}

// A function for reading a single character
char next_char ( SimpleScanner *scanner ) {
    check_eof ( scanner ) ;
    char b = read_char ( scanner ) ;
    check_eof ( scanner ) ;
    return b ;
}

// A function for reading a string
char *next ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb ;
}

// A function for reading an integer
int next_int ( SimpleScanner *scanner ) {
    return atoi ( next ( scanner ) ) ;
}

// A function for reading a long integer
long next_long ( SimpleScanner *scanner ) {
    return atol ( next ( scanner ) ) ;
}

// A function for reading a double
double next_double ( SimpleScanner *scanner ) {
    return atof ( next ( scanner ) ) ;
}

// A function for reading a line
char *next_line ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb ;
}

// A function for reading a string
char *next_string ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb ;
}

// A function for reading a character
char next_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a boolean
int next_bool ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    if ( strcmp ( sb, "true" ) == 0 ) {
        return 1 ;
    } else if ( strcmp ( sb, "false" ) == 0 ) {
        return 0 ;
    } else {
        fprintf ( stderr, "Error: Invalid boolean value.\n" ) ;
        exit ( 1 ) ;
    }
}

// A function for reading a character
char next_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb[0] ;
}

// A function for reading a character
char next_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char_char ( SimpleScanner *scanner ) {
    char *sb = ( char * ) malloc ( sizeof ( char ) * 1024 ) ;
    char b ;
    int i = 0 ;
    do {
        b = read_char ( scanner ) ;
        check_eof ( scanner ) ;
        sb[i++] = b ;
    } while ( b != ' ' && b != '\n' && ! scanner->eof ) ;
    sb[i] = '\0' ;
    return sb