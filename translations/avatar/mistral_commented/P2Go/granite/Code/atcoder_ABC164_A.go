
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader( os.Stdin )

    // Get the input as a list of two integers, S and W, using the Scan function
    S, _ := strconv.Atoi( reader.Scan() )
    W, _ := strconv.Atoi( reader.Scan() )

    // Check if the condition S <= W is true or false and print the corresponding message
    if S <= W {
        fmt.Println( "unsafe" )
    } else {
        fmt.Println( "safe" )
    }
}

// 