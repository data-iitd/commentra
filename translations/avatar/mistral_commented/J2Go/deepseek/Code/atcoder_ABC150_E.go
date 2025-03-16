package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	sa, _ := reader.ReadString('\n')
	sa = sa[:len(sa)-1] // Remove the newline character
	saSlice := splitString(sa, " ")
	n, _ := strconv.Atoi(saSlice[0])
	saSlice, _ = reader.ReadString('\n')
	saSlice = saSlice[:len(saSlice)-1] // Remove the newline character
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(saSlice[i])
	}
	mod := int(1e9 + 7)
	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}
	sort.Ints(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := 0
	for i := 2; i <= n+1; i++ {
		val := a * int(i) % mod
		val *= c[n+1-i]
		val %= mod
		ans += val
		ans %= mod
	}
	ans *= b
	ans %= mod
	fmt.Println(ans)
}

func splitString(s, delimiter string) []string {
	var result []string
	for len(s) > 0 {
		index := 0
		if delimiter != "" {
			index = indexOf(s, delimiter)
		}
		if index == -1 {
			result = append(result, s)
			break
		}
		result = append(result, s[:index])
		s = s[index+len(delimiter):]
	}
	return result
}

func indexOf(s, substr string) int {
	for i := 0; i < len(s); i++ {
		if s[i:i+len(substr)] == substr {
			return i
		}
	}
	return -1
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	val *= val
	if n%2 == 1 {
		val *= x
	}
	val %= int(1e9 + 7)
	return val
}

