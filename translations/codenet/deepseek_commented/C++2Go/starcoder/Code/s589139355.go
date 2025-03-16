<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables
    var a, t, h, lt, lh, tt, hh, l int
    var taro, hana string

    // Read the number of games
    a, _ = strconv.Atoi(os.Args[1])

    // Loop through the number of games
    for i := 0; i < a; i++ {
        // Read the names of Taro and Hana
<<<<<<< HEAD
        taro, hana = strings.Fields(os.Args[2+i])[0], strings.Fields(os.Args[2+i])[1]
=======
        taro = strings.TrimSpace(fmt.Scanln())
        hana = strings.TrimSpace(fmt.Scanln())
>>>>>>> 98c87cb78a (data updated)

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
<<<<<<< HEAD
        tt, hh = 0, 0
=======
        tt = 0
        hh = 0
>>>>>>> 98c87cb78a (data updated)

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

