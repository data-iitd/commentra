package main

import (
	"fmt"
	"time"
)

func main() {
	var y int
	fmt.Scan(&y)
	leap := checkLeap(y)
	sum := 0
	for {
		y++
		if checkLeap(y) {
			sum += 366
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if (checkLeap(y) && leap) || (!checkLeap(y) && !leap) {
				fmt.Println(y)
				return
			}
		}
	}
}

func checkLeap(y int) bool {
	return y%400 == 0 || (y%4 == 0 && y%100 != 0)
}

