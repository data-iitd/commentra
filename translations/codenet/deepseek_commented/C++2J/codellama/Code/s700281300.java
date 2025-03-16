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

int main() {
    int n;
    cin >> n; // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    rep(i,n) { // Step 2: Processing Each Test Case - The outer loop rep(i,n) iterates over each test case.
        string s;
        cin >> s; // For each test case, the program reads a string s.

        set<string> st; // Step 3: Generating Substrings and Checking for Palindromes - A set st is used to store unique substrings.
        st.insert(s); // The first substring is inserted into the set.

        REP(j,1,s.size()){ // The inner loop REP(j,1,s.size()) iterates over possible split points in the string s.
            stringstream ss; // A stringstream is used to construct substrings.
            rep(k,j) { // The first part of the string is extracted and reversed.
                ss << s[k];
            }
            string res = ss.str();
            reverse(res.begin(),res.end()); // The first part is reversed.

            stringstream ss2; // Another stringstream is used to extract the second part of the string.
            REP(k,j,s.size()) { // The second part of the string is extracted and reversed.
                ss2 << s[k];
            }
            string res2 = ss2.str();
            reverse(res2.begin(),res2.end()); // The second part is reversed.

            string t = res; // The first part is concatenated with the reversed second part in both orders and added to the set.
            string t2 = res2;
            st.insert(t+t2);
            st.insert(t2+t);

            st.insert(t+res2); // The first part is concatenated with the reversed first part and added to the set.
            st.insert(res2+t);

            st.insert(res+t2); // The reversed first part is concatenated with the second part and added to the set.
            st.insert(t2+res);

            st.insert(res+res2); // The reversed first and second parts are concatenated in both orders and added to the set.
            st.insert(res2+res);
        }

        cout << st.size() << endl; // Step 4: Outputting the Result - After processing all split points for a string, the size of the set st is printed.
    }

    return 0; // Step 5: End of Program - The program ends with return 0.
}

