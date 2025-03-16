package main

import (
	"fmt"
)

func main() {
	var y int
	fmt.Scan(&y)
	leap := checkLeap(y)
	sum := 0

	for i := y + 1; ; i++ {
		if checkLeap(i) {
			sum += 366
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if (checkLeap(i) && leap) || (!checkLeap(i) && !leap) {
				fmt.Println(i)
				return
			}
		}
	}
}

func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100 != 0)
}

// <END-OF-CODE>
