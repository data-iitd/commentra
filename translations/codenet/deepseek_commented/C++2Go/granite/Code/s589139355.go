
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables
    var a int
    var t, h, lt, lh, tt, hh, l int
    var taro, hana string
    var err error
    var reader = bufio.NewReader(os.Stdin)

    // Read the number of games
    a, err = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    checkError(err)

    // Loop through the number of games
    for i := 0; i < a; i++ {
        // Read the names of Taro and Hana
        taro, hana = readLine(reader), readLine(reader)

        // Get the lengths of the names
        lt = len(taro)
        lh = len(hana)

        // Determine the maximum length of the names
        if lt > lh {
            l = lt
        } else {
            l = lh
        }

        // Initialize score counters for this round
        tt = 0
        hh = 0

        // Compare the names and update the scores
        if taro > hana {
            t = t + 3
        } else if hana > taro {
            h = h + 3
        } else if hana == taro {
            h = h + 1
            t = t + 1
        }
    }

    // Output the final scores
    fmt.Println(t, h)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

