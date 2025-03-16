// Import the NumPy library for efficient array operations
import numpy as np

// Read the number of elements 'N' from the user
int N = Integer.parseInt(input());

// Read 'N' integers from the user and store them in a NumPy array 'A'
int[] A = np.fromiter(Arrays.stream(input().split()).mapToInt(Integer::parseInt), int.class);

// Initialize the result variable to zero
long result = 0;

// Iterate through each bit position 'b' from 0 to 59
for (int b = 0; b < 60; b++) {
    
    // Calculate the sum of bits in position 'b' in all numbers of 'A'
    int bs = (int) ((A >> b).sum());
    
    // Calculate the contribution of this bit position 'b' to the result
    long contribution = bs * (N - bs) * (1 << b);
    
    // Add this contribution to the result
    result = (result + contribution) % 1000000007;
}

// Print the final result
System.out.println(result);

