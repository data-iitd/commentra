#include <iostream> 
#include <vector> 

using namespace std; 

int main() { 
    // Create a Scanner object for input and a PrintWriter for output
    int n; 
    cin >> n; 
    int square = n * n; 
    
    // Initialize ArrayLists to hold odd and even numbers
    vector<int> odd; 
    vector<int> even; 
    
    // Populate the odd and even ArrayLists with numbers from 1 to square
    for (int i = 1; i <= square; i++) { 
        if (i % 2 == 0) { 
            even.push_back(i); // Add to even list if the number is even
        } else { 
            odd.push_back(i); // Add to odd list if the number is odd
        } 
    } 
    
    // Calculate the number of loops and the division for pairing
    int loop = square / n; 
    int div = loop / 2; 
    
    // Debug output to check the value of div
    debug(div); 
    
    // Loop through the number of rows to print the pairs
    for (int i = 1; i <= loop; i++) { 
        // For each row, print div pairs of numbers
        for (int j = 0; j < div; j++) { 
            // Alternate between odd and even pairs based on the row number
            if (i % 2 == 1) { 
                // For odd rows, print an odd number and the last even number
                cout << odd[0] << " " << even[even.size() - 1] << " "; 
                odd.erase(odd.begin()); 
                even.erase(even.end() - 1); 
            } else { 
                // For even rows, print an even number and the last odd number
                cout << even[0] << " " << odd[odd.size() - 1] << " "; 
                even.erase(even.begin()); 
                odd.erase(odd.end() - 1); 
            } 
        } 
        // Move to the next line after printing pairs for the current row
        cout << endl; 
    } 
    
    // Close the PrintWriter to flush the output
    // pw.close(); 
    
    return 0; 
} 

// Debug method to print the contents of the passed objects
void debug(int div) { 
    cout << div << endl; 
} 

