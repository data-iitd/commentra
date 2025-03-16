
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var y int
	var leap bool
	var sum int
	var mod int
	var i int

	y = get_input()
	leap = check_leap(y)
	sum = 0
	mod = 0
	for i = y + 1; ; i++ {
		if check_leap(i) {
			sum += 366
		} else {
			sum += 365
		}
		if sum%7 == 0 {
			if (check_leap(i) && leap) || (!check_leap(i) && !leap) {
				fmt.Println(i)
				return
			} else {
				continue
			}
		}
	}
}

func get_input() int {
	var y int
	var err error
	var input string

	input = os.Args[1]
	y, err = strconv.Atoi(input)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	return y
}

func check_leap(y int) bool {
	if y%400 == 0 || (y%4 == 0 && y%100 != 0) {
		return true
	} else {
		return false
	}
}

