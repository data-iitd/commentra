package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    buf := make([]byte, 512)

    // Step 3: Read input from stdin
    n, err := reader.Read(buf)
    if err != nil {
        fmt.Println("Error reading input:", err)
        return
    }

    // Step 4: Calculate the length of the input
    len := n

    // Step 5: Print the first character, the length minus 3, and the second last character of the input
    if len > 1 {
        fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
    } else {
        fmt.Println("Input too short")
    }

    // Step 6: Return 0 to indicate successful execution
}

