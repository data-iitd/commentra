

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    t, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
    // Reading the first integer input from the user and converting it to an integer

    s, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
    // Reading the second integer input from the user and converting it to an integer

    q, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
    // Reading the third integer input from the user and converting it to an integer

    ans := 0
    // Initializing the variable ans to 0

    for s < t {
        // Starting a for loop that continues as long as s is less than t
        s *= q
        // Multiplying s by q
        ans++
        // Incrementing ans by 1
    }

    fmt.Println(ans)
    // Printing the final value of ans after the loop completes
}

