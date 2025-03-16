
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initialize variables
    var str string
    var tmp string
    var sum int

    // Start an infinite loop
    for {
        // Read a string from the user input
        reader := bufio.NewReader(os.Stdin)
        str, _ = reader.ReadString('\n')

        // Check if the user wants to exit by entering "0"
        if str == "0\n" {
            // Exit the loop if user enters "0"
            break
        }

        // Initialize sum variable to zero
        sum = 0

        // Iterate through each character in the string
        for i := 0; i < len(str); i++ {
            // Get the character as a string
            tmp = string(str[i])

            // Convert the character to an integer and add it to the sum
            num, _ := strconv.Atoi(tmp)
            sum += num
        }

        // Print the sum of the digits in the string
        fmt.Println(sum)
    }
}

