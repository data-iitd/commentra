
#include <iostream> 
#include <cmath> 
#include <cstdio> 
#include <vector> 
#include <algorithm> 
#include <map> 
#include <queue> 
#include <set> 
#include <string> 
#include <cstring> 
#include <cassert> 
#include <stack> 
#include <cstdlib> 
#include <fstream> 
#include <sstream> 
#include <unordered_set> 
#include <unordered_map> 
#include <deque> 
#include <numeric> 
#include <array> 
#include <forward_list> 
#include <list> 
#include <iterator> 
#include <functional> 
#include <limits> 
#include <initializer_list> 
#include <utility> 
#include <iomanip> 
#include <ctime> 
#include <cstddef> 
#include <cstdlib> 
#include <cstdarg> 
#include <cctype> 
#include <cstdio> 
#include <cstdint> 
#include <cstdbool> 
#include <cstdalign> 
#include <cmath> 
#include <ctgmath> 
#include <ccomplex> 
#include <cfenv> 
#include <cinttypes> 
#include <cstdalign> 
#include <cstdnothrow> 
#include <cuchar> 
#include <climits> 
#include <cwchar> 
#include <cwctype> 
#include <cassert> 
#include <cerrno> 
#include <cfloat> 
#include <csignal> 
#include <cstdarg> 
#include <cstdbool> 
#include <cstdint> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cuchar> 
#include <cwchar> 
#include <cwctype> 
#include <exception> 
#include <initializer_list> 
#include <new> 
#include <typeindex> 
#include <typeinfo> 
#include <utility> 
#include <valarray> 
#include <array> 
#include <deque> 
#include <forward_list> 
#include <list> 
#include <map> 
#include <set> 
#include <stack> 
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <algorithm> 
#include <bitset> 
#include <chrono> 
#include <codecvt> 
#include <complex> 
#include <condition_variable> 
#include <deque> 
#include <exception> 
#include <fstream> 
#include <functional> 
#include <future> 
#include <initializer_list> 
#include <iomanip> 
#include <ios> 
#include <iosfwd> 
#include <iostream> 
#include <istream> 
#include <iterator> 
#include <limits> 
#include <list> 
#include <locale> 
#include <memory> 
#include <mutex> 
#include <new> 
#include <numeric> 
#include <ostream> 
#include <queue> 
#include <random> 
#include <ratio> 
#include <regex> 
#include <scoped_allocator> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <stdexcept> 
#include <streambuf> 
#include <string> 
#include <system_error> 
#include <thread> 
#include <tuple> 
#include <typeindex> 
#include <typeinfo> 
#include <unordered_map> 
#include <unordered_set> 
#include <utility> 
#include <valarray> 
#include <vector> 

using namespace std; 

int main() { 
    // Define a constant for array or list size
    const int NUM = ( int ) ( 1e5 + 2 ) ; 

    // Initialize a Scanner object to read input
    Scanner sc = new Scanner ( System.in ) ; 
    
    // Read the number of elements
    int N = sc.nextInt ( ) ; 
    
    // Initialize a HashMap to store value and its index
    HashMap < Integer , Integer > map = new HashMap < > ( ) ; 
    
    // Initialize a PriorityQueue to store numbers
    PriorityQueue < Integer > nums = new PriorityQueue < > ( ) ; 
    
    // Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
    for ( int i = 0 ; i < N ; i ++ ) { 
        int tmp = sc.nextInt ( ) ; 
        nums.add ( tmp ) ; 
        map.put ( tmp , i ) ; 
    } 
    
    // Initialize variables to keep track of the current index and the count of differences
    int bin = 0 ; 
    int diff = 0 ; 
    
    // Loop until the PriorityQueue is empty
    while ( ! nums.isEmpty ( ) ) { 
        // Retrieve the next number and its index from the PriorityQueue and HashMap
        int num = nums.poll ( ) ; 
        int idx = map.get ( num ) ; 
        
        // If the current index is not even when bin is even (or vice versa), increment the diff counter
        if ( ( bin % 2 ) != ( idx % 2 ) ) { 
            diff ++ ; 
        } 
        
        // Update bin and take modulo 2 to keep it within 0 or 1
        bin ++ ; 
        bin %= 2 ; 
    } 
    
    // Calculate the answer by dividing diff by 2
    int ans = ( diff / 2 ) ; 
    
    // Print the result
    System.out.println ( ans ) ; 
} 

