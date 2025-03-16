
#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <climits> 
#include <cstddef> 
#include <queue> 
#include <stack> 
#include <map> 
#include <set> 
#include <unordered_set> 
#include <unordered_map> 
#include <bitset> 
#include <cassert> 
#include <numeric> 
#include <array> 
#include <random> 
#include <chrono> 
#include <ratio> 
#include <complex> 
#include <iomanip> 
#include <locale> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <ostream> 
#include <iterator> 
#include <tuple> 
#include <utility> 
#include <functional> 
#include <memory> 
#include <stdexcept> 
#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <cstdlib> 
#include <limits> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <unordered_map> 
#include <unordered_set> 
#include <utility> 
#include <algorithm> 
#include <functional> 
#include <stack> 
#include <queue> 
#include <deque> 
#include <bitset> 
#include <cassert> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cwchar> 
#include <cwctype> 
#include <fstream> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <ostream> 
#include <iterator> 
#include <limits> 
#include <locale> 
#include <memory> 
#include <new> 
#include <numeric> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <vector> 

using namespace std; 

class Main { 
    long A , B , K ; 
    long x , y ; 

    public: 
        Main ( ) { 
            cin >> A >> B >> K ; 
        } 

        void calc ( ) { 
            x = A ; 
            y = B ; 
            x = A - K ; // Subtract K from A to get the new value of x
            if ( x < 0 ) { 
                y = B + x ; // Adjust B by the negative value of x
                x = 0 ; // Set x to 0 if it becomes negative
                if ( y < 0 ) { 
                    y = 0 ; // Set y to 0 if it becomes negative
                } 
            } 
        } 

        void showResult ( ) { 
            cout << x << " " << y << endl ; // Print the final values of x and y
        } 
}; 

int main ( ) { 
    Main ins = Main ( ) ; 
    ins.calc ( ) ; 
    ins.showResult ( ) ; 
    return 0 ; 
} 

