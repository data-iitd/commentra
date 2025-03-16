
#include <bits/stdc++.h> 
using namespace std; 

// FastReader object to read input efficiently
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

    // Read the number of banned cells
    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols; 

    // Read each banned cell and add it to the appropriate set if it's not on the border
    for (int i = 0; i < m; i++) { 
        int r, c; 
        cin >> r >> c; 
        if (r > 1 && r < n) bannedRows.insert(r); 
        if (c > 1 && c < n) bannedCols.insert(c); 
    } 

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2; 
    answer -= bannedRows.size(); 
    answer -= bannedCols.size(); 

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2!= 0) { 
        int mid = (n + 1) / 2; 
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) { 
            answer--; 
        } 
    } 

    // Output the final answer
    cout << answer << endl; 

    // Close the output stream
    return 0; 
} 

