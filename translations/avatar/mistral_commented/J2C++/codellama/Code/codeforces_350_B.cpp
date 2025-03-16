
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std ;

int main() {
    int n ;  // Declaring an integer variable 'n' to store the number of test cases
    cin >> n ;  // Reading the number of test cases from the standard input stream

    vector<int> a(n + 1) ;  // Creating a vector 'a' of size 'n+1' to store the elements of array 'a'
    vector<int> b(n + 1) ;  // Creating a vector 'b' of size 'n+1' to store the elements of array 'b'
    vector<int> num(n + 1) ;  // Creating a vector 'num' of size 'n+1' to store the elements of array 'num'

    for (int i = 1 ; i <= n ; i ++ ) {  // Loop to read the elements of arrays 'a' and 'b'
        cin >> a[i] >> b[i] ;
    }

    string ss = "" ;  // Declaring an empty string 'ss' to store the final answer
    int ans = 0 ;  // Declaring an integer variable 'ans' to store the maximum length of the answer
    vector<bool> st(n + 1) ;  // Creating a vector 'st' of size 'n+1' to store the visited elements

    for (int i = 1 ; i <= n ; i ++ ) {  // Loop to find the longest chain of numbers
        if (a[i] == 1) {  // If the current number 'i' in array 'a' is 1
            st[i] = true ;  // Mark the current number as visited
            stringstream sb ;  // Creating a stringstream object 'sb' to store the answer
            int x = b[i] ;  // Assigning the value of 'b[i]' to 'x'
            stringstream sss ;  // Creating a stringstream object 'sss' to store the current number
            sss << i ;  // Appending the current number 'i' to 'sss'
            sb << " " << sss.str().substr(sss.str().length() - 1, 1) ;  // Appending the reversed string of 'sss' to 'sb'
            int s = 1 ;  // Initializing an integer variable 's' to 1

            while (st[x] == false && num[x] == 1 && x != 0 && a[x] != 1) {  // Loop to traverse the graph
                sss.str("") ;  // Clearing the stringstream object 'sss'
                sss << x ;  // Appending the current number 'x' to 'sss'
                sb << " " << sss.str().substr(sss.str().length() - 1, 1) ;  // Appending the reversed string of 'sss' to 'sb'
                st[x] = true ;  // Marking the current number 'x' as visited
                x = b[x] ;  // Assigning the value of 'b[x]' to 'x'
                s ++ ;  // Incrementing the length of the current chain
            }

            if (s > ans) {  // If the length of the current chain is greater than the current maximum length
                ans = s ;  // Updating the maximum length
                ss = sb.str().substr(1, sb.str().length() - 1) ;  // Updating the final answer
            }
        }
    }

    cout << ans << endl ;  // Printing the maximum length of the longest chain
    cout << ss << endl ;  // Printing the longest chain as a string

    return 0 ;
}

