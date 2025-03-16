#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// Function to calculate (x^n) % mod using recursion
long power(long x, long n) { 
    // Base case: x^0 = 1
    if (n == 0) { 
        return 1; 
    } 
    
    // Define a modulus value for calculations
    int mod = 1000000007; 
    
    // Recursively calculate power
    long val = power(x, n / 2); 
    
    // Square the result and take modulus
    val = val * val % mod; 
    
    // If n is odd, multiply by x and take modulus
    if (n % 2 == 1) { 
        val = val * x % mod; 
    } 
    
    // Return the final result
    return val; 
} 

int main() { 
    // Create a BufferedReader to read input from the console
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    
    // Read the first line of input and split it into an array of strings
    String[] sa = br.readLine().split(" "); 
    
    // Parse the first element as an integer 'n'
    int n = Integer.parseInt(sa[0]); 
    
    // Read the second line of input and split it into an array of strings
    sa = br.readLine().split(" "); 
    
    // Initialize an integer array 'c' of size 'n'
    int[] c = new int[n]; 
    
    // Populate the array 'c' with integers from the input
    for (int i = 0; i < n; i++) { 
        c[i] = Integer.parseInt(sa[i]); 
    } 
    
    // Close the BufferedReader
    br.close(); 
    
    // Define a modulus value for calculations
    int mod = 1000000007; 
    
    // If there is only one element, calculate and print the result directly
    if (n == 1) { 
        System.out.println(c[0] * 2 % mod); 
        return 0; 
    } 
    
    // Sort the array 'c' in parallel
    Arrays.parallelSort(c); 
    
    // Calculate powers of 2 for later use
    long b = power(2, n); 
    long a = power(2, n - 2); 
    
    // Initialize the answer variable
    long ans = 0; 
    
    // Calculate the final answer using a loop
    for (int i = 2; i <= n + 1; i++) { 
        // Calculate the value for the current iteration
        long val = a * i % mod; 
        val *= c[n + 1 - i]; 
        val %= mod; 
        
        // Accumulate the result
        ans += val; 
        ans %= mod; 
    } 
    
    // Multiply the accumulated answer by 'b' and take modulus
    ans *= b; 
    ans %= mod; 
    
    // Print the final result
    System.out.println(ans); 
    
    // End of code
    return 0; 
} 


