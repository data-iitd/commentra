

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    k, _ := reader.ReadString('\n') // Taking the first integer as input from the user
    n, _ := reader.ReadString('\n') // Taking the second integer as input from the user
    w, _ := reader.ReadString('\n') // Taking the third integer as input from the user

    kInt, _ := strconv.Atoi(k) // Converting the first input to an integer
    nInt, _ := strconv.Atoi(n) // Converting the second input to an integer
    wInt, _ := strconv.Atoi(w) // Converting the third input to an integer

    if kInt >= 1 && wInt <= 1000 { // Input validation
        total := 0 // Initializing the variable 'total' to zero
        for i := 1; i <= wInt; i++ { // Iterating from 1 to w (inclusive)
            total += i * kInt // Adding the product of k and the current index to the total variable
        }

        if total > nInt { // Checking if the total is greater than n or not
            fmt.Println(total - nInt) // If yes, printing the difference between total and n
        } else {
            fmt.Println(0) // If no, printing zero
        }
    }
}

