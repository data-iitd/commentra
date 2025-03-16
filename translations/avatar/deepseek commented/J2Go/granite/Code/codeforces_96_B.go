
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new Scanner object to read input from the user
    in := bufio.NewReader(os.Stdin)
    
    // Read a string input from the user
    str, _ := in.ReadString('\n')
    
    // Convert the string input to a long integer and store it in the number variable
    number, _ := strconv.ParseInt(str, 10, 64)
    
    // Initialize two variables, ans and value, to -1 and 0, respectively
    ans, value := int64(-1), int64(0)
    
    // Set a mask variable to 2
    mask := 2
    
    // The code enters a for loop that continues as long as value is less than the input number
    for value < number {
        // Convert the mask value to a binary string, remove the first character, and store the result in the s variable
        s := fmt.Sprintf("%b", mask)
        s = s[1:]
        
        // Count the number of zeros in the binary string and store it in the zeros variable
        zeros := 0
        for _, c := range s {
            if c == '0' {
                zeros++
            }
        }
        
        // If the number of zeros is not equal to the number of ones, skip the rest of the loop and increment the mask
        if zeros!= len(s)-zeros {
            mask++
            continue
        }
        
        // Replace all zeros with 4 and all ones with 7 in the binary string and convert it back to a long integer
        s = strings.Replace(s, "0", "4", -1)
        s = strings.Replace(s, "1", "7", -1)
        value, _ = strconv.ParseInt(s, 10, 64)
    }
    
    // Print the value variable
    fmt.Println(value)
}

