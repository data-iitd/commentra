// Import necessary libraries
import java.util.*;

// Read input number of rows and columns
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int M = sc.nextInt();

// Initialize array 'A' with given dimensions and data type
int[] A = new int[N];
for (int i = 0; i < N; i++) {
    A[i] = sc.nextInt();
}

// Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
int[] cum_remainders = new int[N + 1];
cum_remainders[0] = 0;
for (int i = 0; i < N; i++) {
    cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
}

// Count the occurrences of each cumulative remainder
HashMap<Integer, Integer> remainder_counts = new HashMap<Integer, Integer>();
for (int i = 0; i < N + 1; i++) {
    remainder_counts.put(cum_remainders[i], remainder_counts.getOrDefault(cum_remainders[i], 0) + 1);
}

// Calculate the number of combinations of elements having the same remainder
int combinations = 0;
for (int count : remainder_counts.values()) {
    combinations += count * (count - 1) / 2;
}

// Print the result
System.out.println(combinations);

