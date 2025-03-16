
int n;

printf("Enter an integer: ");
scanf("%d", &n);

while (n % 2 == 0) {
    n /= 2;
}

if (n == 1) {
    printf("YES\n");
} else {
    printf("NO\n");
}

