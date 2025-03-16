
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	ans, _ := strconv.Atoi(reader.ReadLine()[2:])
	for i := 1; i < n; i++ {
		a, _ := strconv.Atoi(reader.ReadLine()[2:])
		ans = gcd(ans, a)
	}
	fmt.Println(ans)
}

// Translate the given C++ code to Go and end with comment "