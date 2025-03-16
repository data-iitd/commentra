package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

func sumn(i, n int) float64 {
	return float64(n-i) * (float64(i+n) / 2)
}

func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

func value() []int {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

func values() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var result []int
	for scanner.Scan() {
		val, _ := strconv.Atoi(scanner.Text())
		result = append(result, val)
	}
	return result
}

func inlst() []int {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

func inlsts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var result []int
	for scanner.Scan() {
		val, _ := strconv.Atoi(scanner.Text())
		result = append(result, val)
	}
	return result
}

func inp() int {
	var input string
	fmt.Scanln(&input)
	val, _ := strconv.Atoi(input)
	return val
}

func inps() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func instr() string {
	var input string
	fmt.Scanln(&input)
	return input
}

func stlst() []string {
	var input string
	fmt.Scanln(&input)
	return strings.Split(input, " ")
}

func f(s string) string {
	r := ""
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r += strings.ToLower(string(i))
		}
	}
	return r
}

func solve() {
	var l []string
	for i := 0; i < 3; i++ {
		l = append(l, f(instr()))
	}
	perms := permute(l)
	var permStrings []string
	for _, perm := range perms {
		permStrings = append(permStrings, strings.Join(perm, ""))
	}
	for i := 0; i < inp(); i++ {
		if strings.Contains(strings.Join(perms, ""), f(instr())) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

func permute(arr []string) [][]string {
	var result [][]string
	var helper func([]string, int)
	helper = func(arr []string, n int) {
		if n == len(arr)-1 {
			tmp := make([]string, len(arr))
			copy(tmp, arr)
			result = append(result, tmp)
		} else {
			for i := n; i < len(arr); i++ {
				arr[n], arr[i] = arr[i], arr[n]
				helper(arr, n+1)
				arr[n], arr[i] = arr[i], arr[n]
			}
		}
	}
	helper(arr, 0)
	return result
}

func main() {
	solve()
}

