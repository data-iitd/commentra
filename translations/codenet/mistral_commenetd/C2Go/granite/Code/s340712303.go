

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

const N = 2000

func main() {
    // Initialize variables
    var (
        num1, a, num2, ans, sum int
        err error
        i, j int
    )

    // Initialize math array with first element as 1
    math := make([]int, N+1)
    math[0] = 1

    // Read the number of integers to be input
    fmt.Print("Enter the number of integers to be input:\n")
    num1, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine())
    if err!= nil {
        fmt.Println("Error:", err)
        return
    }

    // Read each integer and calculate its sum
    for i = 0; i < num1; i++ {
        fmt.Print("Enter an integer:\n")
        a, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine())
        if err!= nil {
            fmt.Println("Error:", err)
            return
        }

        // Add the current integer to the sum
        sum += a

        // Mark all the previous numbers as visited
        for j = sum - a; j >= 0; j-- {
            if math[j] == 1 {
                math[j+a] = 1
            }
        }
    }

    // Read the number of integers to be checked
    fmt.Print("Enter the number of integers to be checked:\n")
    num2, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine())
    if err!= nil {
        fmt.Println("Error:", err)
        return
    }

    // Check each integer and print the result
    for i = 0; i < num2; i++ {
        fmt.Print("Enter an integer to check:\n")
        ans, err = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine())
        if err!= nil {
            fmt.Println("Error:", err)
            return
        }

        // Check if the current integer is marked as visited
        if math[ans] == 1 {
            fmt.Println("yes")
        } else {
            fmt.Println("no")
        }
    }
}

