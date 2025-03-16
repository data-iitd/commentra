#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);  // Take an integer input N, which represents the number of elements.
    
    double total = 0.0;  // Initialize a variable to hold the total sum.
    
    for (int i = 0; i < N; i++) {
        char input[100];  // Buffer to hold the input string.
        scanf("%s", input);  // Read the input string.
        
        double value = 0.0;  // Variable to hold the evaluated value.
        
        // Check if the input contains "JPY"
        if (strstr(input, "JPY") != NULL) {
            // Replace "JPY" with an empty string and convert to double
            char *jpy = strtok(input, "JPY");
            value = atof(jpy);
        }
        // Check if the input contains "BTC"
        else if (strstr(input, "BTC") != NULL) {
            // Replace "BTC" with an empty string and convert to double
            char *btc = strtok(input, "BTC");
            value = atof(btc) * 380000.0;  // Convert BTC to JPY
        }
        
        total += value;  // Add the evaluated value to the total.
    }
    
    printf("%lf\n", total);  // Print the sum of the elements.
    
    return 0;
}  // <END-OF-CODE>
