
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    // Initialize input and output streams
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false); 
    
    // Create a Scanner object for reading input and a PrintWriter for output
    string s; 
    cin >> s; 
    
    // Create an instance of the AStationAndBus class to solve the problem
    AStationAndBus solver; 
    
    // Call the solve method with test number 1, passing the input and output objects
    solver.solve(1, s); 
    
    // Close the PrintWriter to flush the output
    return 0; 
} 

// Static inner class to handle the logic of the problem
class AStationAndBus { 
public: 
    void solve(int testNumber, string s) { 
        // Check if the string contains both 'A' and 'B'
        if (s.find('A') != string::npos && s.find('B') != string::npos) { 
            // If both characters are present, print "Yes"
            cout << "Yes" << endl; 
        } else { 
            // If either character is missing, print "No"
            cout << "No" << endl; 
        } 
    } 
}; 

