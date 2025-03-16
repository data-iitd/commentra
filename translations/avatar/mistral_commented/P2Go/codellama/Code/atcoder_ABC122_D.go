########################################################################################################################
// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns False if it does, and True otherwise.
// Input: last4 (a list of 4 nucleotides)
// Output: A boolean value
########################################################################################################################
func ok(last4 []string) bool {
    // Iterate through the last 4 nucleotides in reverse order
    for i := 3; i >= 0; i-- {
        // Swap the positions of the current and previous nucleotides
        t := make([]string, 4)
        copy(t, last4)
        if i >= 1 {
            t[i], t[i-1] = t[i-1], t[i]
        }
        
        // Check if the swapped sequence contains "AGC"
        if strings.Count(strings.Join(t, ""), "AGC") >= 1 {
            // If yes, return False and exit the function
            return false
        }
    }
    
    // If no "AGC" sequence is found, return True
    return true
}
########################################################################################################################

// This function performs Depth-First Search (DFS) to find the number of valid sequences
// Input: cur (the current index), last3 (the last 3 nucleotides)
// Output: An integer value representing the number of valid sequences
########################################################################################################################
func dfs(cur int, last3 []string) int {
    // Memoization table to store the results of subproblems
    if _, ok := memo[cur][last3]; ok {
        // If the subproblem has already been solved, return the stored result
        return memo[cur][last3]
    }
    
    // Base case: If we have reached the end of the sequence, return 1
    if cur == n {
        return 1
    }
    
    // Initialize the result to 0
    ret := 0
    
    // Iterate through all possible nucleotides (A, C, G, T)
    for _, c := range []string{"A", "C", "G", "T"} {
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if ok(append(last3[1:], c)) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur+1, append(last3[1:], c))) % mod
        }
    }
    
    // Store the result in the memoization table and return it
    memo[cur][last3] = ret
    return ret
}
########################################################################################################################

// Read the input: the number of nucleotides (n)
n := 0
fmt.Scan(&n)

// Initialize the memoization table with empty dictionaries
memo := make([]map[string]int, n+1)
for i := 0; i <= n; i++ {
    memo[i] = make(map[string]int)
}

// Initialize the modulus value
mod := 1000000007

// Perform DFS and print the result
fmt.Println(dfs(0, []string{"T", "T", "T"}))

