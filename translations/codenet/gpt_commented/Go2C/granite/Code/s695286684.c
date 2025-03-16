
#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declare a character array's' to hold the input string

    // Read a string input from the user and store it in the character array's'
    scanf("%s", s);

    // Replace all occurrences of "2017" with "2018" in the input string and print the result
    printf("%s\n", str_replace("2017", "2018", s));

    return 0;
}

// Function to replace all occurrences of a substring with another substring in a given string
char* str_replace(const char* search, const char* replace, const char* subject) {
    char* result; // Pointer to the result string
    char* tok; // Pointer to the current token in the subject string

    // Allocate memory for the result string
    result = (char*)malloc(strlen(subject) + 1);

    // Copy the subject string to the result string
    strcpy(result, subject);

    // Tokenize the subject string using the search string as the delimiter
    tok = strtok(result, search);

    // Replace each occurrence of the search string with the replace string
    while (tok!= NULL) {
        tok = strreplace(tok, search, replace);
        tok = strtok(NULL, search);
    }

    return result;
}

// Function to replace a substring with another substring in a given string
char* strreplace(char* str, const char* search, const char* replace) {
    char* p; // Pointer to the current position in the string

    // Find the first occurrence of the search string in the string
    p = strstr(str, search);

    // If the search string is found, replace it with the replace string
    if (p!= NULL) {
        strncpy(p, replace, strlen(replace));
    }

    return str;
}

// End of code
