
#include <bits/stdc++.h> 
using namespace std; 

// FastReader for efficient input reading
class FastReader { 
public: 
    BufferedReader br; 
    StringTokenizer st; 

    FastReader() { 
        br = new BufferedReader(new InputStreamReader(System.in)); 
    } 

    // Method to read the next token
    string next() { 
        while (st == null ||!st.hasMoreElements()) { 
            try { 
                st = new StringTokenizer(br.readLine()); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
        return st.nextToken(); 
    } 

    // Method to read the next integer
    int nextInt() { 
        return Integer.parseInt(next()); 
    } 

    // Method to read the next long
    long nextLong() { 
        return Long.parseLong(next()); 
    } 

    // Method to read the next double
    double nextDouble() { 
        return Double.parseDouble(next()); 
    } 

    // Method to read the next line
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

int main() { 
    // Read the dimensions of the grid
    int n, m; 
    cin >> n >> m; 

    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols; 

    // Read the banned rows and columns
    for (int i = 0; i < m; i++) { 
        int r, c; 
        cin >> r >> c; 
        // Add to bannedRows if the row is within valid range
        if (r > 1 && r < n) bannedRows.insert(r); 
        // Add to bannedCols if the column is within valid range
        if (c > 1 && c < n) bannedCols.insert(c); 
    } 

    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2; 
    // Subtract the number of banned rows and columns from the answer
    answer -= bannedRows.size(); 
    answer -= bannedCols.size(); 

    // If n is odd, check the middle row and column
    if (n % 2!= 0) { 
        int mid = (n + 1) / 2; 
        // If the middle row and column are not banned, decrement the answer
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) { 
            answer--; 
        } 
    } 

    // Output the final answer
    cout << answer << endl; 

    return 0; 
} 

