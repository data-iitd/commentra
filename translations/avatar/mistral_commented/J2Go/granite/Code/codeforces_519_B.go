
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Main function is the entry point of the Go application
    // It has a void return type and no parameters
    // We are using the bufio package to read input from the standard input
    // and the fmt package to write the output to the standard output
    // We are also using the os package to handle file related operations
    // We are also using the strconv package to convert string to integer

    reader := bufio.NewReader(os.Stdin)
    // Creating a new bufio.Reader object and initializing it with the standard input stream

    n, _ := strconv.Atoi(reader.ReadLineString())
    // Reading the number of test cases (n) from the input using the ReadLineString() method of the bufio.Reader object
    // and converting it to an integer using the Atoi() function of the strconv package

    a := 0
    // Declaring and initializing an integer variable 'a' with zero value

    for i := 0; i < n; i++ {
        num, _ := strconv.Atoi(reader.ReadLineString())
        // Reading each number in each test case from the input using the ReadLineString() method of the bufio.Reader object
        // and converting it to an integer using the Atoi() function of the strconv package
        // and adding it to the variable 'a'
    }

    b := 0
    // Declaring and initializing an integer variable 'b' with zero value

    for i := 0; i < n-1; i++ {
        num, _ := strconv.Atoi(reader.ReadLineString())
        // Reading each number in each test case (except the last one) from the input using the ReadLineString() method of the bufio.Reader object
        // and converting it to an integer using the Atoi() function of the strconv package
        // and adding it to the variable 'b'
    }

    c := 0
    // Declaring and initializing an integer variable 'c' with zero value

    for i := 0; i < n-2; i++ {
        num, _ := strconv.Atoi(reader.ReadLineString())
        // Reading each number in each test case (except the last two) from the input using the ReadLineString() method of the bufio.Reader object
        // and converting it to an integer using the Atoi() function of the strconv package
        // and adding it to the variable 'c'
    }

    x := a - b
    // Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    y := b - c
    // Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    fmt.Println(x)
    fmt.Println(y)
    // Printing the values of 'x' and 'y' to the standard output using the println() function of the fmt package
}

Translate the above Go code to C++ and end with comment "