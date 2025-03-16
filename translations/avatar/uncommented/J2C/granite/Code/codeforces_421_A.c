
#include <stdio.h>
#include <stdlib.h>

int main() {
int n, a, b, i, j;
scanf("%d %d %d", &n, &a, &b);
int *arr1 = (int*)malloc(a * sizeof(int));
int *arr2 = (int*)malloc(b * sizeof(int));
for (i = 0; i < a; i++) {
scanf("%d", &arr1[i]);
}
for (i = 0; i < b; i++) {
scanf("%d", &arr2[i]);
}
for (i = 1; i <= n; i++) {
int flag = 0;
for (j = 0; j < a; j++) {
if (arr1[j] == i) {
flag = 1;
break;
}
}
if (flag == 1) {
printf("1 ");
} else {
printf("2 ");
}
}
printf("\n");
free(arr1);
free(arr2);
return 0;
}

