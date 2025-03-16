// Input: Read the values of N and K
N,K := 0,0
fmt.Scan(&N,&K) // N is the size of the array, K is a parameter
A := make([]int,N) // Read N elements into array A

// Solution: Calculate the number of inversions in the array
ans1 := 0 // Initialize the count of inversions
for i := 0; i < N; i++ { // Iterate through each element
    for j := 0; j < N; j++ { // Compare with every other element
        if i >= j { continue } // Skip if i is greater than or equal to j
        if A[i] > A[j] { ans1++ } // Count inversion if A[i] > A[j]
        ans1 %= mod // Take modulo to prevent overflow
    }
}

// Count occurrences of each element in the array
count := make([]int,2005) // Initialize a count array to store frequencies
for i := 0; i < N; i++ { // Iterate through the array
    count[A[i]-1]++ // Increment the count for the corresponding value
}

// Calculate the second part of the answer based on the counts
ans2 := 0 // Initialize the second answer
remain := N // Remaining elements to consider
for i := 0; i < 2005; i++ { // Iterate through the count array
    remain -= count[i] // Decrease the remaining count by the current count
    ans2 += count[i]*remain // Calculate pairs of inversions
}

// Calculate the final answer based on ans1 and ans2
ans := 0 // Initialize the final answer
tmp := K*(K-1) // Calculate the number of ways to choose 2 from K
tmp /= 2 // Divide by 2 to get combinations
tmp %= mod // Take modulo
tmp *= ans2 // Multiply by the second answer
tmp %= mod // Take modulo again
ans += ans1 * K // Add the contribution from ans1
ans %= mod // Take modulo
ans += tmp // Add the contribution from tmp
ans %= mod // Take modulo

// Output: Print the final answer
fmt.Println(ans) // Output the result

