
#include <bits/stdc++.h>
using namespace std ;

int main() {
    // Main method declaration

    int n = 0 ;  // Initializing the number of rows in the grid
    int m = 0 ;  // Initializing the number of banned cells

    cin >> n >> m ;  // Reading the number of rows in the grid and the number of banned cells

    set<int> bannedRows ;  // Creating a Set to store banned rows
    set<int> bannedCols ;  // Creating a Set to store banned columns

    for (int i = 0 ; i < m ; i ++ ) {
        // Reading banned cells and adding them to the respective Sets

        int r = 0 ;
        cin >> r ;
        if (r > 1 && r < n) bannedRows.insert(r) ;

        int c = 0 ;
        cin >> c ;
        if (c > 1 && c < n) bannedCols.insert(c) ;
    }

    int answer = (n - 2) * 2 ;  // Initializing answer as the total number of cells in the grid minus the banned cells
    answer -= bannedRows.size() ;  // Subtracting the number of banned rows
    answer -= bannedCols.size() ;  // Subtracting the number of banned columns

    if (n % 2!= 0) {
        // Special case when the number of rows is odd

        int mid = (n + 1) / 2 ;
        if (!bannedRows.contains(mid) &&!bannedCols.contains(mid)) {
            // If the middle cell is not banned, decrement the answer
            answer-- ;
        }
    }

    cout << answer << endl ;  // Writing the answer to the output stream
    return 0 ;
}

