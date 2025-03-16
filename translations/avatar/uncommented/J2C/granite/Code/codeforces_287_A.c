
#include <stdio.h>
#include <string.h>

int main() {
char str[4][2];
int i, j, yes = 0;

for (i = 0; i < 4; i++) {
gets(str[i]);
}

for (i = 0; i < 2; i++) {
for (j = 0; j < 2; j++) {
if ((str[i][j] == str[i][j+1]) && ((str[i+1][j] == str[i][j]) || (str[i+1][j+1] == str[i][j]))) {
yes = 1;
printf("YES\n");
goto end;
} else if ((str[i+1][j] == str[i+1][j+1]) && ((str[i][j] == str[i+1][j]) || (str[i][j+1] == str[i+1][j]))) {
yes = 1;
printf("YES\n");
goto end;
}
}
}

end:
if (yes == 0) {
printf("NO\n");
}

return 0;
}

