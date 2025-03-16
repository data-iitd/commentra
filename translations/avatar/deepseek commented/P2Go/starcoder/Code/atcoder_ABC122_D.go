func ok(last4 string) bool {
    // Check if the last4 string contains "AGC" more than once
    for i := 0; i < 4; i++ {
        t := []rune(last4)
        if i >= 1 {
            // Swap the current and previous character
            t[i], t[i-1] = t[i-1], t[i]
        }
        if strings.Count(string(t), "AGC") >= 1 {
            // If "AGC" is found, return False
            return false
        }
    }
    return true
}

func dfs(cur, last3 string) int {
    // Check if the result for the current state (cur, last3) is already computed
    if last3, ok := memo[cur][last3]; ok {
        return last3
    }
    if cur == n {
        // Base case: if current length equals n, return 1 (valid sequence)
        return 1
    }
    ret := 0
    for _, c := range []rune("ACGT") {
        // Check if adding the character c to last3 forms a valid sequence
        if ok(last3 + string(c)) {
            // Recursively call dfs with the next character
            ret = (ret + dfs(cur+1, last3[1:]+string(c))) % mod
        }
    }
    memo[cur][last3] = ret
    return ret
}

// Read the input value for n
var n int
fmt.Scanf("%d", &n)
mod := 1000000007
// Initialize the memo dictionary for storing computed results
memo := make([]map[string]int, n+1)
for i := 0; i <= n; i++ {
    memo[i] = make(map[string]int)
}
// Print the result of the dfs function starting with last3 as "TTT"
fmt.Println(dfs(0, "TTT"))

