

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    var li []int
    ind := 0
    // Initialize an empty slice and a variable to keep track of the index

    for i := 1; i < 371; i++ {
        temp := []int{}
        p, q := i, i
        count := 0
        // Initialize an empty temporary slice and set p and q to the current value of i
        // Initialize a counter to count the number of digits in i

        for p!= 0 {
            p /= 10
            count++
        }
        // Count the number of digits in i by repeatedly dividing p by 10

        if count == 1 {
            li = append(li, i)
        }
        // If i has 1 digit, append it to the list li

        if count == 2 {
            temp = []int{}
            for q!= 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
        // If i has 2 digits, extract the digits and append them to li

        if count == 3 {
            temp = []int{}
            for q!= 0 {
                x := q % 10
                q /= 10
                temp = append(temp, x)
            }
            li = append(li, temp...)
        }
        // If i has 3 digits, extract the digits and append them to li
    }

    li = li[:len(li)-2]
    // Remove the last two elements from li

    reader := bufio.NewReader(os.Stdin)
    // Create a reader to read input from the user

    fmt.Print("Enter the index: ")
    n, _ := reader.ReadString('\n')
    // Read a string input from the user

    n, _ = strconv.Atoi(n)
    // Convert the string input to an integer

    fmt.Println(li[n-1])
    // Print the nth element of li based on the user's input
}

