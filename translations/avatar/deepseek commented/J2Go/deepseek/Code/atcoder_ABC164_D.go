package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	S := input[:len(input)-1] // Remove the newline character
	N := len(S)
	
	// Array to store remainders at each position
	mod_arr := make([]int, N)
	// Array to count occurrences of each remainder
	mod_cnt := make([]int, 2019)
	// Radix initialized to 1 for the least significant digit
	radix := 1
	
	// Process each character in the string from right to left
	for i := 0; i < N; i++ {
		tmp := (int(S[N-1-i]) - int('0')) * radix % 2019
		if i != 0 {
			tmp = (tmp + mod_arr[i-1]) % 2019
		}
		mod_arr[i] = tmp
		mod_cnt[tmp]++
		radix = radix * 10 % 2019
	}
	
	// Calculate the number of valid pairs using combinatorics
	ans := 0
	mod_cnt[0]++ // Ensure 0 is counted
	for i := 0; i < 2019; i++ {
		ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2
	}
	
	// Output the result
	fmt.Println(ans)
}
