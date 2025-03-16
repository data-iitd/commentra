
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i, v := range reader.ReadLine()[2:] {
		a[i], _ = strconv.Atoi(string(v))
	}
	MOD := int(1e9 + 7)
	lcm := int64(1)
	for _, v := range a {
		lcm = lcm * int64(v) / gcd(lcm, int64(v))
	}
	ans := lcm * sum(a) % MOD
	fmt.Println(ans)
}

func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func sum(a []int) int64 {
	s := int64(0)
	for _, v := range a {
		s += int64(v)
	}
	return s
}

