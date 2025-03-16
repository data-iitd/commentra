#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool debug = false;

void log(char *text) {
    if (debug) {
        printf("%s\n", text);
    }
}

char* parse_input(char* lines_as_string) {
    char* lines[100];
    int line_count = 0;
    char* token;

    if (lines_as_string == NULL) {
        debug = false;
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        lines[line_count++] = strdup(buffer);
    } else {
        debug = true;
        char* lines_copy = strdup(lines_as_string);
        token = strtok(lines_copy, "\n");
        while (token != NULL) {
            lines[line_count++] = token;
            token = strtok(NULL, "\n");
        }
        free(lines_copy);
    }

    char* c = strtok(lines[0], " ");
    return c;
}

char solve(char c) {
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == c) {
            break;
        }
        i++;
    }
    if (a[i + 1] != '\0') {
        return a[i + 1];
    } else {
        return '\0';
    }
}

int main() {
    char* input_line = NULL;
    size_t len = 0;
    getline(&input_line, &len, stdin);
    char* c = parse_input(input_line);
    char result = solve(c[0]);
    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("No next character\n");
    }
    free(input_line);
    return 0;
}
