#include <iostream> 
#include <cstring> 
#include <cctype> 
using namespace std; 

int main() { 
    // Read the number of strings
    int n; 
    cin >> n; 
    char** ss = new char*[n]; 
    
    // Read each string and convert it to a character array
    for (int i = 0; i < n; i++) { 
        ss[i] = new char[100]; 
        cin >> ss[i]; 
    } 
    
    // Read the character array to be modified
    char* cc = new char[100]; 
    cin >> cc; 
    int m = strlen(cc); 
    
    // Read the character to be replaced
    char c; 
    cin >> c; 
    char c_ = toupper(c); 
    
    // Determine the character to replace with
    char a = c == 'a' ? 'b' : 'a'; 
    char a_ = toupper(a); 
    
    // Array to track positions that can be marked as lucky
    bool* lucky = new bool[m]; 
    
    // Loop through each position in the character array
    for (int j = 0; j < m; j++) 
        for (int i = 0; i < n; i++) { 
            int l = strlen(ss[i]); 
            // Check if the substring matches and mark lucky positions
            if (m - j >= l && strncmp(cc + j, ss[i], l) == 0) 
                for (int h = 0; h < l; h++) 
                    lucky[j + h] = true; 
        } 
    
    // Replace characters in the original array based on lucky positions
    for (int j = 0; j < m; j++) 
        if (lucky[j]) { 
            // Replace with the determined character based on case
            if (tolower(cc[j]) == c) 
                cc[j] = isupper(cc[j]) ? a_ : a; 
            else 
                cc[j] = isupper(cc[j]) ? c_ : c; 
        } 
    
    // Print the modified character array
    cout << cc << endl; 
    return 0; 
}

