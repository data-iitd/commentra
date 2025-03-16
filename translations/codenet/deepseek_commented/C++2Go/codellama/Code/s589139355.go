package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables
	var a, t, h, lt, lh, tt, hh, l int
	var taro, hana string

	// Get the number of games
	a, _ = strconv.Atoi(os.Args[1])

	// Loop through the number of games
	for i := 0; i < a; i++ {
		// Read the names of Taro and Hana
		taro = os.Args[2+i*2]
		hana = os.Args[3+i*2]

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

