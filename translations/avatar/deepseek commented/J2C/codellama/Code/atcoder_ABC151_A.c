
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct RemRing { 
    long module ; 
}; 

struct RemRing * RemRing_new ( long module ) { 
    struct RemRing * this = malloc ( sizeof ( struct RemRing ) ) ; 
    this->module = module ; 
    return this ; 
} 

long RemRing_sum ( struct RemRing * this , long a , long b ) { 
    return ( a + b + this->module ) % this->module ; 
} 

long RemRing_sub ( struct RemRing * this , long a , long b ) { 
    return ( a - b + this->module ) % this->module ; 
} 

long RemRing_prod ( struct RemRing * this , long a , long b ) { 
    return ( a * b ) % this->module ; 
} 

long RemRing_div ( struct RemRing * this , long a , long b ) { 
    return ( a * RemRing_inv ( this , b ) ) % this->module ; 
} 

long RemRing_inv ( struct RemRing * this , long a ) { 
    long b = this->module ; 
    long u = 1 ; 
    long v = 0 ; 
    
    // Extended Euclidean Algorithm to find the modular inverse
    while ( b > 0 ) { 
        long t = a / b ; 
        a -= t * b ; 
        u -= t * v ; 
        long z = a ; 
        a = b ; 
        b = z ; 
        z = u ; 
        u = v ; 
        v = z ; 
    } 
    
    u %= this->module ; 
    if ( u < 0 ) u += this->module ; 
    return u ; 
} 

int main ( void ) { 
    // Create a BufferedReader to read input from the console
    struct BufferedReader * r = BufferedReader_new ( stdin ) ; 
    
    // Read a single line of input from the user
    char * s = NULL ; 
    char * sl [ ] = { NULL } ; 
    s = BufferedReader_readLine ( r ) ; 
    
    // Increment the first character of the input by 1 and print it
    printf ( "%c" , s [ 0 ] + 1 ) ; 
    
    // Free the memory allocated for the BufferedReader
    BufferedReader_free ( r ) ; 
    
    // Free the memory allocated for the input string
    free ( s ) ; 
    
    return 0 ; 
} 

struct BufferedReader { 
    FILE * in ; 
    char * line ; 
    int line_len ; 
    int line_cap ; 
}; 

struct BufferedReader * BufferedReader_new ( FILE * in ) { 
    struct BufferedReader * this = malloc ( sizeof ( struct BufferedReader ) ) ; 
    this->in = in ; 
    this->line = NULL ; 
    this->line_len = 0 ; 
    this->line_cap = 0 ; 
    return this ; 
} 

void BufferedReader_free ( struct BufferedReader * this ) { 
    free ( this->line ) ; 
    free ( this ) ; 
} 

char * BufferedReader_readLine ( struct BufferedReader * this ) { 
    // Read a single line of input from the user
    char c ; 
    int i = 0 ; 
    while ( ( c = fgetc ( this->in ) ) != EOF && c != '\n' ) { 
        if ( i == this->line_cap ) { 
            this->line_cap += 100 ; 
            this->line = realloc ( this->line , this->line_cap ) ; 
        } 
        this->line [ i ] = c ; 
        i++ ; 
    } 
    this->line [ i ] = '\0' ; 
    this->line_len = i ; 
    return this->line ; 
} 

