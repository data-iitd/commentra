#include <iostream> 
using namespace std; 

int main() 
{ 
    // Create a Scanner object to read input from the console
    int n;
    cin >> n; 
    
    // Read the number of elements to be processed
    int a = 0, b = 0, c = 0; 
    
    // Read n integers and calculate their sum (a)
    for (int i = 0; i < n; i++) 
        a += cin.nextInt(); 
    
    // Read n-1 integers and calculate their sum (b)
    for (int i = 0; i < n - 1; i++) 
        b += cin.nextInt(); 
    
    // Read n-2 integers and calculate their sum (c)
    for (int i = 0; i < n - 2; i++) 
        c += cin.nextInt(); 
    
    // Calculate the difference between the sums: x = sum of first set - sum of second set
    int x = a - b; 
    
    // Calculate the difference between the sums: y = sum of second set - sum of third set
    int y = b - c; 
    
    // Print the results of the differences
    cout << x << endl; 
    cout << y << endl; 
    
    return 0; 
} 

