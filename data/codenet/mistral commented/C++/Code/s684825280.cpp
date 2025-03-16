
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int SIZE = (1e5 * 2) + 13; // Define the size of the vector

vector<int> a; // Initialize an empty vector 'a' to store the frequency count of each element
vector<int> cnt(SIZE); // Initialize a vector 'cnt' of size 'SIZE' to store the frequency count of each element

int main(){
    int n, k; // Declare two integers 'n' and 'k' to read input

    cin>>n>>k; // Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

    for(int i = 0; i < n; ++i){ // Loop through the input elements
        int x; // Declare an integer 'x' to read an element from the standard input

        cin>>x; // Read an element 'x' from the standard input

        cnt[x]++; // Increment the frequency count of the element 'x' in the vector 'cnt'
    }

    for(int i = 0; i < cnt.size(); ++i){ // Loop through all elements in the vector 'cnt'
        if(cnt[i] > 0) // If the frequency count of an element is greater than zero
            a.push_back(cnt[i]); // Add the frequency count to the vector 'a'
    }

    int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

    sort(a.begin(), a.end()); // Sort the vector 'a' in ascending order

    int m = a.size() - k; // Calculate the index of the last frequency count to be considered

    for(int i = 0; i < m; ++i){ // Loop through the first 'k' frequency counts and add them to the variable 'ans'
        ans += a[i];
    }

    cout<<ans<<endl; // Print the result 'ans' to the standard output
}

