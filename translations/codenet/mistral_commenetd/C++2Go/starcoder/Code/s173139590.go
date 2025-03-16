
<<<<<<< HEAD

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
=======
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
>>>>>>> 98c87cb78a (data updated)
)

// Initialize variables to store the number of each contest result
var n int
var ac_count int
var wa_count int
var tle_count int
var re_count int

func main() {
<<<<<<< HEAD
    // Read the number of contest results from the standard input
    fmt.Scanln(&n)

    // Read each contest result and update the corresponding counter
    for i := 0; i < n; i++ {
        s := strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
        if s == "AC" { // if the contest result is AC
            ac_count++ // increment the number of AC results
        } else if s == "WA" { // if the contest result is WA
            wa_count++ // increment the number of WA results
        } else if s == "TLE" { // if the contest result is TLE
            tle_count++ // increment the number of TLE results
        } else if s == "RE" { // if the contest result is RE
            re_count++ // increment the number of RE results
        }
    }

    // Print the number of each contest result to the standard output
    fmt.Printf("AC x %d\n", ac_count)
    fmt.Printf("WA x %d\n", wa_count)
    fmt.Printf("TLE x %d\n", tle_count)
    fmt.Printf("RE x %d\n", re_count)
=======
	// Read the number of contest results from the standard input
	fmt.Scanln(&n)

	// Read each contest result and update the corresponding counter
	for i := 0; i < n; i++ {
		s := ""
		fmt.Scanln(&s)
		if s == "AC" { // if the contest result is AC
			ac_count++ // increment the number of AC results
		} else if s == "WA" { // if the contest result is WA
			wa_count++ // increment the number of WA results
		} else if s == "TLE" { // if the contest result is TLE
			tle_count++ // increment the number of TLE results
		} else if s == "RE" { // if the contest result is RE
			re_count++ // increment the number of RE results
		}
	}

	// Print the number of each contest result to the standard output
	fmt.Printf("AC x %d\n", ac_count)
	fmt.Printf("WA x %d\n", wa_count)
	fmt.Printf("TLE x %d\n", tle_count)
	fmt.Printf("RE x %d\n", re_count)
>>>>>>> 98c87cb78a (data updated)
}

