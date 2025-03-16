#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double convert_to_usd(const char *input) {
    double value;
    char currency[4]; // To hold the currency type (JPY or BTC)
    
    // Scan the input to separate the value and currency
    sscanf(input, "%lf %3s", &value, currency);
    
    // Convert based on currency type
    if (strcmp(currency, "JPY") == 0) {
        return value; // JPY to USD (1.0)
    } else if (strcmp(currency, "BTC") == 0) {
        return value * 380000.0; // BTC to USD
    }
    
    return 0.0; // Default case (should not happen)
}

int main() {
    int N;
    scanf("%d", &N);
    double total = 0.0;
    
    for (int i = 0; i < N; i++) {
        char input[50]; // Buffer to hold the input string
        scanf("%s", input);
        total += convert_to_usd(input);
    }
    
    printf("%lf\n", total);
    return 0;
}

// <END-OF-CODE>
