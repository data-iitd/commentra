package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the integer input representing the threshold
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the space-separated string input and split it into a list
	m := strings.Split(readLine(reader), " ")
	
	// Initialize a boolean variable to check if the condition is possible
	possible := true
	
	// Create a map to store the count of each element
	countMap := make(map[string]int)
	
	// Iterate over the unique elements in the list `m`
	for _, i := range m {
		countMap[i]++
	}
	
	// Iterate over the map to check if any element's count is greater than or equal to n / 2 + 1
	for _, count := range countMap {
		if count >= n / 2 + 1 {
			possible = false
			break
		}
	}
	
	// Print 'YES' if possible is True, otherwise print 'NO'
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}
