

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading input from standard input
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n') // Read a line and convert it to a string
    input = strings.TrimSpace(input) // Remove any leading or trailing whitespace
    arr := []rune(input) // Convert the string to a rune array
    N := len(arr) // Store the length of the rune array

    // Initialize a map to store unique strings and read the number of test cases
    set := make(map[string]bool)
    K, _ := strconv.Atoi(reader.ReadLine()) // Read the number of test cases and convert it to an integer

    // Initialize the result variable to store the final count
    res := 0

    // Loop to process each test case
    for k := 0; k < K; k++ {
        input, _ := reader.ReadString('\n') // Read the input string for the current test case
        input = strings.TrimSpace(input) // Remove any leading or trailing whitespace
        a := 0 // Counter for the first character of the input
        b := 0 // Counter for the second character of the input

        // Iterate over the characters of the input array
        for i := 0; i < N; i++ {
            if arr[i] == rune(input[0]) { // If the character matches the first character of the input
                a++ // Increment the counter
            } else if arr[i] == rune(input[1]) { // If the character matches the second character of the input
                b++ // Increment the counter
            } else { // If the character does not match either of the input characters
                res += int(math.Min(float64(a), float64(b))) // Add the minimum of a and b to the result
                a = b = 0 // Reset the counters
            }
        }
        res += int(math.Min(float64(a), float64(b))) // Add the minimum of a and b to the result after the loop
    }

    // Print the final result
    fmt.Println(res) // Print the final result
}

