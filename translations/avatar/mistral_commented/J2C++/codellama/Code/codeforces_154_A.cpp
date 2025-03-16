
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std ;

int main ( ) {
    // Declaring the main method, which is the entry point of the C++ application

    string hi ;
    // Declaring a string variable 'hi' to store the input string

    cin >> hi ;
    // Reading the first line of input as a string and storing it in the 'hi' variable

    int N = hi.length ( ) ;
    // Declaring and initializing the length of the string 'hi' in the variable 'N'

    set < string > set ;
    // Creating an empty set object to store unique strings

    int K ;
    // Declaring an integer variable 'K' to store the number of input strings

    cin >> K ;
    // Reading the second line of input as an integer and storing it in the variable 'K'

    int res = 0 ;
    // Declaring and initializing an integer variable 'res' to store the result

    for ( int k = 0 ; k < K ; k ++ ) {
        // Starting a for loop that iterates 'K' times

        string input ;
        // Declaring a string variable 'input' to store the input string

        cin >> input ;
        // Reading a string as input and storing it in the 'input' variable

        int a = 0 ;
        int b = 0 ;
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string 'hi'

        for ( int i = 0 ; i < N ; i ++ ) {
            // Starting a nested for loop that iterates through each index of the string 'hi'

            if ( hi [ i ] == input [ 0 ] )
                a ++ ;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

            else if ( hi [ i ] == input [ 1 ] )
                b ++ ;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

            else {
                res += min ( a , b ) ;  // Adding the minimum of 'a' and 'b' to the 'res' variable if the current character is different from both characters in the input string
                a = b = 0 ;  // Resetting the 'a' and 'b' variables to zero
            }
        }

        res += min ( a , b ) ;  // Adding the minimum of 'a' and 'b' to the 'res' variable after the end of the outer for loop
    }

    cout << res << endl ;
    // Printing the final result to the standard output stream

    return 0 ;
}

