
#include <stdio.h>
#include <string.h>

int main() {
char n[1000];
gets(n);
int len = strlen(n);
int i;
int s = 0;
for (i = 0; i < len; i++) {
if (n[i] == '.') {
if (s) {
printf("1");
s = 0;
} else {
printf("0");
}
} else {
if (s) {
printf("2");
s = 0;
} else {
s = 1;
}
}
}
return 0;
}
//END-OF-CODE


