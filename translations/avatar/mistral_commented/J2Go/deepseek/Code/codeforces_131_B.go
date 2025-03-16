package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of test cases from the console
	scanner.Scan()
	n := parseInt(scanner.Text())

	// Define the maximum size of the array to avoid array out of bounds exception
	const N = 1e5 + 5

	// Initialize an array to store the count of each number
	cnt := make([]int64, 21)

	// Read the numbers one by one and update the count array accordingly
	for i := 0; i < n; i++ {
		scanner.Scan()
		num := parseInt(scanner.Text())
		cnt[int64(num)+10]++
	}

	// Calculate the result using the given formula
	var res int64 = 0
	for i := 0; i < 10; i++ {
		res += cnt[int64(i)] * cnt[20-int64(i)]
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2

	// Print the result to the console
	fmt.Println(res)
}

func parseInt(s string) int64 {
	var res int64
	for _, c := range s {
		res = res*10 + int64(c-'0')
	}
	return res
}

