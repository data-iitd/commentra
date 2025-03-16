package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Read the number of elements and the modulo value
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	
	// Read the array of elements
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	parts = strings.Split(line, " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(parts[i])
	}
	
	// HashMap to store the frequency of remainders
	dp := make(map[int]int)
	
	// Initialize the answer and base variable
	var ans int64 = 0
	var base int = 0
	
	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base variable
		base = (base - a[i] % m + m) % m
		
		// Update the frequency of remainders in the map
		dp[(base + a[i]) % m]++
		
		// Add the frequency of the current remainder to the answer
		ans += int64(dp[base])
	}
	
	// Print the final answer
	fmt.Fprintln(writer, ans)
}
