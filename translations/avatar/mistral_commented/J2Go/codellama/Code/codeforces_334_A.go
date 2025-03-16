
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initializing scanner for input and PrintWriter for output
    in := bufio.NewScanner(os.Stdin)
    out := bufio.NewWriter(os.Stdout)

    // Reading the number 'n' from the user
    in.Scan()
    n, _ := strconv.Atoi(in.Text())

    // Calculating the square of the number 'n'
    square := n * n

    // Creating an empty ArrayList for odd numbers
    odd := make([]int, 0)
    // Creating an empty ArrayList for even numbers
    even := make([]int, 0)

    for i := 1; i <= square; i++ {  // Looping from 1 to square
        if i%2 == 0 {  // If the number is even
            even = append(even, i)  // Add the number to the even ArrayList
        } else {  // If the number is odd
            odd = append(odd, i)  // Add the number to the odd ArrayList
        }
    }

    loop := square / n  // Calculating the number of pairs to be printed
    div := loop / 2  // Calculating half of the number of pairs

    for i := 1; i <= loop; i++ {  // Looping through each pair
        for j := 0; j < div; j++ {  // Looping through half of the pair
            if i%2 == 1 {  // If the current pair is odd
                fmt.Fprintf(out, "%d %d ", odd[0], even[len(even)-1])  // Print the first and last numbers of the current pair
                odd = odd[1:]  // Remove the first number from the odd ArrayList
                even = even[:len(even)-1]  // Remove the last number from the even ArrayList
            } else {  // If the current pair is even
                fmt.Fprintf(out, "%d %d ", even[0], odd[len(odd)-1])  // Print the last and first numbers of the current pair
                even = even[1:]  // Remove the first number from the even ArrayList
                odd = odd[:len(odd)-1]  // Remove the last number from the odd ArrayList
            }
        }
        fmt.Fprintln(out)  // Printing a newline after each pair
    }

    out.Flush()  // Closing the PrintWriter after printing all the pairs
}

