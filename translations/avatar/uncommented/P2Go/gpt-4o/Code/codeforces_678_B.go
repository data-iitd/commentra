package main

import (
	"fmt"
)

func leapYear(n int) string {
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		return "y"
	}
	return "n"
}

func main() {
	var n int
	fmt.Scan(&n)

	d := "f"
	var ans string
	if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
		ans = "ly"
	} else {
		ans = "nly"
	}

	for {
		if n%400 == 0 || (n%4 == 0 && n%100 != 0) {
			switch d {
			case "m":
				d = "w"
				n++
			case "t":
				d = "th"
				n++
			case "w":
				d = "f"
				n++
			case "th":
				d = "sa"
				n++
			case "f":
				d = "s"
				n++
			case "sa":
				d = "m"
				n++
			case "s":
				d = "t"
				n++
			}
		} else {
			switch d {
			case "m":
				d = "t"
				n++
			case "t":
				d = "w"
				n++
			case "w":
				d = "th"
				n++
			case "th":
				d = "f"
				n++
			case "f":
				d = "sa"
				n++
			case "sa":
				d = "s"
				n++
			case "s":
				d = "m"
				n++
			}
		}

		if d == "f" && ans == "ly" && leapYear(n) == "y" {
			break
		} else if d == "f" && ans == "nly" && leapYear(n) == "n" {
			break
		}
	}
	fmt.Println(n)
}

// <END-OF-CODE>
