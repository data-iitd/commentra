
#include <bits/stdc++.h> 
using namespace std; 

// FastReader for efficient input reading
class FastReader { 
    public: 
        FastReader() { 
            ios_base::sync_with_stdio(false); 
            cin.tie(NULL); 
        } 
        int nextInt() { 
            int x; 
            cin >> x; 
            return x; 
        } 
        long nextLong() { 
            long x; 
            cin >> x; 
            return x; 
        } 
        double nextDouble() { 
            double x; 
            cin >> x; 
            return x; 
        } 
        string nextString() { 
            string x; 
            cin >> x; 
            return x; 
        } 
}; 

int main() { 
    // Read the dimensions of the grid
    int n = FastReader().nextInt(), m = FastReader().nextInt(); 
    
    // Initialize sets to keep track of banned rows and columns
    set<int> bannedRows, bannedCols; 
    bannedRows = set<int>(); 
    bannedCols = set<int>(); 
    
    // Read the banned rows and columns
    for (int i = 0; i < m; i++) { 
        int r = FastReader().nextInt(); 
        // Add to bannedRows if the row is within valid range
        if (r > 1 && r < n) bannedRows.insert(r); 
        int c = FastReader().nextInt(); 
        // Add to bannedCols if the column is within valid range
        if (c > 1 && c < n) bannedCols.insert(c); 
    } 
    
    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2; 
    // Subtract the number of banned rows and columns from the answer
    answer -= bannedRows.size(); 
    answer -= bannedCols.size(); 
    
    // If n is odd, check the middle row and column
    if (n % 2 != 0) { 
        int mid = (n + 1) / 2; 
        // If the middle row and column are not banned, decrement the answer
        if (!bannedRows.count(mid) && !bannedCols.count(mid)) { 
            answer--; 
        } 
    } 
    
    // Output the final answer
    cout << answer << endl; 
    return 0; 
} 

