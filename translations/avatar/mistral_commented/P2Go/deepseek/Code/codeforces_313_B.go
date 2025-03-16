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
	
	// Take input string 'soz' from the user
	soz, _ := reader.ReadString('\n')
	soz = strings.TrimSpace(soz)
	
	// Initialize an array 'a' of size 'len(soz)+1' with zeros
	a := make([]int, len(soz)+1)
	
	// Iterate through the string 'soz' starting from index 1
	for i := 1; i < len(soz); i++ {
		// Assign the value of the previous index to the current index
		a[i] = a[i - 1]
		
		// If the current character is same as the previous character, increment the count
		if soz[i - 1] == soz[i] {
			a[i] += 1
		}
	}
	
	// Take the number of test cases 'n' as input
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	
	// Initialize an empty list 'arr' to store the differences
	arr := []int{}
	
	// Iterate through the test cases
	for i := 0; i < n; i++ {
		// Take two integers 'm' and 'l' as input, separated by a space
		input, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(input), " ")
		m, _ := strconv.Atoi(parts[0])
		l, _ := strconv.Atoi(parts[1])
		
		// Calculate the difference between the count at index 'l' and index 'm'
		arr = append(arr, a[l] - a[m])
	}
	
	// Iterate through the list 'arr' and print each difference
	for _, i := range arr {
		fmt.Println(i)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}
