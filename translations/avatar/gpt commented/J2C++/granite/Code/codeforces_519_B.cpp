
#include <iostream> 
#include <vector> 
using namespace std; 

int main() { 
    // Create a vector to store the input integers
    vector<int> v; 
    
    // Read the number of elements to be processed
    int n; 
    cin >> n; 
    
    // Read n integers and store them in the vector
    for (int i = 0; i < n; i++) { 
        int num; 
        cin >> num; 
        v.push_back(num); 
    } 
    
    // Calculate the sum of the first n integers
    int a = 0; 
    for (int i = 0; i < n; i++) 
        a += v[i]; 
    
    // Calculate the sum of the first n-1 integers
    int b = 0; 
    for (int i = 0; i < n - 1; i++) 
        b += v[i]; 
    
    // Calculate the sum of the first n-2 integers
    int c = 0; 
    for (int i = 0; i < n - 2; i++) 
        c += v[i]; 
    
    // Calculate the difference between the sums: x = sum of first set - sum of second set
    int x = a - b; 
    
    // Calculate the difference between the sums: y = sum of second set - sum of third set
    int y = b - c; 
    
    // Print the results of the differences
    cout << x << endl; 
    cout << y << endl; 
    
    return 0; 
}
