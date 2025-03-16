
#include <bits/stdc++.h> 
using namespace std; 

// FastReader class to handle fast input
class FastReader { 
public: 
    BufferedReader br; 
    StringTokenizer st; 

    // Constructor to initialize BufferedReader
    FastReader() { 
        br = new BufferedReader(new InputStreamReader(System.in)); 
    } 

    // Method to read the next token from input
    string next() { 
        // Read new line if no tokens are available
        while (st == null ||!st.hasMoreElements()) { 
            try { 
                st = new StringTokenizer(br.readLine()); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
        return st.nextToken(); 
    } 

    // Method to read the next integer from input
    int nextInt() { 
        return Integer.parseInt(next()); 
    } 

    // Method to read the next long from input
    long nextLong() { 
        return Long.parseLong(next()); 
    } 

    // Method to read the next double from input
    double nextDouble() { 
        return Double.parseDouble(next()); 
    } 

    // Method to read the next line from input
    string nextLine() { 
        string str = ""; 
        try { 
            str = br.readLine(); 
        } catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return str; 
    } 
}; 

// Create an instance of FastReader for input
FastReader scan; 

int main() { 
    int t = 1; // Number of test cases (currently set to 1)
    while (t-- > 0) { 
        solve(); // Call the solve method for processing
    } 
    return 0; 
} 

void solve() { 
    // Read the number of elements in the array
    int t = scan.nextInt(); 
    int arr[t]; 

    // Populate the array with input values
    for (int i = 0; i < t; i++) { 
        arr[i] = scan.nextInt(); 
    } 

    int prevWinner = 0; // Variable to track the previous winner
    
    // Iterate through the array to determine the winner for each element
    for (int i = 0; i < t; i++) { 
        // Check if the current element is 1
        if (arr[i] == 1) { 
            // If the previous winner is 0, set the previous winner to 2
            if (prevWinner == 0) { 
                prevWinner = 2; 
            } 
        } 

        // Determine the winner based on the previous winner and the current element
        if (prevWinner == 2 || prevWinner == 0) { 
            // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) { 
                cout << 2 << endl; // Print winner 2
                prevWinner = 2; // Update previous winner
            } else { 
                cout << 1 << endl; // Print winner 1
                prevWinner = 1; // Update previous winner
            } 
        } else { 
            // If the previous winner is 1, check the parity of (arr[i] - 1)
            if ((arr[i] - 1) % 2 == 0) { 
                cout << 1 << endl; // Print winner 1
                prevWinner = 1; // Update previous winner
            } else { 
                cout << 2 << endl; // Print winner 2
                prevWinner = 2; // Update previous winner
            } 
        } 
    } 
} 

