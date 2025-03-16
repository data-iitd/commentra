
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read two integers from input: S (the strength) and W (the weight)
    reader := bufio.NewReader(os.Stdin)
    S, _ := strconv.Atoi(reader.ReadLine())
    W, _ := strconv.Atoi(reader.ReadLine())
    
    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

// 