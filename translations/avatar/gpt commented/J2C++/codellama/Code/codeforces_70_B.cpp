#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    // Read the maximum allowed length of messages
    int n; 
    cin >> n; 
    
    // Read the input string containing messages
    string input; 
    getline(cin, input); 
    
    // Initialize variables to track the maximum message length and store lengths of individual messages
    int max = -1; 
    int* msgLength = new int[input.length() / 2]; 
    int count = 0; 
    int idx = 0; 
    
    // Iterate through each character in the input string
    for (int i = 0; i < input.length(); i++) { 
        char c = input[i]; 
        
        // Check if the character is a message delimiter (., ?, or !)
        if (c == '.' || c == '?' || c == '!') { 
            // Store the length of the current message and update the maximum length if necessary
            msgLength[idx++] = ++count; 
            if (count > max) max = count; 
            
            // Move to the next character after the delimiter
            i++; 
            count = 0; // Reset count for the next message
        } else {
            // Increment the count for the current message length
            count++; 
        } 
    } 
    
    // Check if the maximum message length exceeds the allowed length
    if (max > n) 
        cout << "Impossible"; 
    else { 
        // Calculate the number of messages that can fit within the allowed length
        int ans = 0; 
        for (int i = 0; i < idx; i++) { 
            int l = msgLength[i]; 
            
            // Combine consecutive messages if they fit within the allowed length
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) { 
                l += msgLength[i + 1] + 1; 
                i++; 
            } 
            ans++; // Increment the count of messages
        } 
        // Output the total number of messages that can be sent
        cout << ans; 
    } 
    
    return 0; 
} 

