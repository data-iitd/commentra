
int N;
scanf("%d", &N);  // Take an integer input N, which represents the number of elements.
double x[N];
for (int i = 0; i < N; i++) {
    char s[100];
    scanf("%s", s);
    if (strcmp(s, "JPY") == 0) {
        x[i] = 1.0;
    } else if (strcmp(s, "BTC") == 0) {
        x[i] = 380000.0;
    } else {
        x[i] = atof(s);
    }
}
double sum = 0.0;
for (int i = 0; i < N; i++) {
    sum += x[i];
}
printf("%.2f\n", sum);  // Print the sum of the elements in the array x.



