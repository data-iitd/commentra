
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define a tuple 'ABC' by splitting a user input by space and converting each element to integer using the Atoi() function
	ABC := tuple(strings.Split(reader.ReadString(), " "))

	// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
	if count(ABC, 5) == 2 {
		// If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
		if sum(ABC) == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		// If the condition is not met, print 'NO'
		fmt.Println("NO")
	}
}

func tuple(ABC []string) []int {
	var result []int
	for _, v := range ABC {
		i, _ := strconv.Atoi(v)
		result = append(result, i)
	}
	return result
}

func count(ABC []int, target int) int {
	var result int
	for _, v := range ABC {
		if v == target {
			result++
		}
	}
	return result
}

func sum(ABC []int) int {
	var result int
	for _, v := range ABC {
		result += v
	}
	return result
}

var reader = bufio.NewReader(os.Stdin)

