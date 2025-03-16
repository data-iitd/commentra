
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Input the number of princess's power
    princess, _ := strconv.Atoi(readLine())
    // Input the number of dragon's power
    dragon, _ := strconv.Atoi(readLine())
    // Input the initial time
    t, _ := strconv.Atoi(readLine())
    // Input the time increment
    f, _ := strconv.Atoi(readLine())
    // Input the target power level
    c, _ := strconv.Atoi(readLine())

    // Check if the dragon's power is less than or equal to the princess's power
    if dragon <= princess {
        fmt.Println(0)
        return
    }

    result := 0                // Initialize the result counter
    position := t * princess   // Calculate the initial position based on time and princess's power
    position += princess * position / (dragon - princess)  // Adjust the position based on the given formula

    // Enter a while loop that continues until the position is greater than or equal to the target power level
    for position < c {
        result += 1         // Increment the result counter
        position += princess * position / dragon  // Update the position based on the dragon's power
        position += princess * f  // Add the time increment to the position
        position += princess * position / (dragon - princess)  // Adjust the position based on the given formula
    }

    fmt.Println(result)            // Print the number of attacks needed
}

func readLine() string {
    var (
        buf byt
        a   []byt
        i   int = 0
    )
    for {
        if i == len(a) {
            a = make([]byt, 1024)
            buf = make([]byt, 1024)
            n, err := os.Stdin.Read(buf)
            if err!= nil {
                panic(err)
            }
            a = buf[:n]
            i = 0
        }
        if a[i] == '\n' {
            tmp := a[0:i]
            a = a[i + 1:]
            return string(tmp)
        }
        i++
    }
}

