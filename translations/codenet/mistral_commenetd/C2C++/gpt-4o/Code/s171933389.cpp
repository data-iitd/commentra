#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

// Function to read an array of 4 integers from the standard input
int get_int4(int &a1, int &a2, int &a3, int &a4) {
    // Read 4 integers from the standard input and store them in the given references
    std::cin >> a1 >> a2 >> a3 >> a4;
    // Return 0 to indicate successful execution
    return 0;
}

// Function to read an array of 64-bit integers from the standard input
int fget_array(std::vector<int64_t> &arr, int size) {
    arr.resize(size);
    // Iterate through the given size and read each 64-bit integer from the standard input and store it in the given array
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    // Return 0 to indicate successful execution
    return 0;
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

// Comparator function for sort to sort an array of 64-bit integers in ascending order
bool asc(int64_t a1, int64_t a2) {
    return a1 < a2;
}

// Comparator function for sort to sort an array of 64-bit integers in descending order
bool desc(int64_t a1, int64_t a2) {
    return a1 > a2;
}

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

struct range {
    int start;
    int end;
};

// Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
int lower_bound(const std::vector<int64_t> &arr, const struct range &r, int64_t key) {
    int low = r.start;
    int high = r.end;
    // Binary search to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    // Return the index of the first element greater than or equal to the given key, or the size of the array if no such element exists
    return low + 1;
}

int main() {
    int x, y, z, rank;
    // Read 4 integers x, y, z, and rank from the standard input
    get_int4(x, y, z, rank);
    std::vector<int64_t> xrr, yrr, zrr; // Declare vectors to store the arrays of 64-bit integers
    // Read the three arrays of 64-bit integers from the standard input using the function fget_array()
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);
    int64_t min_sum = VAL_MAX + 1; // Initialize min_sum with a value larger than any possible sum
    int64_t max_sum = 0; // Initialize max_sum with an initial value of 0

    // Iterate through the third array zrr and update min_sum and max_sum accordingly
    for(int i = 0; i < z; i++) {
        min_sum = min(min_sum, zrr[i]);
        max_sum += zrr[i];
    }

    std::vector<int64_t> pair(NUM2_MAX); // Declare a vector to store the sum of each pair of elements from the first and second arrays
    int idx = 0; // Initialize an index variable idx to 0
    // Iterate through the first array xrr and the second array yrr, and compute the sum of each pair, storing it in the vector pair
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }
    // Sort the vector pair in ascending order
    std::sort(pair.begin(), pair.begin() + idx, asc);
    // Update min_sum and max_sum with the sum of the first and last elements in the sorted vector pair, respectively
    min_sum += pair[0];
    max_sum += pair[idx - 1];

    std::vector<int> cache(NUM_MAX); // Declare a vector to store the index of the last element less than or equal to the current pivot in the sorted vector pair
    std::vector<int> cnt_map(NUM_MAX); // Declare a vector to store the number of elements in the sorted vector pair less than or equal to the current pivot
    std::vector<int64_t> ans(RANK_MAX); // Declare a vector to store the answer for each rank
    int size = x * y * z; // Compute the size of the vector pair
    int64_t prev = min_sum; // Initialize prev with the initial value of min_sum

    // Iterate through the ranks from rank down to 1, and find the answer for each rank using binary search
    for(int r = rank; r >= 1; r--) {
        int64_t low = prev - 1; // Initialize the lower bound of the binary search with prev-1
        int64_t high = max_sum + 1; // Initialize the upper bound of the binary search with max_sum+1
        // Binary search to find the index of the first element greater than or equal to the current rank in the sorted vector ans
        while(low + 1 < high) {
            int64_t mid = (low + high) / 2;
            // Compute the number of elements in the sorted vector pair less than or equal to the current pivot, for each pivot in the third array zrr
            for(int i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i] - 1, idx}; // Define the range r for the current pivot
                int tmp = lower_bound(pair, r, mid - pivot); // Find the index of the first element greater than or equal to mid-pivot in the sorted vector pair
                cnt_map[i] = tmp; // Store the number of elements in the sorted vector pair less than or equal to the current pivot
            }
            // Check if the total number of elements in the sorted vector pair less than or equal to the current pivot, for all pivots in the third array zrr, is greater than or equal to the size of the vector pair minus the current rank
            if(std::accumulate(cnt_map.begin(), cnt_map.begin() + z, 0) >= size - r) {
                // If so, update prev with mid and continue the outer loop
                low = mid;
            } else {
                // Otherwise, update high with mid and continue the inner loop
                high = mid;
            }
        }
        // Store the index of the first element greater than or equal to the current rank in the sorted vector ans
        ans[r - 1] = low;
        // If the index found is equal to max_sum, break the outer loop as there is no solution for the current rank
        if(low == max_sum) break;
        // Update prev with the index found
        prev = low;
    }
    // Print the answer for each rank, except for the last rank which may not have a solution
    for(int i = 0; i < rank; i++) {
        std::cout << (ans[i] == 0 ? max_sum : ans[i]) << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
