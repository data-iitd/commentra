package main

import (
	"fmt"
	"strconv"
)

func leapyear(n int) string {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
		return "y"
	} else {
		return "n"
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	d := "f"
	ans := "nly"
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
		ans = "ly"
	}

	for {
		if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
			if (d == "m") {
				d = "w"
				n += 1
			} else if (d == "t") {
				d = "th"
				n += 1
			} else if (d == "w") {
				d = "f"
				n += 1
			} else if (d == "th") {
				d = "sa"
				n += 1
			} else if (d == "f") {
				d = "s"
				n += 1
			} else if (d == "sa") {
				d = "m"
				n += 1
			} else if (d == "s") {
				d = "t"
				n += 1
			}
		} else {
			if (d == "m") {
				d = "t"
				n += 1
			} else if (d == "t") {
				d = "w"
				n += 1
			} else if (d == "w") {
				d = "th"
				n += 1
			} else if (d == "th") {
				d = "f"
				n += 1
			} else if (d == "f") {
				d = "sa"
				n += 1
			} else if (d == "sa") {
				d = "s"
				n += 1
			} else if (d == "s") {
				d = "m"
				n += 1
			}
		}

		if (d == "f" && ans == "ly" && leapyear(n) == "y") {
			break
		} else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
			break
		}
	}

	fmt.Println(n)
}

