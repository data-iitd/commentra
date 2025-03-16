
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Define a constant variable N, which is the input number
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])

	// Define a list A, which consists of five integers, each input as a separate line
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		A[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])
	}

	// Calculate the minimum value in the list A
	min_value := A[0]
	for i := 1; i < 5; i++ {
		if A[i] < min_value {
			min_value = A[i]
		}
	}

	// Calculate the ceiling value of N divided by the minimum value in the list A
	ceiling_value := int(math.Ceil(float64(N) / float64(min_value)))

	// Add 4 to the ceiling value to get the final answer
	final_answer := ceiling_value + 4

	// Print the final answer
	fmt.Println(final_answer)
}
