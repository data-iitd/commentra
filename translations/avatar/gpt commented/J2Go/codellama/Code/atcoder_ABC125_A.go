package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the user
	sc := new(Scanner)

	// Reading the number of seconds from user input
	sec, _ := strconv.Atoi(sc.Next())

	// Reading the number of items per interval from user input
	per_num, _ := strconv.Atoi(sc.Next())

	// Reading the maximum time limit, adding 0.5 to ensure proper rounding
	max_sec, _ := strconv.ParseFloat(sc.Next(), 64)
	max_sec += 0.5

	// Initializing a variable to hold the total count of items
	ans_num := 0

	// Looping from 'sec' to 'max_sec' in increments of 'sec'
	for i := sec; i < max_sec; i += sec {
		// Accumulating the total number of items produced
		ans_num += per_num
	}

	// Outputting the total number of items produced
	fmt.Println(ans_num)
}

// 