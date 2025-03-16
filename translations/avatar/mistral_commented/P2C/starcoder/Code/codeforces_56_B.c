#######
# Code
#######

# Read the number of elements in the list 'A'
scanf("%d", &N);

// Initialize an empty list 'A' with the given size 'N'
// and read the elements from the standard input
int A[N];
for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
}

// Initialize minimum and maximum indices'mn' and'mx'
int mn = N + 1, mx = -1;

// Iterate through the list 'A' from index 0 to 'N-1'
for (int i = 0; i < N; i++) {
    // Check if the current index 'i' is not equal to the next element
    if (i + 1!= A[i]) {
        // Update the minimum and maximum indices'mn' and'mx'
        mn = min(mn, i);
        mx = max(mx, i);
    }
}

// Check if the maximum index'mx' is still equal to -1
if (mx == -1) {
    // If yes, print '0 0' as the output
    printf("0 0\n");
} else {
    // Slice the list 'A' based on the indices'mn' and'mx+1'
    int A[mx - mn + 1];
    for (int i = 0; i < mx - mn + 1; i++) {
        A[i] = A[mn + i];
    }
    
    // Check if the sliced list 'A' is sorted in ascending order
    if (is_sorted(A, mx - mn + 1)) {
        // If yes, print the minimum and maximum indices'mn+1' and'mx+1' as the output
        printf("%d %d\n", mn + 1, mx + 1);
    } else {
        // If no, print '0 0' as the output
        printf("0 0\n");
    }
}

