package main

import (
	"fmt"
)

func main() {
	// Reading the number of seconds from user input
	var sec int
	fmt.Scan(&sec)
	
	// Reading the number of items per interval from user input
	var per_num int
	fmt.Scan(&per_num)
	
	// Reading the maximum time limit, adding 0.5 to ensure proper rounding
	var max_sec float64
	fmt.Scan(&max_sec)
	
	// Initializing a variable to hold the total count of items
	ans_num := 0
	
	// Looping from 'sec' to 'max_sec' in increments of 'sec'
	for i := sec; i < int(max_sec); i += sec {
		// Accumulating the total number of items produced
		ans_num += per_num
	}
	
	// Outputting the total number of items produced
	fmt.Println(ans_num)
}
