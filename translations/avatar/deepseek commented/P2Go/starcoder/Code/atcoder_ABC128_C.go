package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of switches (n) and the number of bulbs (m)
	n, m := readTwoInts(bufio.NewReader(os.Stdin))

	// Read the connections of switches for each bulb and store them in a list (li)
	// Each element in li is a list of switches connected to a bulb, excluding the bulb itself
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		li[i] = readInts(bufio.NewReader(os.Stdin))
	}

	// Read the pattern of on/off states for each bulb and store it in a tuple (p)
	p := readInts(bufio.NewReader(os.Stdin))

	// Create a set (q) containing all the switches from all the bulbs
	q := make(map[int]bool)
	for _, u := range li {
		for _, v := range u {
			q[v] = true
	}

	// Create a set (r) containing all the switches from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}

	// Calculate the set (v) which contains the switches that are not connected to any bulb
	v := make(map[int]bool)
	for i := 1; i <= n; i++ {
		if _, ok := q[i];!ok {
			v[i] = true
	}

	// Initialize the answer variable to count the number of valid configurations
	ans := 0

	// Iterate over all possible combinations of switches from q
	for i := 0; i <= len(q); i++ {
		for s := range combinations(q, i) {
			// Check if each combination satisfies the given pattern p
			for j, u := range li {
				s := set(s)
				if len(s & set(u)) % 2!= p[j] {
					break
			} else {
				// If a combination satisfies the pattern, increment the answer by 2^len(v)
				ans += 1 << len(v)
		}
	}

	// Print the total number of valid configurations
	fmt.Println(ans)
}

func readTwoInts(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimSuffix(line, "\r")
	nums := strings.Split(line, " ")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	return a, b
}

func readInts(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimSuffix(line, "\r")
	nums := strings.Split(line, " ")
	ints := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		ints[i], _ = strconv.Atoi(nums[i])
	}
	return ints
}

func combinations(q map[int]bool, i int) map[int]bool {
	if i == 0 {
		return map[int]bool{}
	}
	if i == 1 {
		for k := range q {
			return map[int]bool{k: true}
	}
	for k, v := range combinations(q, i - 1) {
		for l := range q {
			if l > k {
				v[l] = true
		}
		return v
	}

func set(s map[int]bool) map[int]bool {
	r := make(map[int]bool)
	for k, v := range s {
		if v {
			r[k] = true
	}
	return r
}

