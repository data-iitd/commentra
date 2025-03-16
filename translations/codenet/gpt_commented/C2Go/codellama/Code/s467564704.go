package main

import "fmt"

func main() {
    // Declare a 4x4 array to hold input values and a variable for test cases
    input := [4][4]int{}
    var tc int

    // Read 3x3 input values from the user
    for i := 0; i < 3; i++ {
        for j := 0; j < 3; j++ {
            fmt.Scan(&input[i][j]) // Store each input value in the array
        }
    }

    // Read the number of test cases
    fmt.Scan(&tc)
    var testcase int

    // Process each test case
    for i := 0; i < tc; i++ {
        fmt.Scan(&testcase) // Read the current test case value

        // Check the input array for the testcase value and set it to 0 if found
        for i := 0; i < 3; i++ {
            for j := 0; j < 3; j++ {
                if input[i][j] == testcase {
                    input[i][j] = 0 // Replace the found value with 0
                }
            }
        }
    }

    // Check for winning conditions in the modified input array
    if input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0 { // Check diagonal from top-left to bottom-right
        fmt.Println("Yes")
    } else if input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0 { // Check diagonal from top-right to bottom-left
        fmt.Println("Yes")
    } else if input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0 { // Check first row
        fmt.Println("Yes")
    } else if input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0 { // Check second row
        fmt.Println("Yes")
    } else if input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0 { // Check third row
        fmt.Println("Yes")
    } else if input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0 { // Check first column
        fmt.Println("Yes")
    } else if input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0 { // Check second column
        fmt.Println("Yes")
    } else if input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0 { // Check third column
        fmt.Println("Yes")
    } else {
        fmt.Println("No") // If no winning condition is met, output "No"
    }
}

