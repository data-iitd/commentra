
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

const (
	N_MAX = 100
	P_MAX = 100
	DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func abss(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

func strrstr(string, pattern string) string {
	offset := 0
	lastP := ""

	searchResult := ""
	for searchResult = strings.Index(string[offset:], pattern); searchResult!= -1 && string[offset]!= '\0'; offset++ {
		lastP = searchResult
		offset++
	}

	return lastP
}

func compareF(a, b *size_t) int {
	if *a < *b {
		return -1
	}
	return 1
}

func comb(n, r size_t) size_t {
	result := size_t(1)

	for i := size_t(0); i < r; i++ {
		result *= n - i
		result /= i + 1
	}

	return result
}

func gcd(m, n uint64) uint64 {
	temp := n
	for m%n!= 0 {
		temp = n
		n = m % n
		m = temp
	}

	return n
}

func main() {
	const patternBase = "keyence"
	var top [8]byte
	var bottom [8]byte
	var S [101]byte

	fmt.Fscanf(bufio.NewReader(os.Stdin), "%s", S[:])

	len := len(S)
	found := false

	for offset := 0; offset < len(patternBase); offset++ {
		copy(top[:], patternBase[:offset])
		top[offset] = '\0'
		copy(bottom[:], patternBase[offset:])
		bottom[len(patternBase)-offset] = '\0'

		topSearch := strings.Index(string(S[:]), string(top[:]))
		if topSearch!= -1 {
			bottomSearch := strrstr(S[topSearch+offset:], string(bottom[:]))
			if bottomSearch!= "" {
				sepCount := 0

				if topSearch!= 0 {
					sepCount++
				}
				if topSearch+offset!= bottomSearch {
					sepCount++
				}
				if bottomSearch[len(bottom)-1]!= '\0' {
					sepCount++
				}

				if sepCount <= 1 {
					found = true
					break
				}
			}
		}
	}

	fmt.Println(func() string {
		if found {
			return "YES"
		}
		return "NO"
	}())
}

