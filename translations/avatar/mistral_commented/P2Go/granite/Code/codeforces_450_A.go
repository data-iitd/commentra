
###
# Code
###

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Define the number of elements 'n' and the modulus'm' in the list 'l'
    n, m := readTwoInts()

    // Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by'm'
    l2 := make([]int, n)

    // Iterate through each element 'i' in the list 'l'
    for i := 0; i < n; i++ {
        // Check if the element 'i' is divisible by'm'. If yes, store the quotient (integer division) in 'l2' at index 'i'. If not, store the quotient plus one.
        if readInt()%m == 0 {
            l2[i] = readInt() / m
        } else {
            l2[i] = int(float64(readInt())/float64(m) + 1)
        }
    }

    // Find the maximum quotient in 'l2'
    mx := 0
    for i := 0; i < n; i++ {
        if l2[i] > mx {
            mx = l2[i]
        }
    }

    // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
    for i := 0; i < n; i++ {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
        if l2[i] == mx {
            ind = i
        }
    }

    // Print the index 'ind' plus one (since the indices in Go start from 0)
    fmt.Println(ind + 1)
}

func readInt() int {
    // Read an integer from the input
    //...
}

func readTwoInts() (int, int) {
    // Read two integers from the input
    //...
}

func readNInt64s(n int) []int64 {
    // Read 'n' integers from the input
    //...
}

func readNFloat64s(n int) []float64 {
    // Read 'n' floating-point numbers from the input
    //...
}

func readNStrings(n int) []string {
    // Read 'n' strings from the input
    //...
}

func readTwoFloat64s() (float64, float64) {
    // Read two floating-point numbers from the input
    //...
}

func readFloat64() float64 {
    // Read a floating-point number from the input
    //...
}

func readString() string {
    // Read a string from the input
    //...
}

func readNLines(n int) []string {
    // Read 'n' lines from the input
    //...
}

func readLine() string {
    // Read a line from the input
    //...
}

func checkError(err error) {
    // Check for any errors and handle them
    //...
}

func main() {
    // Define the number of elements 'n' and the modulus'm' in the list 'l'
    n, m := readTwoInts()

    // Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by'm'
    l2 := make([]int, n)

    // Iterate through each element 'i' in the list 'l'
    for i := 0; i < n; i++ {
        // Check if the element 'i' is divisible by'm'. If yes, store the quotient (integer division) in 'l2' at index 'i'. If not, store the quotient plus one.
        if readInt()%m == 0 {
            l2[i] = readInt() / m
        } else {
            l2[i] = int(float64(readInt())/float64(m) + 1)
        }
    }

    // Find the maximum quotient in 'l2'
    mx := 0
    for i := 0; i < n; i++ {
        if l2[i] > mx {
            mx = l2[i]
        }
    }

    // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
    for i := 0; i < n; i++ {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
        if l2[i] == mx {
            ind = i
        }
    }

    // Print the index 'ind' plus one (since the indices in Go start from 0)
    fmt.Println(ind + 1)
}

func readInt() int {
    // Read an integer from the input
    //...
}

func readTwoInts() (int, int) {
    // Read two integers from the input
    //...
}

func readNInt64s(n int) []int64 {
    // Read 'n' integers from the input
    //...
}

func readNFloat64s(n int) []float64 {
    // Read 'n' floating-point numbers from the input
    //...
}

func readNStrings(n int) []string {
    // Read 'n' strings from the input
    //...
}

func readTwoFloat64s() (float64, float64) {
    // Read two floating-point numbers from the input
    //...
}

func readFloat64() float64 {
    // Read a floating-point number from the input
    //...
}

func readString() string {
    // Read a string from the input
    //...
}

func readNLines(n int) []string {
    // Read 'n' lines from the input
    //...
}

func readLine() string {
    // Read a line from the input
    //...
}

func checkError(err error) {
    // Check for any errors and handle them
    //...
}

