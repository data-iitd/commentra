
package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	q := nextInt(sc)
	s := nextString(sc)

	range := make([][2]int, q)
	for i := 0; i < q; i++ {
		range[i][0] = nextInt(sc)
		range[i][1] = nextInt(sc)
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if s[i-2:i] == "AC" {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for i := 0; i < q; i++ {
		left := range[i][0]
		right := range[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextNumber(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, err := strconv.ParseFloat(sc.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return f
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return n
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func abs(x int) int {
	return int(math.Abs(float64(x)))
}

func modpow(a, b, m int) int {
	r := 1
	for i := 0; i < b; i++ {
		r = (r * a) % m
	}
	return r
}

func comb(n, k int) int {
	return fact(n) / (fact(k) * fact(n - k))
}

func perm(n, k int) int {
	return fact(n) / fact(n - k)
}

func fact(n int) int {
	r := 1
	for i := 1; i <= n; i++ {
		r *= i
	}
	return r
}

func gcd(x, y int) int {
	return fact(x) / (fact(y) * fact(x - y))
}

func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	x := n
	for {
		x++
		if isPrime(x) {
			return x
		}
	}
}

func divisors(n int) []int {
	d := []int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			d = append(d, i)
			if i*i!= n {
				d = append(d, n/i)
			}
		}
	}
	return d
}

func divisorsMap(n int) map[int]int {
	m := map[int]int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			m[i]++
			if i*i!= n {
				m[n/i]++
			}
		}
	}
	return m
}

func p(f string, a...interface{}) {
	fmt.Printf(f, a...)
}

func main() {
	const mod = 1000000007
	n, q := 0, 0
	fmt.Scan(&n, &q)
	s := ""
	fmt.Scan(&s)
	range := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&range[i][0], &range[i][1])
	}
	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if s[i-2:i] == "AC" {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}
	for i := 0; i < q; i++ {
		left, right := range[i][0], range[i][1]
		fmt.Println(rui[right] - rui[left])
	}
}