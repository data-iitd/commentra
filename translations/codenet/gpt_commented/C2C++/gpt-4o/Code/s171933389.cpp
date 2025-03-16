#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint> // uint64_t

// Macro definitions for maximum and minimum
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

// Function to read four integers from standard input
void get_int4(int &a1, int &a2, int &a3, int &a4) {
    std::cin >> a1 >> a2 >> a3 >> a4;
}

// Function to read an array of int64_t from standard input
void fget_array(std::vector<int64_t> &arr, int size) {
    arr.resize(size);
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

// Constants defining maximum sizes for arrays and ranks
const int NUM_MAX = 1000;
const int NUM2_MAX = NUM_MAX * NUM_MAX;
const int RANK_MAX = 3000;

// Comparison function for ascending order used in std::sort
bool asc(int64_t a1, int64_t a2) {
    return a1 < a2;
}

// Comparison function for descending order used in std::sort
bool desc(int64_t a1, int64_t a2) {
    return a1 > a2;
}

// Constants defining maximum values for calculations
const int64_t VAL_MAX = static_cast<int64_t>(1e+10);
const int64_t SUM_MAX = VAL_MAX * 3;

// Structure to represent a range with start and end indices
struct range {
    int start;
    int end;
};

// Function to find the lower bound index of a key in a sorted array
int lower_bound(const std::vector<int64_t> &arr, const range &r, int64_t key) {
    int low = r.start;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1; // Return the index of the first element greater than key
}

// Main function
int main() {
    // Variables to hold input values and rank
    int x, y, z, rank;
    get_int4(x, y, z, rank); // Read the dimensions and rank

    // Vectors to hold input values
    std::vector<int64_t> xrr, yrr, zrr;

    // Read the arrays from input
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);

    // Initialize min and max sums
    int64_t min_sum = VAL_MAX + 1;
    int64_t max_sum = 0;

    // Calculate minimum and maximum values from zrr
    for(int i = 0; i < z; i++) min_sum = min(min_sum, zrr[i]);
    for(int i = 0; i < z; i++) max_sum = max(max_sum, zrr[i]);

    // Create a vector to hold the sums of pairs from xrr and yrr
    std::vector<int64_t> pair;
    pair.reserve(NUM2_MAX);
    
    // Calculate all possible sums of pairs from xrr and yrr
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            pair.push_back(xrr[i] + yrr[j]);
        }
    }

    // Sort the pair array in ascending order
    std::sort(pair.begin(), pair.end(), asc);

    // Update min and max sums with the smallest and largest pair sums
    min_sum += pair[0];
    max_sum += pair.back();

    // Arrays for caching and counting
    std::vector<int> cache(NUM_MAX);
    std::vector<int> cnt_map(NUM_MAX);
    std::vector<int64_t> ans(RANK_MAX);

    // Calculate the size of the combined array
    int size = x * y * z;
    int64_t prev = min_sum;

    // Iterate to find the rank-th largest sum
    for(int r = rank; r >= 1; r--) {
        int64_t low = prev - 1;
        int64_t high = max_sum + 1;

        // Binary search to find the appropriate sum
        while(low + 1 < high) {
            int64_t mid = (low + high) / 2;
            int cnt = 0;

            // Count how many sums are less than or equal to mid
            for(int i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                range r = {cache[i] - 1, static_cast<int>(pair.size())};
                int tmp = lower_bound(pair, r, mid - pivot);
                cnt_map[i] = tmp;
                cnt += tmp;
            }

            // Adjust the search range based on the count
            if(cnt <= size - r) {
                std::copy(cnt_map.begin(), cnt_map.begin() + z, cache.begin());
                low = mid;
            } else {
                high = mid;
            }
        }

        // Store the found sum in the answer array
        ans[r - 1] = low;
        if(low == max_sum) break; // Stop if we reach the maximum sum
        prev = low; // Update previous sum for the next iteration
    }

    // Print the results for each rank
    for(int i = 0; i < rank; i++) {
        std::cout << (ans[i] == 0 ? max_sum : ans[i]) << std::endl;
    }

    return 0; // Return success
} // <END-OF-CODE>
