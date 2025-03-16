
#####
# Code
#####

# Read the number of elements in the list 'A'
int N;
std::cin >> N;

// Initialize an empty list 'A' with the given size 'N'
// and read the elements from the standard input
std::vector<int> A(N);
for (int i = 0; i < N; i++) {
    std::cin >> A[i];
}

// Initialize minimum and maximum indices'mn' and'mx'
int mn = N + 1, mx = -1;

// Iterate through the list 'A' from index 0 to 'N-1'
for (int i = 0; i < N; i++) {
    // Check if the current index 'i' is not equal to the next element
    if (i + 1!= A[i]) {
        // Update the minimum and maximum indices'mn' and'mx'
        mn = std::min(mn, i);
        mx = std::max(mx, i);
    }
}

// Check if the maximum index'mx' is still equal to -1
if (mx == -1) {
    // If yes, print '0 0' as the output
    std::cout << "0 0" << std::endl;
} else {
    // Slice the list 'A' based on the indices'mn' and'mx+1'
    std::vector<int> B(A.begin() + mn, A.begin() + mx + 1);
    std::reverse(B.begin(), B.end());
    A.erase(A.begin() + mn, A.begin() + mx + 1);
    A.insert(A.begin() + mn, B.begin(), B.end());
    
    // Check if the sliced list 'A' is sorted in ascending order
    bool sorted = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > A[i + 1]) {
            sorted = false;
            break;
        }
    }
    
    // If yes, print the minimum and maximum indices'mn+1' and'mx+1' as the output
    if (sorted) {
        std::cout << mn + 1 << " " << mx + 1 << std::endl;
    } else {
        // If no, print '0 0' as the output
        std::cout << "0 0" << std::endl;
    }
}

