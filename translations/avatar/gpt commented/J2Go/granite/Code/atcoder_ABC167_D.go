
package main

import (
    "bufio"
    "fmt"
    "os"
)

const MOD = 1000000007
const MAX = int(1e6) + 1
const LMAX = int64(1e18) + 1

func main() {
    // Initialize scanner for input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read the number of elements N and the long value K
    scanner.Scan()
    N, _ := fmt.Sscanf(scanner.Text(), "%d")
    scanner.Scan()
    K, _ := fmt.Sscanf(scanner.Text(), "%d")
    
    // Initialize the array A to store the input values
    A := make([]int, N)
    
    // Read N integers into the array A and adjust values to be zero-indexed
    for i := 0; i < N; i++ {
        scanner.Scan()
        A[i], _ = fmt.Sscanf(scanner.Text(), "%d")
        A[i]--
    }
    
    // Set to track used indices and arrays to store index and position
    used := make(map[int]bool)
    idx := make([]int, N)
    pos := make([]int, N)
    
    // Initialize variables for the cycle detection
    next, cur := 0, 0
    
    // Detect the cycle in the array using the 'used' set
    for!used[next] {
        used[next] = true
        idx[next] = cur
        pos[cur] = next
        next = A[next]
        cur++
    }
    
    // Calculate the lengths of the cycle and the position of the next element
    a := int64(cur) - int64(idx[next])
    b := int64(idx[next])
    
    // Calculate the answer based on the cycle length and K
    ans := int((10000*a + K - b) % a + b)
    
    // If b is greater than K, set ans to K
    if b > K {
        ans = int(K)
    }
    
    // Output the result, adjusting for 1-based indexing
    fmt.Println(pos[ans] + 1)
}

