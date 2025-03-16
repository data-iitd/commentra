
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Take an integer input N and a string input S from the user
	N, _ := strconv.Atoi(read(reader))
	S := read(reader)

	// Define a function calculate that takes two arguments: an integer n and a string s
	calculate(N, S)
}

func calculate(n int, s string) {
	// Create a list arr from the string s
	arr := []rune(s)

	// Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
	rNum := 0
	gNum := 0
	bNum := 0
	for _, c := range arr {
		switch c {
		case 'R':
			rNum++
		case 'G':
			gNum++
		case 'B':
			bNum++
		}
	}

	// Initialize a variable sum to 0
	sum := 0

	// Use a for loop to iterate through each step from 1 to the ceiling of N/2
	for step := 1; step <= int(math.Ceil(float64(n)/2)); step++ {
		// Inside the inner for loop, join three consecutive elements of the list arr to form a string s
		s := string(arr[0]) + string(arr[1]) + string(arr[2])

		// Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
		switch s {
		case "RGB", "RBG", "BGR", "BRG", "GBR", "GRB":
			sum++
		}

		// Rotate the list arr by one position to the left
		arr = append(arr[1:], arr[0])
	}

	// After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
	fmt.Println(rNum * gNum * bNum - sum)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

