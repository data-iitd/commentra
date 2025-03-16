
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Create a Scanner object for input and a BufferedWriter for output
    Scanner sc(cin); 
    BufferedWriter bw(new BufferedWriter(new OutputStreamWriter(cout))); 
    
    // Read the dimensions of the grid and the parameters A and B
    int H = sc.nextInt(); // Height of the grid
    int W = sc.nextInt(); // Width of the grid
    int A = sc.nextInt(); // Parameter A
    int B = sc.nextInt(); // Parameter B
    
    // Check if the grid can accommodate the required number of 0s and 1s
    if (W < 2 * A || H < 2 * B) { 
        cout << -1 << endl; // Print -1 if the grid is too small
        return 0; // Exit the program
    } 
    
    // Generate the grid based on the parameters A and B
    for (int i = 0; i < H; i++) { // Iterate over each row
        for (int j = 0; j < W; j++) { // Iterate over each column
            // Determine whether to write '0' or '1' based on the current position
            if ((i < B && j < A) || (i >= B && j >= A)) 
                bw << "0"; // Write '0' for specified conditions
            else 
                bw << "1"; // Write '1' otherwise
        } 
        bw << endl; // Move to the next line after finishing a row
    } 
    
    // Flush the BufferedWriter to ensure all data is written out
    bw.flush(); 
    
    return 0; 
}
