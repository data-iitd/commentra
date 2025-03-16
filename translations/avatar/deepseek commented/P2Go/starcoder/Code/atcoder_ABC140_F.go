
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Function to read an integer from standard input
func I() int {
    s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    i, _ := strconv.Atoi(strings.TrimSpace(s))
    return i
}

// Function to read a list of integers from standard input
func LI() []int {
    s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    i, _ := strconv.Atoi(strings.TrimSpace(s))
    return make([]int, i)
}

func main() {
    // Read the number of elements N
    N := I()
    
    // Read the list of integers S, sort them in descending order
    S := make([]int, N)
    for i := 0; i < N; i++ {
        S[i] = I()
    }
    sort.Slice(S, func(i, j int) bool { return S[i] > S[j] })
    
    // Initialize a flag array to keep track of used elements
    flag := make([]bool, N)
    
    // Initialize the current list with the first element of S
    cur := make([]int, 0)
    cur = append(cur, S[0])
    
    // Set the flag for the first element to False
    flag[0] = false
    
    // Loop through N times
    for i := 0; i < N; i++ {
        j := 0
        jM := len(cur)
        
        // Iterate over the elements of S
        for k := 0; k < N; k++ {
            if!flag[k] && S[k] < cur[j] {
                // Add the element to cur, set its flag to False, and increment j
                cur = append(cur, S[k])
                flag[k] = false
                j++
                if j == jM {
                    break
            }
        }
        
        // If no such element is found, return "No"
        if j == jM {
            fmt.Println("No")
            return
        }
        
        // Sort cur in descending order
        sort.Slice(cur, func(i, j int) bool { return cur[i] > cur[j] })
    }
    
    // Return "Yes" if the condition is satisfied
    fmt.Println("Yes")
}

