package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner object to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Reading the number of seconds from user input
	var sec int
	fmt.Fscan(reader, &sec)

	// Reading the number of items per interval from user input
	var per_num int
	fmt.Fscan(reader, &per_num)

	// Reading the maximum time limit, adding 0.5 to ensure proper rounding
	var max_sec float64
	fmt.Fscan(reader, &max_sec)
	max_sec += 0.5

	// Initializing a variable to hold the total count of items
	var ans_num int

	// Looping from'sec' to'max_sec' in increments of'sec'
	for i := sec; i < int(max_sec); i += sec {
		// Accumulating the total number of items produced
		ans_num += per_num
	}

	// Outputting the total number of items produced
	fmt.Println(ans_num)
}

