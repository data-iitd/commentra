
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Input Handling
    // The program starts by taking a string input from the user.
    reader := bufio.NewReader(os.Stdin)
    source, _ := reader.ReadString('\n')
    source = strings.TrimSpace(source)

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
    maxI := int(math.Pow(2, float64(len(source)-1)))

    // Step 3: Iterating Over Combinations
    // The program iterates over all possible combinations of placing '+' signs between the digits.
    // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    sum := 0.0

    for i := 0; i < maxI; i++ {
        plus := fmt.Sprintf("%0"+strconv.Itoa(len(source)-1)+"b", i)

        number := 0.0

        working := source
        for len(plus) > 0 {
            index := strings.Index(plus, "1")
            sum += atof(working[:index+1])
            plus = plus[index+1:]
            working = working[index+1:]
        }
        sum += atof(working)
    }

    // Step 4: Output
    // Finally, the program outputs the sum of all possible combinations.
    fmt.Println(int(sum))
}

