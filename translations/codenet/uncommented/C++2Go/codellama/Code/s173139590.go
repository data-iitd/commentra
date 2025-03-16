package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	ac_count := 0
	wa_count := 0
	tle_count := 0
	re_count := 0
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		if s == "AC" {
			ac_count++
		} else if s == "WA" {
			wa_count++
		} else if s == "TLE" {
			tle_count++
		} else if s == "RE" {
			re_count++
		}
	}
	fmt.Println("AC x", ac_count)
	fmt.Println("WA x", wa_count)
	fmt.Println("TLE x", tle_count)
	fmt.Println("RE x", re_count)
}

