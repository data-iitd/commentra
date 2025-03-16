package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N int
    var MOD int64 = 1000000007
    var TOKENS = []string{"A", "C", "G", "T"}
    var memo []map[string]int64

    // Constructor initializes N and sets up memoization array
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    N, _ = strconv.Atoi(scanner.Text())
    scanner.Close()
    memo = make([]map[string]int64, N + 1)
    for i := 0; i < len(memo); i++ {
        memo[i] = make(map[string]int64)
    }

    // Method to calculate the number of valid sequences
    func calc() int64 {
        return dfs(0, "TTT")
    }

    // Method to check if the last four characters form a valid sequence
    func isOK(last4 string) bool {
        if strings.Contains(last4, "AGC") {
            return false
        }
        for i := 0; i < 3; i++ {
            vals := []rune(last4)
            vals[i] = rune(last4[i + 1])
            vals[i + 1] = rune(last4[i])
            s := string(vals)
            if strings.Contains(s, "AGC") {
                return false
            }
        }
        return true
    }

    // Recursive method to count valid sequences using memoization
    func dfs(current int, last3 string) int64 {
        if memo[current][last3] != 0 {
            return memo[current][last3]
        }
        if current == N {
            return 1
        }
        result := int64(0)
        for _, c := range TOKENS {
            if isOK(last3 + c) {
                result = (result + dfs(current + 1, last3[1:] + c)) % MOD
            }
        }
        memo[current][last3] = result
        return result
    }

    // Main method to run the program
    fmt.Println(calc())
}

