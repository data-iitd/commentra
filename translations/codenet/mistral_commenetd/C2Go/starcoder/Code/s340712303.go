
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
<<<<<<< HEAD
    var num1, num2, a, ans, sum int
=======
    var num1, num2, a, ans int
    var sum int
>>>>>>> 98c87cb78a (data updated)
    var i, j int
    var math [2000]int

    // Initialize variables
    num1 = 0
    num2 = 0
<<<<<<< HEAD
=======
    a = 0
>>>>>>> 98c87cb78a (data updated)
    ans = 0
    sum = 0

    // Initialize math array with first element as 1
    math[0] = 1

    // Read the number of integers to be input
    fmt.Println("Enter the number of integers to be input:")
    fmt.Scanf("%d", &num1)

    // Read each integer and calculate its sum
    for i = 0; i < num1; i++ {
        fmt.Println("Enter an integer:")
        fmt.Scanf("%d", &a)

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
    fmt.Println("Enter the number of integers to be checked:")
    fmt.Scanf("%d", &num2)

    // Check each integer and print the result
    for i = 0; i < num2; i++ {
        fmt.Println("Enter an integer to check:")
        fmt.Scanf("%d", &ans)

        // Check if the current integer is marked as visited
        if math[ans] == 1 {
            fmt.Println("yes")
        } else {
            fmt.Println("no")
        }
    }
}

