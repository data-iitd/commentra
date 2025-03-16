

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables N and D using bufio.Scanln function
	reader := bufio.NewScanner(os.Stdin)
	reader.Scan()
	line := reader.Text()
	N, _ := strconv.Atoi(line[0:1])
	D, _ := strconv.Atoi(line[2:3])

	// Calculate the quotient of N by (D*2+1) and store it in variable ans
	ans := N / (D*2 + 1)

	// Calculate the remainder of N by (D*2+1) and store it in variable rem
	rem := N % (D*2 + 1)

	// Check if the remainder is zero or not
	if rem!= 0 {
		// If the remainder is not zero, increment the value of ans by 1
		ans = ans + 1
	}

	// Print the value of ans using fmt.Println function
	fmt.Println(ans)
}

