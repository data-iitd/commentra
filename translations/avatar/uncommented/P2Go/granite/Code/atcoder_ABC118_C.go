
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine()[2:])
	A := make([]int, N)
	for i, v := range strings.Split(reader.ReadLine()[2:], " ") {
		A[i], _ = strconv.Atoi(v)
	}
	gcd := A[0]
	for _, v := range A[1:] {
		gcd = gcd(gcd, v)
	}
	fmt.Println(gcd)
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}
