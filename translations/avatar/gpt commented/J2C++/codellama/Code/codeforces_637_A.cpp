#include <iostream> 
#include <map> 
#include <vector> 
using namespace std; 

int main() { 
    // Create a Scanner object for input and PrintWriter for output
    int n; 
    cin >> n; 
    vector<int> ara(n); 
    map<int, int> map; 
    for (int i = 0; i < n; i++) { 
        int v; 
        cin >> v; 
        ara[i] = v; 
        // If the element is not in the map, add it with a count of 1
        if (map.find(v) == map.end()) { 
            map[v] = 1; 
        } else { 
            // If it is already in the map, increment its count
            map[v]++; 
        } 
    } 
    
    // Find the maximum frequency among the elements
    int max = 0; 
    for (auto i : map) { 
        max = max(max, i.second); 
    } 
    
    // Create another map to track the order of elements while checking frequency
    map<int, int> mm; 
    
    // Iterate through the original array to find the first element with maximum frequency
    for (int i = 0; i < n; i++) { 
        if (mm.find(ara[i]) == mm.end()) { 
            mm[ara[i]] = 1; 
            // Check if the current element's frequency matches the maximum frequency
            if (mm[ara[i]] == max) { 
                cout << ara[i] << endl; 
                break; 
            } 
        } else { 
            // Increment the count for the existing element
            mm[ara[i]]++; 
            // Check if the current element's frequency matches the maximum frequency
            if (mm[ara[i]] == max) { 
                cout << ara[i] << endl; 
                break; 
            } 
        } 
    } 
    
    return 0; 
} 

// END-OF-CODE
