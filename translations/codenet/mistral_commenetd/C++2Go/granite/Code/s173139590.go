

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables to store the number of each contest result
    var n int // number of contest results to be read
    var acCount int // number of AC (Accepted) results
    var waCount int // number of WA (Wrong Answer) results
    var tleCount int // number of TLE (Time Limit Exceeded) results
    var reCount int // number of RE (Runtime Error) results

    // Read the number of contest results from the standard input
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        n, _ = strconv.Atoi(scanner.Text())
    }

    // Read each contest result and update the corresponding counter
    for i := 0; i < n; i++ {
        scanner.Scan()
        s := scanner.Text()
        switch s {
        case "AC": // if the contest result is AC
            acCount++ // increment the number of AC results
        case "WA": // if the contest result is WA
            waCount++ // increment the number of WA results
        case "TLE": // if the contest result is TLE
            tleCount++ // increment the number of TLE results
        case "RE": // if the contest result is RE
            reCount++ // increment the number of RE results
        }
    }

    // Print the number of each contest result to the standard output
    fmt.Printf("AC x %d\n", acCount)
    fmt.Printf("WA x %d\n", waCount)
    fmt.Printf("TLE x %d\n", tleCount)
    fmt.Printf("RE x %d\n", reCount)
}

