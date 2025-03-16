
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <time.h> 
#include <assert.h> 
#include <vector> 
#include <map> 
#include <queue> 
#include <set> 
#include <string> 
#include <algorithm> 
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <unordered_set> 

typedef long long ll; 
typedef unsigned long long llu; 
typedef long double ld; 
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define repm(i,m) for(int i=0;i<m;i++)
#define all(c) c.begin(),c.end()

using namespace std; 

int main() { 
    // Create a Scanner object for input and PrintWriter for output
    Scanner in = new Scanner(System.in); 
    PrintWriter pw = new PrintWriter(System.out); 

    // Read the number of elements
    int n = in.nextInt(); 

    // Initialize an array to store the elements
    int ara[n]; 

    // Create a map to count the frequency of each element
    unordered_map<int, int> map; 

    // Read elements and populate the frequency map
    for (int i = 0; i < n; i++) { 
        int v = in.nextInt(); 
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
    unordered_map<int, int> mm; 

    // Iterate through the original array to find the first element with maximum frequency
    for (int i = 0; i < n; i++) { 
        if (mm.find(ara[i]) == mm.end()) { 
            mm[ara[i]] = 1; 
            // Check if the current element's frequency matches the maximum frequency
            if (mm[ara[i]] == max) { 
                pw.println(ara[i]); 
                break; 
            } 
        } else { 
            // Increment the count for the existing element
            mm[ara[i]]++; 
            // Check if the current element's frequency matches the maximum frequency
            if (mm[ara[i]] == max) { 
                pw.println(ara[i]); 
                break; 
            } 
        } 
    } 

    // Close the PrintWriter
    pw.close(); 
} 

// Debugging method to print objects
void debug(Object... obj) { 
    System.err.println(Arrays.deepToString(obj)); 
} 

