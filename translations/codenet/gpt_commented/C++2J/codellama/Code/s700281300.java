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

public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        int n;
        cin >> n;

        // Process each test case
        rep(i, n) {
            string s;
            // Read the string for the current test case
            cin >> s;

            // Initialize a set to store unique combinations of strings
            set<string> st;
            // Insert the original string into the set
            st.insert(s);

            // Generate combinations by splitting the string at different positions
            REP(j, 1, s.size()) { 
                stringstream ss;
                // Create the first part of the split string
                rep(k, j) {
                    ss << s[k];
                }
                string res = ss.str(); // First part of the string

                stringstream ss2;
                // Create the second part of the split string
                REP(k, j, s.size()) {
                    ss2 << s[k];
                }
                string res2 = ss2.str(); // Second part of the string

                // Create reversed versions of both parts
                string t = res;
                reverse(res.begin(), res.end()); // Reverse the first part
                string t2 = res2;
                reverse(res2.begin(), res2.end()); // Reverse the second part

                // Insert various combinations of the parts and their reverses into the set
                st.insert(t + t2); // Original order
                st.insert(t2 + t); // Reversed order

                st.insert(t + res2); // First part + second part
                st.insert(res2 + t); // Second part + first part

                st.insert(res + t2); // First part + reversed second part
                st.insert(t2 + res); // Reversed second part + first part

                st.insert(res + res2); // First part + second part (both original)
                st.insert(res2 + res); // Second part + first part (both original)
            }

            // Output the number of unique combinations generated
            cout << st.size() << endl;
        }

        return 0; // End of the program
    }
}

