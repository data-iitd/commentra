<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	a := make([]int, n)
	acc := make([]int, n + 1)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a[i])
		acc[i + 1] = acc[i] + a[i]
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD
		ans %= MOD
	}
	fmt.Println(ans)
}

