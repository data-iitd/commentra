
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int main() { 
    // Set up input and output streams
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    // Read the number of strings
    int n; 
    cin >> n; 
    // Initialize an array to count occurrences of specific starting letters
    vector<long> cnt(5, 0); 
    
    // Process each string input
    for (int i = 0; i < n; ++i) { 
        string str; 
        cin >> str; 
        // Increment the count based on the first character of the string
        if (str[0] == 'M') { 
            cnt[0]++; 
        } else if (str[0] == 'A') { 
            cnt[1]++; 
        } else if (str[0] == 'R') { 
            cnt[2]++; 
        } else if (str[0] == 'C') { 
            cnt[3]++; 
        } else if (str[0] == 'H') { 
            cnt[4]++; 
        } 
    } 
    
    // Calculate the result based on combinations of counts
    long res = cnt[0] * cnt[1] * cnt[2] + 
               cnt[0] * cnt[1] * cnt[3] + 
               cnt[0] * cnt[1] * cnt[4] + 
               cnt[0] * cnt[2] * cnt[3] + 
               cnt[0] * cnt[2] * cnt[4] + 
               cnt[0] * cnt[3] * cnt[4] + 
               cnt[1] * cnt[2] * cnt[3] + 
               cnt[1] * cnt[2] * cnt[4] + 
               cnt[1] * cnt[3] * cnt[4] + 
               cnt[2] * cnt[3] * cnt[4]; 
    
    // Output the result
    cout << res << endl; 
    
    return 0; 
} 

