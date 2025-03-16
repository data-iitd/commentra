
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declaring the main function, which is the entry point of the Go application

    infile := bufio.NewReader(os.Stdin)
    // Creating a new Reader object to read input from the standard input stream

    arr, _ := infile.ReadString('\n')
    // Reading the first line of input as a string and storing it in the 'arr' variable

    N := len(arr)
    // Declaring and initializing the length of the string 'arr' in the variable 'N'

    set := make(map[string]bool)
    // Creating an empty map object to store unique strings

    K, _ := strconv.Atoi(infile.Text())
    // Reading the second line of input as an integer and storing it in the variable 'K'

    res := 0
    // Declaring and initializing an integer variable 'res' to store the result

    for k := 0; k < K; k++ {
        // Starting a for loop that iterates 'K' times

        input, _ := infile.ReadString('\n')
        // Reading a string as input and storing it in the 'input' variable

        a := 0
        b := 0
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string 'arr'

        for i := 0; i < N; i++ {
            // Starting a nested for loop that iterates through each index of the string 'arr'

            if arr[i] == input[0] {
                a++
            } else if arr[i] == input[1] {
                b++
            } else {
                res += int(math.Min(float64(a), float64(b)))
                a = b = 0
            }
        }

        res += int(math.Min(float64(a), float64(b)))
    }

    fmt.Println(res)
    // Printing the final result to the standard output stream
}

