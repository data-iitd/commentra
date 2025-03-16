package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
	"strconv"
)

func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func ceil(a, b int) int {
	return int(-(-a / b))
}

func round(x float64) int {
	return int((x * 2 + 1) / 2)
}

func fermat(x, y, MOD int) int {
	return x * powMod(y, MOD-2, MOD) % MOD
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func lcmList(nums []int) int {
	result := 1
	for _, num := range nums {
		result = lcm(result, num)
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	q, _ := strconv.Atoi(parts[0])
	h, _ := strconv.Atoi(parts[1])
	s, _ := strconv.Atoi(parts[2])
	d, _ := strconv.Atoi(parts[3])
	n, _ := strconv.Atoi(parts[4])

	best1L := min(q * 4, h * 2, s)
	best2L := min(d, best1L * 2)

	if n % 2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L * (n / 2) + best1L)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func powMod(base, exp, mod int) int {
	result := 1
	base = base % mod
	for exp > 0 {
		if exp % 2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}
