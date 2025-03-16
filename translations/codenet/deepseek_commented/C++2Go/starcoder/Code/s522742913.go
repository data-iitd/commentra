<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Input Handling
    // The program starts by taking a string input from the user.
    var source string
    fmt.Scanf("%s", &source)

    // It checks if the length of the input string is within the valid range (1 to 10 characters).
    // If not, it returns -1.
    if len(source) > 10 || len(source) < 1 {
        fmt.Println(-1)
        return
    }

    // Step 2: Calculation Setup
    // The program calculates the maximum number of combinations that can be formed
    // by placing '+' signs between the digits of the input string.
    // This is done using the formula 2^(n-1), where n is the length of the input string.
    max_i := int(math.Pow(2, float64(len(source)-1)))

    // Step 3: Iterating Over Combinations
    // The program iterates over all possible combinations of placing '+' signs between the digits.
    // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    sum := 0.0
    for i := 0; i < max_i; i++ {
        plus := fmt.Sprintf("%b", i)
        plus = strings.Repeat("0", 100-len(plus)) + plus

        number := 0.0
        working := source
        for _, v := range plus {
            if v == '1' {
                i, _ := strconv.Atoi(working[:strings.Index(working, "+")+1])
                number += float64(i)
                working = working[strings.Index(working, "+")+1:]
            }
        }
        number += float64(atoi(working))
        sum += number
    }

    // Step 4: Output
    // Finally, the program outputs the sum of all possible combinations.
    fmt.Printf("%.0f\n", sum)
}

