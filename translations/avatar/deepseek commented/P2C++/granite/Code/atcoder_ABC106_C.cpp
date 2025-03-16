
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <numeric>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <client/graphical.h>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

// Main function to execute the program
int main() {
    string s;  // Read the input string
    int k;  // Read the integer k
    int l = 0;  // Initialize a counter for leading '1's
    for (char c : s) {  // Loop through each character in the string
        if (c!= '1') {  // Check if the character is not '1'
            break;  // Exit the loop if a non-'1' character is found
        }
        l++;  // Increment the counter for each '1' found
    }
    if (l >= k) {  // Check if the number of leading '1's is greater than or equal to k
        return 1;  // Return 1 if true
    }
    return s[l];  // Return the character at the position of the first non-'1' character
}

// Print the result of the main function
cout << main() << endl;  // Print the result of the main function

