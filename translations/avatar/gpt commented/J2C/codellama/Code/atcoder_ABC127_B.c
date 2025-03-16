#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#define BUFFER_SIZE 10240 

typedef struct { 
    FILE *in; 
    char buffer[BUFFER_SIZE]; 
    int buffer_size; 
    int buffer_pos; 
    int eof; 
} SimpleScanner; 

SimpleScanner *SimpleScanner_new(FILE *in) { 
    SimpleScanner *scanner = malloc(sizeof(SimpleScanner)); 
    scanner->in = in; 
    scanner->buffer_size = 0; 
    scanner->buffer_pos = 0; 
    scanner->eof = 0; 
    return scanner; 
} 

void SimpleScanner_delete(SimpleScanner *scanner) { 
    free(scanner); 
} 

char SimpleScanner_read(SimpleScanner *scanner) { 
    if (scanner->buffer_pos >= scanner->buffer_size) { 
        scanner->buffer_size = fread(scanner->buffer, 1, BUFFER_SIZE, scanner->in); 
        scanner->buffer_pos = 0; 
        if (scanner->buffer_size == 0) { 
            scanner->eof = 1; 
            return '\0'; 
        } 
    } 
    return scanner->buffer[scanner->buffer_pos++]; 
} 

void SimpleScanner_checkEof(SimpleScanner *scanner) { 
    if (scanner->eof) { 
        fprintf(stderr, "Error: Unexpected end of input\n"); 
        exit(1); 
    } 
} 

char SimpleScanner_nextChar(SimpleScanner *scanner) { 
    SimpleScanner_checkEof(scanner); 
    char b = SimpleScanner_read(scanner); 
    SimpleScanner_checkEof(scanner); 
    return b; 
} 

char *SimpleScanner_next(SimpleScanner *scanner) { 
    char b; 
    // Skip any whitespace characters
    do { 
        b = SimpleScanner_read(scanner); 
        SimpleScanner_checkEof(scanner); 
    } while (isspace(b)); 
    
    char *sb = malloc(BUFFER_SIZE); 
    int sb_size = 0; 
    // Append characters until a whitespace or EOF is encountered
    do { 
        sb[sb_size++] = b; 
        b = SimpleScanner_read(scanner); 
    } while (!scanner->eof && !isspace(b)); 
    
    sb[sb_size] = '\0'; 
    return sb; 
} 

int SimpleScanner_nextInt(SimpleScanner *scanner) { 
    return atoi(SimpleScanner_next(scanner)); 
} 

long SimpleScanner_nextLong(SimpleScanner *scanner) { 
    return atol(SimpleScanner_next(scanner)); 
} 

double SimpleScanner_nextDouble(SimpleScanner *scanner) { 
    return atof(SimpleScanner_next(scanner)); 
} 

int main(int argc, char *argv[]) { 
    // Create a SimpleScanner instance to read input from the standard input stream
    SimpleScanner *scanner = SimpleScanner_new(stdin); 
    
    // Create a PrintWriter instance to output results to the standard output stream
    FILE *out = stdout; 
    
    // Read integer values for r and d, and a long value for x from the input
    int r = SimpleScanner_nextInt(scanner); 
    int d = SimpleScanner_nextInt(scanner); 
    long x = SimpleScanner_nextLong(scanner); 
    
    // Perform the calculation and output the result 10 times
    for (int i = 0; i < 10; ++i) { 
        // Update x according to the formula x = r * x - d
        x = r * x - d; 
        // Print the updated value of x
        fprintf(out, "%ld\n", x); 
    } 
    
    // Close the PrintWriter to release resources
    fclose(out); 
    
    // Free the SimpleScanner instance
    SimpleScanner_delete(scanner); 
    
    return 0; 
} 

