<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

// Function to solve the problem
<<<<<<< HEAD
func solve() {
=======
func solve() bool {
>>>>>>> 98c87cb78a (data updated)
    // Initialize variables to track the longest string and its count
    maxsize := 0
    maxcnt := 0
    ans_num := 0 // Index of the longest string
    ans_num2 := 0 // Index of the most frequent string
    str_v := make([]string, 0) // Vector to store input strings
    
    // Variable to read input strings
    var in string
<<<<<<< HEAD
    for _, _ = range(fmt.Scanf("%s", &in)) {
        str_v = append(str_v, in) // Store the input string in the vector
        if maxsize < len(in) { // Check if the current string is the longest so far
            maxsize = len(in) // Update the length of the longest string
            ans_num = len(str_v) - 1 // Store the index of the longest string
        }
    }
    
    // Count occurrences of each string and find the most frequent string
    for i := 0; i < len(str_v); i++ {
        cnt := 0
        for j := 0; j < len(str_v); j++ {
            if str_v[i] == str_v[j] {
                cnt++ // Count occurrences of the current string
            }
        }
        if maxcnt < cnt { // Check if the current string is the most frequent so far
            maxcnt = cnt // Update the count of the most frequent string
            ans_num2 = i // Store the index of the most frequent string
        }
    }
    
    // Output the most frequent and the longest string
    fmt.Printf("%s %s\n", str_v[ans_num2], str_v[ans_num])
}

// Main function to set precision and call the solve function
func main() {
    fmt.Printf("%.10f\n", math.Pi)
    solve()
}

=======
    fmt.Scanln(&in)
    for in!= "
>>>>>>> 98c87cb78a (data updated)
