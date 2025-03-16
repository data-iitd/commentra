
#####
// This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
// It returns False if it does, and True otherwise.
// Input: last4 (a String of 4 nucleotides)
// Output: A boolean value
########################################################################################################################
public static boolean ok(String last4) {
    // Iterate through the last 4 nucleotides in reverse order
    for (int i = 0; i < 4; i++) {
        // Swap the positions of the current and previous nucleotides
        String t = last4;
        if (i >= 1) {
            t = t.substring(0, i-1) + last4.charAt(i) + last4.charAt(i-1) + t.substring(i+1);
        }
        
        // Check if the swapped sequence contains "AGC"
        if (t.indexOf("AGC") >= 0) {
            // If yes, return False and exit the function
            return false;
        }
    }
    
    // If no "AGC" sequence is found, return True
    return true;
}
########################################################################################################################

// This function performs Depth-First Search (DFS) to find the number of valid sequences
// Input: cur (the current index), last3 (the last 3 nucleotides)
// Output: An integer value representing the number of valid sequences
########################################################################################################################
public static int dfs(int cur, String last3) {
    // Memoization table to store the results of subproblems
    if (memo[cur].containsKey(last3)) {
        // If the subproblem has already been solved, return the stored result
        return memo[cur].get(last3);
    }
    
    // Base case: If we have reached the end of the sequence, return 1
    if (cur == n) {
        return 1;
    }
    
    // Initialize the result to 0
    int ret = 0;
    
    // Iterate through all possible nucleotides (A, C, G, T)
    for (char c : "ACGT".toCharArray()) {
        // Check if the next nucleotide can be added to the last 3 nucleotides
        if (ok(last3 + c)) {
            // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur+1, last3.substring(1) + c)) % mod;
        }
    }
    
    // Store the result in the memoization table and return it
    memo[cur].put(last3, ret);
    return ret;
}
########################################################################################################################

// Read the input: the number of nucleotides (n)
int n = scanner.nextInt();

// Initialize the memoization table with empty HashMaps
Map<String, Integer>[] memo = new HashMap[n+1];
for (int i = 0; i <= n; i++) {
    memo[i] = new HashMap<>();
}

// Initialize the modulus value
int mod = 1000000007;

// Perform DFS and print the result
System.out.println(dfs(0, "TTT"));

