<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, D, X int
	var num_of_chocolate int
	var counter int
	var days int
	var A [101]int

	// Input reading
	fmt.Scanf("%d %d %d", &N, &D, &X)

	// Array initialization
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Reading values into array A
	for i := 0; i < N; i++ {
		days = 0
		counter = 0
		for j := 0; ; j++ {
			days = j*A[i] + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		num_of_chocolate = num_of_chocolate + counter
	}

	// Adding extra chocolates
	num_of_chocolate = num_of_chocolate + X

	// Output the result
	fmt.Println(num_of_chocolate)
}

