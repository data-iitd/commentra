// Read the number of elements in the list
int N = Integer.parseInt(input());

// Read the list of integers from input and convert them to a list of integers
List<Integer> A = Arrays.stream(input().split()).map(Integer::parseInt).collect(Collectors.toList());

// Initialize minimum and maximum indices for the range of elements that are out of place
int mn = N + 1, mx = -1;

// Iterate through the list to find the first and last indices where the element is not in its correct position
for (int i = 0; i < N; i++) {
    // Check if the current index + 1 does not match the value at that index
    if (i + 1!= A.get(i)) {
        // Update the minimum index if the current index is less than the current minimum
        mn = Math.min(mn, i);
        // Update the maximum index if the current index is greater than the current maximum
        mx = Math.max(mx, i);
    }
}

// If no elements were out of place, output '0 0'
if (mx == -1) {
    System.out.println("0 0");
} else {
    // Reverse the subarray from mn to mx and concatenate it with the rest of the list
    List<Integer> sublist = A.subList(mn, mx + 1);
    Collections.reverse(sublist);
    A.subList(mn, mx + 1).clear();
    A.addAll(mn, sublist);
    
    // Check if the modified list is sorted
    if (A.equals(Collections.sort(A))) {
        // If sorted, print the 1-based indices of the range that was reversed
        System.out.println(mn + 1 + " " + mx + 1);
    } else {
        // If not sorted, output '0 0'
        System.out.println("0 0");
    }
}

