// Read the number of elements in the array
int n = Integer.parseInt(input());

// Read the array elements from input, converting them to integers
int[] arr = Arrays.stream(input().strip().split()).mapToInt(Integer::parseInt).toArray();

// Initialize an answer array with zeros, which will store the results
int[] ans = new int[n];

// Set the maximum value to the last element of the array
int mx = arr[n - 1];

// Iterate through the array from the second last element to the first
for (int i = n - 2; i >= 0; i--) {
    // Calculate the required value for ans[i] based on the difference from the maximum
    ans[i] = Math.max(0, mx - arr[i] + 1);
    
    // Update the maximum value if the current element is greater than the current maximum
    if (arr[i] > mx) {
        mx = arr[i];
    }
}

// Print the result array as space-separated values
for (int i = 0; i < n; i++) {
    System.out.print(ans[i] + " ");
}

// 