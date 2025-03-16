package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the values of N and M from the standard input
	line, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(line[:len(line)-1])
	line, _ = reader.ReadString('\n')
	M, _ := strconv.Atoi(line[:len(line)-1])
	
	// Read the array A from the standard input
	line, _ = reader.ReadString('\n')
	A := []int{}
	for _, s := range strings.Split(line[:len(line)-1], " ") {
		num, _ := strconv.Atoi(s)
		A = append(A, num)
	}
	
	// Calculate the cumulative remainders of the array A modulo M
	// Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
	cumRemainders := []int{0}
	for _, a := range A {
		cumRemainders = append(cumRemainders, (cumRemainders[len(cumRemainders)-1]+a)%M)
	}
	
	// Count the occurrences of each remainder
	remainderCounts := make(map[int]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}
	
	// Initialize the number of combinations
	combinations := 0
	
	// Calculate the number of combinations where the difference between two remainders is a multiple of M
	for _, count := range remainderCounts {
		combinations += count * (count - 1) / 2
	}
	
	// Print the number of combinations
	fmt.Println(combinations)
}
