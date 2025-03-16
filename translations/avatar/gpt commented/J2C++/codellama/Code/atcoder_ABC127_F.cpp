#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
#include <queue> 

using namespace std; 

// Output stream for printing results
ostream& outputStream = cout; 

int main() { 
    // BufferedReader to read input from standard input
    string line; 
    getline(cin, line); 
    
    // Read the number of test cases
    int t = stoi(line); 
    
    // Arrays and priority queues for processing input
    vector<string> s; 
    priority_queue<int> pqmax; // Min-heap for maximum values
    priority_queue<int, vector<int>, greater<int>> pqmin; // Max-heap for minimum values
    
    // Variables to store sums and minimum value
    long sumMin = 0, sumMax = 0, sumb = 0; 
    int min = 0; 
    
    // Process each test case
    while (t-- > 0) { 
        // Read the input line and split it into parts
        getline(cin, line); 
        stringstream ss(line); 
        s.clear(); 
        while (ss.good()) { 
            string substr; 
            getline(ss, substr, ' '); 
            s.push_back(substr); 
        } 
        
        // If the first character is '2', calculate and print the result
        if (s[0].at(0) == '2') { 
            long ans = min; 
            ans *= pqmin.size(); 
            ans -= sumMin; 
            long ans1 = min; 
            ans1 *= pqmax.size(); 
            ans1 = sumMax - ans1; 
            
            // Print the minimum value and the calculated result
            outputStream << min << " " << (ans + ans1 + sumb) << endl; 
        } else { 
            // Parse the input values
            int in = stoi(s[1]); 
            sumb += stol(s[2]); // Update the sum of additional values
            
            // Add the input value to the appropriate priority queue
            if (in > min) { 
                pqmax.push(in); 
                sumMax += in; 
            } else { 
                pqmin.push(in); 
                sumMin += in; 
            } 
            
            // Balance the two heaps if necessary
            if (pqmin.size() > pqmax.size()) { 
                sumMax += pqmin.top(); 
                sumMin -= pqmin.top(); 
                pqmax.push(pqmin.top()); 
                pqmin.pop(); 
            } 
            if (pqmin.size() < pqmax.size()) { 
                sumMax -= pqmax.top(); 
                sumMin += pqmax.top(); 
                pqmin.push(pqmax.top()); 
                pqmax.pop(); 
            } 
            
            // Update the minimum value based on the current state of the heaps
            min = pqmin.top(); 
        } 
    } 
    
    return 0; 
} 

