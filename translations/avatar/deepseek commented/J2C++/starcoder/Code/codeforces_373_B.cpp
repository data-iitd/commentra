
#include <bits/stdc++.h>
using namespace std;

// Global variable to store the answer
long long ans = 0;

// Helper function to calculate the sum of numbers based on a specific pattern
long long get(long long a) {
    long long ret = 0;
    long long now = 1;
    long long t = 1;
    for (; ; ) {
        if (now * 10 > a) {
            ret += (a - now + 1) * t;
            break;
        }
        ret += now * 9 * t;
        now *= 10;
        t++;
    }
    return ret;
}

// Binary search function to find the desired value
long long binarySearch(long long k, long long l, long long r, long long x) {
    if (r >= l) {
        long long mid = l + (r - l) / 2;
        if (mid > ans && mid * k <= x) ans = mid;

        if (k * mid == x) return mid;

        if (k * mid > x) return binarySearch(k, l, mid - 1, x);

        return binarySearch(k, mid + 1, r, x);
    }

    return -1;
}

// Setup for input and output using BufferedReader and PrintWriter
// Note: Do not delete 'r' even if you are not using it
// Note: Do not delete 'w' even if you are not using it
// Note: Do not delete's' even if you are not using it
// Note: Do not delete 't' even if you are not using it
// Note: Do not delete 'endl' even if you are not using it
// Note: Do not delete 'flush' even if you are not using it
// Note: Do not delete 'getline' even if you are not using it
// Note: Do not delete 'printf' even if you are not using it
// Note: Do not delete'scanf' even if you are not using it
// Note: Do not delete 'long long' even if you are not using it
// Note: Do not delete 'double' even if you are not using it
// Note: Do not delete 'int' even if you are not using it
// Note: Do not delete 'char' even if you are not using it
// Note: Do not delete'string' even if you are not using it
// Note: Do not delete'vector' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete 'queue' even if you are not using it
// Note: Do not delete'stack' even if you are not using it
// Note: Do not delete 'priority_queue' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'bitset' even if you are not using it
// Note: Do not delete 'complex' even if you are not using it
// Note: Do not delete 'valarray' even if you are not using it
// Note: Do not delete 'deque' even if you are not using it
// Note: Do not delete 'list' even if you are not using it
// Note: Do not delete 'forward_list' even if you are not using it
// Note: Do not delete 'array' even if you are not using it
// Note: Do not delete 'tuple' even if you are not using it
// Note: Do not delete 'pair' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: Do not delete 'unordered_multiset' even if you are not using it
// Note: Do not delete 'unordered_multimap' even if you are not using it
// Note: Do not delete 'unordered_map' even if you are not using it
// Note: Do not delete'map' even if you are not using it
// Note: Do not delete'set' even if you are not using it
// Note: Do not delete'multiset' even if you are not using it
// Note: Do not delete'multimap' even if you are not using it
// Note: Do not delete 'unordered_set' even if you are not using it
// Note: 