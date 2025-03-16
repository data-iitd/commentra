package main

import "fmt"

func main() {
    // Read the number of elements in round_complexity and george_complexity
    var n, m int
    fmt.Scan(&n, &m)
    
    // Read the complexities of the rounds
    round_complexity := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&round_complexity[i])
    }
    
    // Read the complexities of George's challenges
    george_complexity := make([]int, m)
    for i := 0; i < m; i++ {
        fmt.Scan(&george_complexity[i])
    }
    
    // Initialize counters for both lists
    i, j := 0, 0
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        if round_complexity[i] <= george_complexity[j] {
            i++
        }
        
        // Increment j to move to the next element in george_complexity
        j++
    }
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

// Check if the script is run as the main program
if __name__ == "__main__":
    main()
