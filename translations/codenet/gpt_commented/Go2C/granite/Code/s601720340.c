
#include <stdio.h>
#include <stdlib.h>

// Define the Io struct and its methods
typedef struct {
    FILE *reader;
    FILE *writer;
    char **tokens;
    int nextToken;
} Io;

Io* NewIo() {
    Io *io = (Io*)malloc(sizeof(Io));
    io->reader = stdin;
    io->writer = stdout;
    io->tokens = NULL;
    io->nextToken = 0;
    return io;
}

void FlushIo(Io *io) {
    fflush(io->writer); // Flush the writer buffer
}

char* NextLineIo(Io *io) {
    char *buffer = (char*)malloc(sizeof(char) * 1000000); // Allocate buffer with a large capacity
    int len = 0;
    while (1) {
        char line[1000000]; // Define a line buffer
        len = fgets(line, 1000000, io->reader); // Read a line
        if (len == 0) {
            break; // Break if end of file is reached
        }
        int i = 0;
        while (line[i]!= '\n') {
            i++; // Count the number of characters in the line
        }
        char *tokens = (char*)malloc(sizeof(char) * i); // Allocate memory for tokens
        memcpy(tokens, line, i); // Copy the line to the token buffer
        io->tokens = tokens; // Set the token buffer
        io->nextToken = 0; // Reset token index
        break; // Break the loop
    }
    return tokens; // Return the token buffer
}

char* NextIo(Io *io) {
    if (io->nextToken >= io->tokens) {
        char *line = NextLineIo(io); // Read the next line
        io->tokens = strsep(line, " "); // Split the line into tokens
        io->nextToken = 0; // Reset token index
    }
    return io->tokens[io->nextToken++]; // Get the next token
}

int NextIntIo(Io *io) {
    char *token = NextIo(io); // Get the next token
    int value = atoi(token); // Convert the token to int
    return value; // Return the int value
}

float NextFloatIo(Io *io) {
    char *token = NextIo(io); // Get the next token
    float value = atof(token); // Convert the token to float64
    return value; // Return the float value
}

void PrintLnIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    va_start(args, "l") // Initialize the variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    va_start(args, "l") // Initialize the variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintIntLnIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

void PrintfIo(Io *io,...) {
    va_list args; // Define a variable-length argument list
    for (int i = 0; i < 100; i++) {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        io.NextInt() // Get the next int
        if io.NextInt() {
            io.PrintIntLn(io,...) {
                va_list args; // Define a variable-length argument list
                for (int i = 0; i < 100; i++) {
                    va_end(args) // End the variable-length argument list
                    Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
    }
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
		Printf("Hello, World!") // Print a message
	}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}


func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!) // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!) // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!) // Print a message
	}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!) // Print a message
}
}

func main() {
    var io = NewIo() // Create a new Io instance
    for {
        va_end(args) // End the variable-length argument list
        Printf("Hello, World!") // Print a message
	}
}

func main() {
    var io = 