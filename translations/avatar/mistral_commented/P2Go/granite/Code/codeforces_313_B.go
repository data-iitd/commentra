
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Take input string'soz' from the user
	soz := readString()

	// Initialize an array 'a' of size 'len(soz)+1' with zeros
	a := make([]int, len(soz)+1)

	// Iterate through the string'soz' starting from index 1
	for i := 1; i < len(soz); i++ {
		// Assign the value of the previous index to the current index
		a[i] = a[i-1]

		// If the current character is same as the previous character, increment the count
		if soz[i-1] == soz[i] {
			a[i] += 1
		}
	}

	// Take the number of test cases 'n' as input
	n := readInt()

	// Initialize an empty list 'arr' to store the differences
	arr := make([]int, n)

	// Iterate through the test cases
	for i := 0; i < n; i++ {
		// Take two integers'm' and 'l' as input, separated by a space
		m, l := readTwoInts()

		// Calculate the difference between the count at index 'l' and index'm'
		arr[i] = a[l-1] - a[m-1]
	}

	// Iterate through the list 'arr' and print each difference
	for _, v := range arr {
		fmt.Println(v)
	}
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readTwoInts() (int, int) {
	res := make([]int, 2)
	scanner := bufio.NewScanner(os.Stdin)
	x := 0
	scanner.Scan()
	for _, num := range strings.Split(scanner.Text(), " ") {
		val, _ := strconv.Atoi(num)
		res[x] = val
		x++
	}
	return res[0], res[1]
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

