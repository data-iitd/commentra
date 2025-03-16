package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Read the first long integer input N
	scanner.Scan()
	N, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	// Initialize the minimum long integer variable with the first input value
	var min int64 = 0
	for i := 0; i < 5; i++ {
		scanner.Scan()
		current, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		if i == 0 {
			min = current
		} else {
			if current < min {
				min = current
			}
		}
	}

	// Print the answer using the p method
	fmt.Println(int64(math.Ceil(float64(N)/float64(min))) + 4)
}

