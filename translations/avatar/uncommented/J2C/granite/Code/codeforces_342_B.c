
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    fgets(input, 1000, stdin);
    char *token = strtok(input, " ");
    int m = atoi(token);
    token = strtok(NULL, " ");
    int s = atoi(token);
    token =...