package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
)

func main() {
	// Read the value of N
	reader := bufio.NewReader(os.Stdin)
	N, _ := readLong(reader)

	// Initialize min to 0 and find the minimum of the first five inputs
	min := int64(0)
	for i := 0; i < 5; i++ {
		if i == 0 {
			min, _ = readLong(reader)
		} else {
			current, _ := readLong(reader)
			if current < min {
				min = current
			}
		}
	}

	// Calculate the result and print it
	result := int64(math.Ceil(float64(N) / float64(min))) + 4
	fmt.Println(result)
}

// Helper function to read long from reader
func readLong(reader *bufio.Reader) (int64, error) {
	var num int64
	_, err := fmt.Fscan(reader, &num)
	return num, err
}
