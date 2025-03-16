
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char line[100];
char *token;
int i = 0;
int Sheep, Wolve;

while (fgets(line, sizeof(line), stdin)) {
token = strtok(line, " ");
Sheep = atoi(token);
token = strtok(NULL, " ");
Wolve = atoi(token);

if (Wolve >= Sheep) {
printf("unsafe\n");
} else {
printf("safe\n");
}
}

return 0;
}

