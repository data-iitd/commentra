
int n, i, j;

printf("Enter an integer: ");
scanf("%d", &n);

i = 1;
j = n * n;

while (i < j) {
    printf("%d %d\n", i, j);
    i++;
    j--;
}

printf("