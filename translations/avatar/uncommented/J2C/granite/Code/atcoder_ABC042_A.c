
#include <stdio.h>
#include <string.h>

int main() {
char line[100];
fgets(line, sizeof(line), stdin);
char *list[3];
char *token = strtok(line, " ");
int i = 0;
while (token!= NULL) {
list[i++] = token;
token = strtok(NULL, " ");
}
int x = atoi(list[0]);
int a = atoi(list[1]);
int y = atoi(list[2]);
char h[] = "NO";
if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
if (x + y + a == 17) {
h[0] = 'Y';
h[1] = 'E';
h[2] = 'S';
}
}
printf("%s\n", h);
return 0;
}
// END-OF-CODE