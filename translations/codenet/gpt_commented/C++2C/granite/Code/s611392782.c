
// ACM-ICPCアジア地区予選2014 B. Miscalculation

#include <stdio.h>
#include <string.h>

char str[1000001]; // String to hold the expression
int d; // Variable to hold the expected result

// Function to perform multiplication based on the custom operator '*' in the string
int mul(int idx){
    // Initialize result with the first digit
    int res = str[idx]-'0';
    // Loop through the string to find '*' operators and perform multiplication
    while(idx+1 < strlen(str) && str[idx+1]=='*'){
        idx += 2; // Move index to the next number after '*'
        res *= str[idx]-'0'; // Multiply the result with the next number
    }
    return res; // Return the final multiplication result
}

// Function to perform addition based on the custom operator '+' in the string
int add(int idx){
    // Start with the first multiplication result
    int res = mul(idx);
    // Loop through the string to find '+' operators and perform addition
    while(idx+1 < strlen(str) && str[idx+1] == '+'){
        idx += 2; // Move index to the next number after '+'
        res += mul(idx); // Add the next multiplication result to the total
    }
    return res; // Return the final addition result
}

// Function to calculate the result based on Bob's interpretation of the expression
int bob(int idx){
    // Initialize result with the first digit
    int res = str[idx]-'0';
    // Loop through the string to evaluate the expression according to Bob's rules
    while(idx+1 < strlen(str)){
        // Check if the next operator is '+' or '*' and perform the corresponding operation
        if(str[idx+1] == '+') 
            res += str[idx+2]-'0'; // Add the next number
        else                  
            res *= str[idx+2]-'0'; // Multiply by the next number
        idx += 2; // Move index to the next operator
    }
    return res; // Return the final result according to Bob's interpretation
}

int main(){
    // Read input until end of file
    while(scanf("%s %d", str, &d)!= EOF){
        int idx = 0; // Initialize index for parsing the string
        int a = add(idx); // Calculate the result using the addition function
        idx = 0; // Reset index for Bob's calculation
        int b = bob(idx); // Calculate the result using Bob's interpretation
        // Compare results and print the corresponding output
        if(a == d){
            printf("%c\n", (b == d? 'U' : 'M')); // Output 'U' if both are equal, else 'M'
        } else {
            printf("%c\n", (b == d? 'L' : 'I')); // Output 'L' if Bob's result is equal, else 'I'
        }
    }
}
