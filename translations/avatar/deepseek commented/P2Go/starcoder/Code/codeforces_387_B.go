package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements in round_complexity and george_complexity
    n, m := read_input()
    
    // Read the complexities of the rounds
    round_complexity := read_input()
    
    // Read the complexities of George's challenges
    george_complexity := read_input()
    
    // Initialize counters for both lists
    i := 0
    j := 0
    
    // Loop through both lists to compare complexities
    for i < n && j < m {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += 1 * (round_complexity[i] <= george_complexity[j])
        
        // Increment j to move to the next element in george_complexity
        j += 1
    
    // Print the number of rounds George can solve
    fmt.Println(n - i)
}

// Read the number of elements in round_complexity and george_complexity
func read_input() (int, int) {
    // Read the number of elements in round_complexity and george_complexity
    n, m := strings.Split(bufio.NewReader(os.Stdin).ReadString('\n'), " ")
    
    // Convert the strings to integers
    n, m = strconv.Atoi(n), strconv.Atoi(m)
    
    return n, m
}

// Read the complexities of the rounds
func read_input() []int {
    // Read the complexities of the rounds
    round_complexity := strings.Split(bufio.NewReader(os.Stdin).ReadString('\n'), " ")
    
    // Convert the strings to integers
    round_complexity = convert_to_int(round_complexity)
    
    return round_complexity
}

// Read the complexities of George's challenges
func read_input() []int {
    // Read the complexities of George's challenges
    george_complexity := strings.Split(bufio.NewReader(os.Stdin).ReadString('\n'), " ")
    
    // Convert the strings to integers
    george_complexity = convert_to_int(george_complexity)
    
    return george_complexity
}

// Convert the strings to integers
func convert_to_int(input []string) []int {
    output := make([]int, len(input))
    
    for i := 0; i < len(input); i++ {
        output[i], _ = strconv.Atoi(input[i])
    }
    
    return output
}

// Check if the script is run as the main program
func init() {
    if len(os.Args) == 1 {
        fmt.Println("Please provide input in the format 'go run main.go'")
        os.Exit(1)
    }
}

