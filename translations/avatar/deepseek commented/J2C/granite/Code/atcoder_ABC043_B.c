

#include <stdio.h>
#include <string.h>

int main() {
    // Step 1: Define the input stream and output stream
    FILE *inputStream = stdin;
    FILE *outputStream = stdout;
    
    // Step 2: Read the input string
    char s[100001];
    fgets(s, 100001, inputStream);
    
    // Step 3: Create a StringBuilder instance for building the result
    char d[100001];
    int len = 0;
    
    // Step 4: Iterate over each character in the input string
    for (int i = 0; s[i]!= '\0'; i++) {
        switch (s[i]) {
            case '0':
                // Append '0' to the result
                d[len++] = '0';
                break;
            case '1':
                // Append '1' to the result
                d[len++] = '1';
                break;
            case 'B':
                // Remove the last character if the result is not empty
                if (len > 0) {
                    len--;
                }
                break;
        }
    }
    
    // Step 5: Print the result
    d[len] = '\0';
    fprintf(outputStream, "%s\n", d);
    
    return 0;
}

