// Import necessary libraries
import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

// Read input number of rows and columns
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
int M = scanner.nextInt();

// Initialize array 'A' with given dimensions and data type
int[] A = new int[N];
for (int i = 0; i < N; i++) {
    A[i] = scanner.nextInt();
}

// Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
int[] cum_remainders = new int[N];
cum_remainders[0] = A[0] % M;
for (int i = 1; i < N; i++) {
    cum_remainders[i] = (cum_remainders[i - 1] + A[i]) % M;
}

// Count the occurrences of each cumulative remainder
Map<Integer, Integer> remainder_counts = new HashMap<>();
for (int remainder : cum_remainders) {
    if (remainder_counts.containsKey(remainder)) {
        remainder_counts.put(remainder, remainder_counts.get(remainder) + 1);
    } else {
        remainder_counts.put(remainder, 1);
    }
}

// Calculate the number of combinations of elements having the same remainder
int combinations = 0;
for (int count : remainder_counts.values()) {
    combinations += count * (count - 1) / 2;
}

// Print the result
System.out.println(combinations);

