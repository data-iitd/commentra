
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    int num; 
    cin >> num; 
    
    // Initialize counters for occurrences of 'C' and the total fine
    int counter = 0; 
    int fine = 0; 
    
    // Create an ArrayList to store the input strings
    vector<string> arr; 
    
    // Read 'num' strings from input and add them to the ArrayList
    for (int i = 0; i < num; i++) { 
        string s; 
        cin >> s; 
        arr.push_back(s); 
    } 
    
    // Calculate fines based on occurrences of 'C' in each column
    for (int i = 0; i < num; i++) { 
        for (int k = 0; k < num; k++) { 
            // Count occurrences of 'C' in the current column
            if (arr[k][i] == 'C') { 
                counter++; 
            } 
        } 
        // Update the fine based on the number of 'C's found in this column
        fine += (counter * (counter - 1)) / 2; 
        // Reset counter for the next column
        counter = 0; 
    } 
    
    // Calculate fines based on occurrences of 'C' in each row
    for (int i = 0; i < num; i++) { 
        for (int k = 0; k < num; k++) { 
            // Count occurrences of 'C' in the current row
            if (arr[i][k] == 'C') { 
                counter++; 
            } 
        } 
        // Update the fine based on the number of 'C's found in this row
        fine += (counter * (counter - 1)) / 2; 
        // Reset counter for the next row
        counter = 0; 
    } 
    
    // Output the total fine calculated
    cout << fine << endl; 
    
    return 0; 
} 

