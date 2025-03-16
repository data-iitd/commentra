
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Split the line into integers
	line = strings.TrimSpace(line)
	ABC := strings.Split(line, " ")
	// Convert the integers into integers
	ABC = convert(ABC)
	// Check if the tuple contains exactly two 5s
	if ABC.count(5) == 2 {
		// Check if the sum of the elements in ABC is 17
		if sum(ABC) == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}

func convert(arr []string) []int {
	var result []int
	for _, v := range arr {
		i, err := strconv.Atoi(v)
		if err!= nil {
			panic(err)
		}
		result = append(result, i)
	}
	return result
}

func sum(arr []int) int {
	var result int
	for _, v := range arr {
		result += v
	}
	return result
}

func count(arr []int, val int) int {
	var result int
	for _, v := range arr {
		if v == val {
			result += 1
		}
	}
	return result
}

