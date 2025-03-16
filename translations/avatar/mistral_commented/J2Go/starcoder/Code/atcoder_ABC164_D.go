
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
	S := strings.TrimSpace(readLine(reader))
	N := len(S)

	mod_arr := make([]int, N)
	mod_cnt := make([]int, 2019)
	radix := 1

	for i := 0; i < N; i++ {
		tmp := 0

		// Calculating the value of the current digit in the given base
		tmp = int(S[N-1-i]-'0')*radix % 2019

		// Updating the temporary variable with the carry from the previous digit
		if i!= 0 {
			tmp = (tmp + mod_arr[i-1]) % 2019
		}

		// Storing the intermediate result in the array
		mod_arr[i] = tmp

		// Updating the frequency count of the current number in the array
		mod_cnt[tmp]++

		// Updating the radix for the next iteration
		radix = radix * 10 % 2019
	}

	ans := int64(0)

	// Calculating the answer by summing up the terms of the formula
	for i := 0; i < 2019; i++ {
		ans += int64(mod_cnt[i]) * (int64(mod_cnt[i]) - 1) / 2
	}

	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

