#include <iostream> 
#include <cmath> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    int n, m, q, i, j, md, res; 
    cin >> n; 
    int arr[n]; 
    arr[0] = cin.nextInt(); 
    for (i = 1; i < n; i++) { 
        int x = cin.nextInt(); 
        arr[i] = x + arr[i - 1]; 
    } 
    cin >> m; 
    int q[m]; 
    for (i = 0; i < m; i++) 
        q[i] = cin.nextInt(); 
    for (k = 0; k < m; k++) { 
        i = 0; 
        j = n; 
        while (i <= j) { 
            md = i + (j - i) / 2; 
            if (arr[md] == q[k]) 
                return md; 
            else if (arr[md] > q[k]) { 
                res = md; 
                j = md - 1; 
            } else 
                i = md + 1; 
        } 
        cout << res + 1 << endl; 
    } 
    return 0; 
} 

