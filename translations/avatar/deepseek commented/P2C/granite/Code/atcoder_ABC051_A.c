

#include <stdio.h>

int main() {
 char input[100];
 printf("Enter a string: ");
 fgets(input, 100, stdin);
 printf("Input string after replacing ',' with'': %s", strreplace(input, ',',''));
 return 0;
}

char* strreplace(char* str, char find, char replace) {
 int i;
 for (i = 0; str[i]!= '\0'; i++) {
 if (str[i] == find) {
 str[i] = replace;
 }
 }
 return str;
}

