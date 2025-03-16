package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a [5]int
	var r [5]int
	var map map[int]int
	map = make(map[int]int)

	// Step 2: Reading input and storing remainders
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		r[i] = a[i] % 10
		b := 10
		if r[i]!= 0 {
			b = 10 - r[i]
			map[b] = a[i]
		}
	}

	// Step 3: Handling edge cases
	if len(map) == 0 {
		ans := 0
		for i := 0; i < len(a); i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}

	// Step 4: Finding the maximum and adjusting values
	last := map[max(map)]
	idx := 0
	for i := 0; i < len(a); i++ {
		if a[i] == last {
			idx = i
		}
	}
	ans := 0
	for i := 0; i < len(a); i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}
	ans += last
	fmt.Println(ans)
}

func max(m map[int]int) int {
	max := 0
	for k, v := range m {
		if k > max {
			max = k
		}
	}
	return max
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

