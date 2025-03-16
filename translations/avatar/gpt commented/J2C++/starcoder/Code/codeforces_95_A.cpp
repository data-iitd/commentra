#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cassert>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <numeric>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <cstdlib>
using namespace std;

// Constructor for the Main class
Main() { 
    super(System.out, true); 
} 

// Scanner object to read input
Scanner sc = new Scanner(System.in); 

int main(int argc, char *argv[]) { 
    // Create an instance of Main and invoke the main logic
    Main o = new Main(); 
    o.main(); 
    o.flush(); 
} 

// Method to compare two character arrays with case insensitivity
int compare(char[] aa, int i, char[] bb, int j, int m) { 
    while (m-- > 0) { 
        // Convert characters to uppercase for comparison
        char a = toupper(aa[i]); 
        char b = toupper(bb[j]); 
        // Return the difference if characters do not match
        if (a!= b) return a - b; 
        i++; 
        j++; 
    } 
    // Return 0 if all characters match
    return 0; 
} 

void main() { 
    // Read the number of strings
    int n = sc.nextInt(); 
    char ss[n][]; 
    
    // Read each string and convert it to a character array
    for (int i = 0; i < n; i++) 
        ss[i] = sc.next().toCharArray(); 
    
    // Read the character array to be modified
    char cc[sc.nextInt()]; 
    int m = cc.length; 
    
    // Read the character to be replaced
    char c = sc.next().charAt(0); 
    char c_ = toupper(c); 
    
    // Determine the character to replace with
    char a = c == 'a'? 'b' : 'a'; 
    char a_ = toupper(a); 
    
    // Array to track positions that can be marked as lucky
    bool lucky[m]; 
    
    // Loop through each position in the character array
    for (int j = 0; j < m; j++) 
        for (int i = 0; i < n; i++) { 
            int l = ss[i].length; 
            // Check if the substring matches and mark lucky positions
            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) 
                for (int h = 0; h < l; h++) 
                    lucky[j + h] = true; 
        } 
    
    // Replace characters in the original array based on lucky positions
    for (int j = 0; j < m; j++) 
        if (lucky[j]) { 
            // Replace with the determined character based on case
            if (tolower(cc[j]) == c) 
                cc[j] = isupper(cc[j])? a_ : a; 
            else 
                cc[j] = isupper(cc[j])? c_ : c; 
        } 
    
    // Print the modified character array
    printf("%s\n", cc); 
}

