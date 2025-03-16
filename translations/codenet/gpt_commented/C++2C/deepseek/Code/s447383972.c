#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a long long integer from input
long long read(){   
    long long x=0, f=1; 
    char ch=getchar();   
    // Read characters until a digit or '-' is found
    while(ch<'0'||ch>'9'){ 
        if(ch=='-') f=-1; // Check for negative sign
        ch=getchar();
    }  
    // Convert the digits to a long long integer
    while(ch>='0'&&ch<='9'){ 
        x=x*10+ch-'0'; 
        ch=getchar();
    }  
    return x*f; // Return the final value with sign
} 

// Function to write a long long integer to output
void write(long long x){    
    if (x<0) putchar('-'), x=-x; // Print negative sign if needed
    if (x>=10) write(x/10);   // Recursively write the digits
    putchar(x%10+'0');  // Print the last digit
} 

// Function to write a long long integer followed by a newline
void writeln(long long x){ 
    write(x);   
    puts("");   // Print a newline
}

#define N 200010 // Define a constant for the maximum size of the array

int main(){
    long long a[N], q[N], n, tot = 0; // Declare arrays and variables
    n = read(); // Read the number of elements
    for(long long i = 1; i <= n; ++i) a[i] = read(); // Read the elements into the array a
    qsort(a + 1, n, sizeof(long long), (int (*)(const void *, const void *))compare); // Sort the array in non-decreasing order

    // Identify duplicates and store them in array q
    for(long long i = 1; i <= n; ++i) 
        if (a[i] == a[i+1]) 
            q[++tot] = a[i], i++; // Store the duplicate and skip the next element

    // Output the product of the last two duplicates found
    writeln(q[tot] * q[tot-1]);
}

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}
