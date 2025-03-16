#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

using namespace std;
using ll = long long;

int main(){
    // Read the number of elements
    int n;
    cin >> n;

    // Initialize a vector to store the elements
    vector<int> a(n);
    
    // Input the elements into the vector
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Initialize the answer counter and a flag for the loop
    int ans = 0;
    bool ok = true;

    // Loop until an odd number is found in the vector
    while(ok){
        // Check each element in the vector
        for(int i = 0; i < n; i++){
            // If the current element is odd, print the answer and exit
            if(a[i] % 2 == 1){
                cout << ans << endl;
                return 0;
            }
            // If the current element is even, divide it by 2
            else{
                a[i] /= 2;
            }
        }
        // Increment the answer counter for each complete iteration
        ans++;
    }

    // Output the final count of divisions by 2 before encountering an odd number
    cout << ans << endl;
}
