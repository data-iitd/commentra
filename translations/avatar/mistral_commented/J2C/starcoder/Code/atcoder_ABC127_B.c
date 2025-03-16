
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char * buffer ;
    size_t size ;
    size_t length ;
    FILE * stream ;
} SimpleScanner ;

void init_scanner ( SimpleScanner * scanner, FILE * stream ) {
    scanner->stream = stream ;
    scanner->buffer = malloc ( BUFFER_SIZE * sizeof ( char ) ) ;
    scanner->size = BUFFER_SIZE ;
    scanner->length = 0 ;
}

void free_scanner ( SimpleScanner * scanner ) {
    free ( scanner->buffer ) ;
}

void read_char ( SimpleScanner * scanner ) {
    if ( scanner->length == scanner->size ) {
        scanner->size *= 2 ;
        scanner->buffer = realloc ( scanner->buffer, scanner->size * sizeof ( char ) ) ;
    }
    scanner->buffer[scanner->length] = fgetc ( scanner->stream ) ;
    scanner->length += 1 ;
}

void check_eof ( SimpleScanner * scanner ) {
    if ( scanner->length == scanner->size ) {
        scanner->size *= 2 ;
        scanner->buffer = realloc ( scanner->buffer, scanner->size * sizeof ( char ) ) ;
    }
    scanner->buffer[scanner->length] = '\0' ;
    scanner->length += 1 ;
}

char next_char ( SimpleScanner * scanner ) {
    read_char ( scanner ) ;
    check_eof ( scanner ) ;
    return scanner->buffer[scanner->length - 2] ;
}

char * next ( SimpleScanner * scanner ) {
    char * result = malloc ( scanner->length * sizeof ( char ) ) ;
    size_t i = 0 ;
    while ( i < scanner->length - 1 ) {
        result[i] = scanner->buffer[i] ;
        i += 1 ;
    }
    result[i] = '\0' ;
    return result ;
}

int next_int ( SimpleScanner * scanner ) {
    return atoi ( next ( scanner ) ) ;
}

long next_long ( SimpleScanner * scanner ) {
    return atol ( next ( scanner ) ) ;
}

double next_double ( SimpleScanner * scanner ) {
    return atof ( next ( scanner ) ) ;
}

int main ( int argc, char * argv [ ] ) {
    SimpleScanner scanner ;
    init_scanner ( & scanner, stdin ) ;
    FILE * output = fopen ( "output.txt", "w" ) ;
    int r = next_int ( & scanner ) ;
    int d = next_int ( & scanner ) ;
    long x = next_long ( & scanner ) ;
    for ( int i = 0 ; i < 10 ; ++ i ) {
        x = r * x - d ;
        fprintf ( output, "%ld\n", x ) ;
    }
    free_scanner ( & scanner ) ;
    fclose ( output ) ;
    return 0 ;
}

