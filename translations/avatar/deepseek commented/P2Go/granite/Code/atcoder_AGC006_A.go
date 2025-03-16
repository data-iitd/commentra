

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	s := readLine(reader)

	t := readLine(reader)

	result := makeStringsEqual(n, s, t)

	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func makeStringsEqual(n int32, s string, t string) int32 {
	// Check if the strings `s` and `t` are equal
	if s == t {
		return n
	}

	cnt := int32(0) // Initialize the counter `cnt` to 0

	// Compare characters of `s` and `t` starting from each index `i` of `s`
	for i := int32(0); i < n; i++ {
		for j := int32(0); j < n-i; j++ {
			// If a mismatch is found, break out of the inner loop
			if string(s[i+j])!= string(t[j]) {
				break
			}
			// If the end of the inner string is reached without breaking, set `cnt`
			if j == n-i-1 {
				cnt = n - i
			}
		}
	}

	// Return `2 * n - cnt`
	return 2*n - cnt
}

