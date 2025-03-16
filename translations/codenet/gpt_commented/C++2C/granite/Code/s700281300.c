
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <set>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Process each test case
    rep(i, n) {
        char s[1000];
        // Read the string for the current test case
        scanf("%s", s);

        // Initialize a set to store unique combinations of strings
        std::set<std::string> st;
        // Insert the original string into the set
        st.insert(s);

        // Generate combinations by splitting the string at different positions
        REP(j, 1, strlen(s)) { 
            std::stringstream ss;
            // Create the first part of the split string
            rep(k, j) {
                ss << s[k];
            }
            std::string res = ss.str(); // First part of the string

            std::stringstream ss2;
            // Create the second part of the split string
            REP(k, j, strlen(s)) {
                ss2 << s[k];
            }
            std::string res2 = ss2.str(); // Second part of the string

            // Create reversed versions of both parts
            std::string t = res;
            std::reverse(res.begin(), res.end()); // Reverse the first part
            std::string t2 = res2;
            std::reverse(res2.begin(), res2.end()); // Reverse the second part

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
        printf("%d\n", st.size());
    }

    return 0; // End of the program
}
