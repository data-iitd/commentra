

package main // Defining the main package named main

import ( // Importing the necessary packages
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() { // Defining the main function that is executed when the program runs
    reader := bufio.NewReader(os.Stdin) // Creating a new bufio.Reader object named reader to read input from the standard input stream
    n, _ := strconv.Atoi(reader.ReadLine()) // Reading the number of elements in the ArrayList from the standard input stream and converting it to an integer

    a := make([]int, n) // Creating an empty slice named a of type int with a length equal to the number of elements

    for i := 0; i < n; i++ { // Using a for loop to read and store each element in the slice
        value, _ := strconv.Atoi(reader.ReadLine()) // Reading an integer value from the standard input stream and converting it to an integer
        a[i] = value // Storing the value in the corresponding index of the slice
    }

    result, pos, flag := 0, 0, 0 // Declaring and initializing the variables result, pos, and flag

    if a[0] > 15 { // Checking if the first element in the slice is greater than 15
        result = 15 // Assigning 15 to the result variable if the condition is true
    } else {
        for i := 1; i < n; i++ { // Using a for loop to compare each element with the previous one
            if a[i]-a[i-1] > 15 { // Checking if the difference between two consecutive elements is greater than 15
                pos = i - 1 // Assigning the index of the previous element to the pos variable if the condition is true
                flag = 1 // Assigning 1 to the flag variable to indicate that the condition is true
                break // Exiting the loop if the condition is true
            }
        }
        if flag == 1 { // Checking if the flag variable is equal to 1, indicating that the condition in the inner for loop was true
            result = a[pos] + 15 // Assigning the sum of the previous element and 15 to the result variable
        } else {
            result = a[n-1] + 15 // Assigning the sum of the last element and 15 to the result variable if the flag variable is 0
        }
    }

    if result > 90 { // Checking if the result is greater than 90 and assigning 90 to the result variable if it is
        result = 90 // Assigning 90 to the result variable if the condition is true
    }

    fmt.Println(result) // Printing the result to the standard output stream

Translate the above Go code to C++ and end with comment "