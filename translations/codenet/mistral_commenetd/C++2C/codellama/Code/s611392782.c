// ACM-ICPCアジア地区予選2014 B. Miscalculation

#include <stdio.h>
#include <string.h>

// Function to calculate the multiplication part of the expression
int mul(const char* str, int* idx){
    int res = str[*idx]-'0'; // Extract the first digit and store it in 'res'
    while(*idx+1 < strlen(str) && str[*idx+1]=='*'){ // Check if there is a '*' symbol
        *idx += 2; // Move the index to the next symbol
        res *= str[*idx]-'0'; // Multiply 'res' with the next digit
    }
    return res; // Return the final result
}

// Function to calculate the addition part of the expression
int add(const char* str, int* idx){
    int res = mul(str, idx); // Call the 'mul' function to calculate the multiplication part
    while(*idx+1 < strlen(str) && str[*idx+1] == '+'){ // Check if there is a '+' symbol
        *idx += 2; // Move the index to the next symbol
        res += mul(str, idx); // Add the result of the next multiplication part
    }
    return res; // Return the final result
}

// Function to calculate the whole expression
int bob(const char* str, int* idx){
    int res = str[*idx]-'0'; // Extract the first digit and store it in 'res'
    while(*idx+1 < strlen(str)){ // Loop through the rest of the expression
        if(str[*idx+1] == '+') res += str[*idx+2]-'0'; // If there is a '+' symbol, add the next digit
        else                  res *= str[*idx+2]-'0'; // If there is a '*' symbol, multiply the next digit
        *idx += 2; // Move the index to the next symbol
    }
    return res; // Return the final result
}

int main(){
    char s[1000]; int d; // Declare two variables to store the input string and desired result
    while(scanf("%s %d", s, &d) == 2){ // Read the input string and desired result from the standard input
        int idx = 0; // Initialize the index to 0
        int a = add(s, &idx); // Call the 'add' function to calculate the addition part of the expression
        idx = 0; // Reset the index to 0
        int b = bob(s, &idx); // Call the 'bob' function to calculate the whole expression
        if(a == d){ // Check if the addition part matches the desired result
            printf("%c\n", b == d ? 'U' : 'M'); // If both parts match, print 'U', otherwise print 'M'
        } else { // If the addition part doesn't match, check if the whole expression matches
            printf("%c\n", b == d ? 'L' : 'I'); // If the whole expression matches, print 'L', otherwise print 'I'
        }
    }
}

