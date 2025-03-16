
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define SIZE (1e5 * 2) + 13 // Define the size of the count array

vector<int> a; // Vector to store non-zero counts
vector<int> cnt(SIZE); // Vector to count occurrences of each integer

int main(){
    int n, k;
    scanf("%d %d", &n, &k); // Read the number of elements and the threshold k
    
    // Count occurrences of each integer
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    // Filter non-zero counts and store them in vector a
    for(int i = 0; i < cnt.size(); ++i){
        if(cnt[i] > 0)
            a.push_back(cnt[i]);
    }
    
    // Sort the vector a in ascending order
    sort(a.begin(), a.end());
    
    // Calculate the sum of the smallest k counts in vector a
    int ans = 0;
    int m = a.size() - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    
    // Output the result
    printf("%d\n", ans); // Output the result
    
    return 0;
}
