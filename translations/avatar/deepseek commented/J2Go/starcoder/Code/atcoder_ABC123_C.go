
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the value of N
	N, _ := strconv.ParseInt(readLine(), 10, 64)

	// Initialize min to 0 and find the minimum of the first five inputs
	min := 0
	for i := 0; i < 5; i++ {
		if i == 0 {
			min, _ = strconv.ParseInt(readLine(), 10, 64)
		} else {
			temp, _ := strconv.ParseInt(readLine(), 10, 64)
			if temp < min {
				min = temp
			}
		}
	}

	// Calculate the result and print it
	fmt.Println(int(math.Ceil((float64(N) / float64(min))) + 4))
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

