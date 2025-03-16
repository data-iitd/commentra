#include<iostream>  // Include the input-output stream library
#include<vector>    // Include the vector library
#include<string>    // Include the string library
#include<algorithm> // Include the algorithm library
#include<map>       // Include the map library
#include<cmath>     // Include the math library
#include<queue>     // Include the queue library
#include<stack>     // Include the stack library
#include<list>      // Include the list library

using namespace std; // Use the standard namespace
using ll = long long; // Define a shorthand for long long

int main(){
    int n;
    cin>>n;  // Read the integer n
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];  // Read n integers into the vector a
    }

    int ans=0;  // Initialize ans to 0
    bool ok = true;  // Initialize ok to true
    while(ok){  // Start the main loop
        for(int i=0;i<n;i++){  // Iterate over each element in the vector a
            if(a[i]%2 == 1){  // Check if the element is odd
                cout<<ans<<endl;  // Print the current value of ans and exit
                return 0;
            }
            else{  // If the element is even
                a[i] /= 2;  // Divide the element by 2
            }
        }
        ans++;  // Increment ans after processing all elements
    }

    cout<<ans<<endl;  // Print the final value of ans
}
