

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  // Take an integer input N, which represents the number of elements.
    double x[N];
    for (int i = 0; i < N; i++) {
        char s[100];
        scanf("%s", s);
        if (strstr(s, "JPY")) {
            sscanf(s, "%*s %lf", &x[i]);
            x[i] *= 1.0;
        } else if (strstr(s, "BTC")) {
            sscanf(s, "%*s %lf", &x[i]);
            x[i] *= 380000.0;
        }
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    printf("%.2lf\n", sum);  // Print the sum of the elements in the list x.
    return 0;
}



Translate the above C code to Java and end with comment "