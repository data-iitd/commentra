#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <map> 

using namespace std; 

int main() { 
    // Initialize variables
    int m, s, f, maxT = -1; 
    map<int, vector<int>> map; 
    string input, mth; 
    char M; 
    int k, a, b, d, cur; 
    string actions; 
    
    // Read the first line of input and split it into an array
    getline(cin, input); 
    stringstream ss(input); 
    ss >> m >> s >> f; 
    
    // Read the movements for each time step
    while (m--) { 
        // Read the movement data for the current time step
        getline(cin, mth); 
        stringstream ss2(mth); 
        ss2 >> k >> a >> b; 
        
        // Initialize the list for the current time step and add the movement range
        map[k] = vector<int>(2); 
        map[k][0] = a; 
        map[k][1] = b; 
        
        // Update maxT to the highest time step encountered
        maxT = max(maxT, k); 
    } 
    
    // Determine the direction of movement based on start and final positions
    M = (s < f) ? 'R' : 'L'; 
    d = (s < f) ? +1 : -1; 
    
    // Initialize current position to start position
    cur = s; 
    
    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) { 
        // Check if there are movements defined for the current time step
        if (map.find(t) != map.end()) { 
            a = map[t][0]; // Get the start of the movement range
            b = map[t][1]; // Get the end of the movement range
        } 
        
        // Check if the current position or the next position is within the movement range
        if (map.find(t) != map.end() && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) { 
            actions += 'X'; // Append 'X' if within the range
        } else { 
            actions += M; // Append the movement direction
            cur += d; // Update the current position
        } 
        
        // Break the loop if the current position reaches the final position
        if (cur == f) break; 
    } 
    
    // Continue moving until the current position reaches the final position
    while (cur != f) { 
        actions += M; // Append the movement direction
        cur += d; // Update the current position
    } 
    
    // Output the sequence of actions taken
    cout << actions << endl; 
    
    return 0; 
} 

