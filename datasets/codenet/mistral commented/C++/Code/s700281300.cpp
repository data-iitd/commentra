
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

// Main function starts here
int main() {
    int n; // number of strings to be processed

    // Read the number of strings from the standard input
    cin >> n;

    // Iterate through each string
    rep(i,n) {
        string s; // string to be processed

        // Read the string from the standard input
        cin >> s;

        // Create an empty set to store unique substrings
        set<string> st;

        // Process each substring of the string
        REP(j,1,s.size()){
            // Create a stringstream to store the substring
            stringstream ss;

            // Iterate through the first j characters of the string
            rep(k,j) {
                // Add the character to the stringstream
                ss << s[k];
            }

            // Get the substring as a string from the stringstream
            string res = ss.str();

            // Create another stringstream to process the remaining characters of the string
            stringstream ss2;

            // Iterate through the remaining characters of the string
            REP(k,j,s.size()) {
                // Add the character to the stringstream
                ss2 << s[k];
            }

            // Get the substring as a string from the stringstream
            string res2 = ss2.str();

            // Create two temporary strings by reversing the substrings
            string t = res;
            reverse(res.begin(),res.end());
            string t2 = res2;
            reverse(res2.begin(),res2.end());

            // Insert all possible combinations of the substrings and their reversed versions into the set
            st.insert(t+t2);
            st.insert(t2+t);
            st.insert(t+res2);
            st.insert(res2+t);
            st.insert(res+t2);
            st.insert(t2+res);
            st.insert(res+res2);
            st.insert(res2+res);
        }

        // Print the size of the set, which represents the number of unique substrings
        cout << st.size() << endl;
    }

    // Main function ends here
    return 0;
}
