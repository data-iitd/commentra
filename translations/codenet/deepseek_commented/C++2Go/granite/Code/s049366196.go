
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscanf(reader, "%d\n", &N)

	const mod = 1e9 + 7
	ans := int64(1)
	for i := 2; i <= N; i++ {
		if isPrime(int64(i)) {
			cnt := int64(0)
			NN := int64(N)
			for NN > 0 {
				cnt += NN / int64(i)
				NN /= int64(i)
			}
			ans *= cnt + 1
			ans %= mod
		}
	}

	fmt.Println(ans)
}

func isPrime(x int64) bool {
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

