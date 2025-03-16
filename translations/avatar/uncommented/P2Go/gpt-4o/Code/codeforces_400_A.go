package main

import (
	"fmt"
	"os"
	"strings"
)

func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

func values() (int, int) {
	var a, b int
	fmt.Fscan(os.Stdin, &a, &b)
	return a, b
}

func inlst() []int {
	var input string
	fmt.Scan(&input)
	strs := strings.Split(input, " ")
	lst := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscan(s, &lst[i])
	}
	return lst
}

func inlsts() []int {
	var input string
	fmt.Fscan(os.Stdin, &input)
	strs := strings.Split(input, " ")
	lst := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscan(s, &lst[i])
	}
	return lst
}

func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

func inps() int {
	var n int
	fmt.Fscan(os.Stdin, &n)
	return n
}

func instr() string {
	var input string
	fmt.Scan(&input)
	return input
}

func stlst() []string {
	var input string
	fmt.Scan(&input)
	return strings.Split(input, " ")
}

func help(a, b int, l []int) bool {
	tot := make([][]int, b)
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}
	for i := 0; i < a; i++ {
		sum := 0
		for j := 0; j < b; j++ {
			sum += tot[j][i]
		}
		if sum == b {
			return true
		}
	}
	return false
}

func solve() {
	tot := [][]int{}
	x := instr()
	s := []int{}
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}
	fmt.Print(len(tot), " ")
	for _, pair := range tot {
		fmt.Printf("%dx%d ", pair[0], pair[1])
	}
	fmt.Println()
}

func main() {
	for i := inp(); i > 0; i-- {
		solve()
	}
}

// <END-OF-CODE>
