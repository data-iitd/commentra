
#include <bits/stdc++.h> 
using namespace std; 

// Function to count the number of set bits (1s) in the binary representation of x
int rec(long x) { 
    int answer = 0; 
    // Iterate through each bit position from 31 to 0
    for (int k = 31; k >= 0; k--) { 
        // Check if the k-th bit is set
        if ((x & (1 << k))!= 0) 
            answer++; 
    } 
    return answer; 
} 

int main() { 
    // Initialize FastReader for input and PrintWriter for output
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    FastReader sc; 
    PrintWriter out; 
    
    // Read the number of integers to process
    int n = sc.nextInt(); 
    
    // Array to count occurrences of integers based on their bit count
    int a[33] = {0}; 
    
    // Process each integer and count how many have the same number of set bits
    for (int i = 0; i < n; i++) { 
        a[rec(sc.nextLong())]++; 
    } 
    
    // Variable to accumulate the final answer
    double answer = 0; 
    
    // Calculate the contribution to the answer from each bit count
    for (int i = 0; i < 33; i++) { 
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); 
        answer += summ; 
    } 
    
    // Print the final answer as a long integer
    cout << (long) answer << endl; 
    return 0; 
} 

// FastReader class for efficient input reading
class FastReader { 
public: 
    BufferedReader br; 
    StringTokenizer st; 
    
    // Constructor to initialize BufferedReader
    FastReader() { 
        br = new BufferedReader(new InputStreamReader(System.in)); 
    } 
    
    // Method to read the next token as a String
    string next() { 
        // Read a new line if the current tokenizer is exhausted
        while (st == NULL ||!st.hasMoreElements()) { 
            try { 
                st = new StringTokenizer(br.readLine()); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
        return st.nextToken(); 
    } 
    
    // Method to read the next token as an integer
    int nextInt() { 
        return stoi(next()); 
    } 
    
    // Method to read the next token as a long
    long nextLong() { 
        return stol(next()); 
    } 
    
    // Method to read the next token as a double
    double nextDouble() { 
        return stod(next()); 
    } 
    
    // Method to read the next line as a String
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

// End of code