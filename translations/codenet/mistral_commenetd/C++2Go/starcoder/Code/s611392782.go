
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to calculate the multiplication part of the expression
func mul(str string, idx *int) int {
    res, _ := strconv.Atoi(string(str[*idx])) // Extract the first digit and store it in'res'
    for *idx = *idx + 1; *idx < len(str) && str[*idx] == '*'; *idx = *idx + 2 { // Check if there is a '*' symbol
        res = res * int(str[*idx]) - '0' // Multiply'res' with the next digit
    }
    return res // Return the final result
}

// Function to calculate the addition part of the expression
func add(str string, idx *int) int {
    res := mul(str, idx) // Call the'mul' function to calculate the multiplication part
    for *idx = *idx + 1; *idx < len(str) && str[*idx] == '+'; *idx = *idx + 2 { // Check if there is a '+' symbol
        res = res + mul(str, idx) // Add the result of the next multiplication part
    }
    return res // Return the final result
}

// Function to calculate the whole expression
func bob(str string, idx *int) int {
    res, _ := strconv.Atoi(string(str[*idx])) // Extract the first digit and store it in'res'
    for *idx = *idx + 1; *idx < len(str); *idx = *idx + 2 { // Loop through the rest of the expression
        if str[*idx] == '+' {
            res = res + int(str[*idx+1]) - '0' // If there is a '+' symbol, add the next digit
        } else {
            res = res * int(str[*idx+1]) - '0' // If there is a '*' symbol, multiply the next digit
        }
    }
    return res // Return the final result
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        str, _ := reader.ReadString('\n')
        str = strings.TrimSpace(str)
        if str == "" {
            break
        }
        idx := 0
        a := add(str, &idx)
        idx = 0
        b := bob(str, &idx)
        if a == b {
            fmt.Println("U")
        } else if a > b {
            fmt.Println("M")
        } else {
            fmt.Println("L")
        }
    }
}

