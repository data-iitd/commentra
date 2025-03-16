<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n, m int
<<<<<<< HEAD
    var foods []int
=======
>>>>>>> 98c87cb78a (data updated)

    // Read input values
    fmt.Scanln(&n, &m)

    // Initialize a vector of size m to store the count of each food item
<<<<<<< HEAD
    foods = make([]int, m)
=======
    foods := make([]int, m)
>>>>>>> 98c87cb78a (data updated)

    // Read n food preferences from the standard input
    for i := 0; i < n; i++ {
        var k int

        // Read the number of food items in the current preference
        fmt.Scanln(&k)

        // Read the indices of the food items in the current preference
        for j := 0; j < k; j++ {
            var temp int

            // Read the index of the current food item
            fmt.Scanln(&temp)

            // Increment the count of the corresponding food item in the foods vector
            foods[temp]++
        }
    }

    // Initialize a variable to store the number of food items that appear in all preferences
    var ans int

    // Iterate through each element in the foods vector and check if its count is equal to the total number of preferences
    for _, elem := range foods {
        if elem == n {
            ans++
        }
    }

    // Print the value of ans to the standard output
    fmt.Println(ans)
}

