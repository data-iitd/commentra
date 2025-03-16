
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)
    
    // Reading the number of seconds from user input
    scanner.Scan()
    sec, _ := strconv.Atoi(scanner.Text())
    
    // Reading the number of items per interval from user input
    scanner.Scan()
    per_num, _ := strconv.Atoi(scanner.Text())
    
    // Reading the maximum time limit, adding 0.5 to ensure proper rounding
    scanner.Scan()
    max_sec, _ := strconv.ParseFloat(scanner.Text(), 64)
    max_sec += 0.5
    
    // Initializing a variable to hold the total count of items
    ans_num := 0
    
    // Looping from'sec' to'max_sec' in increments of'sec'
    for i := sec; i < max_sec; i += sec {
        // Accumulating the total number of items produced
        ans_num += per_num
    }
    
    // Outputting the total number of items produced
    fmt.Println(ans_num)
}

