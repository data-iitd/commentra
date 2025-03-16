// ABC 152-D
// 2020.1.19 bal4u

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
	var (
		N int
		i int
<<<<<<< HEAD
		f1 [100]int
		f2 [100]int
		ans int
	)
	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	for N > 0 {
		calc(N, f1, f2)
		N--
	}
	for i = 0; i < 100; i++ {
		ans += f1[i] * f2[i]
	}
	fmt.Printf("%d\n", ans)
}

func calc(N int, f1 [100]int, f2 [100]int) {
	k := N % 10
	for N >= 10 {
		N /= 10
	}
	f1[10*k+N]++
	f2[N*10+k]++
=======
	)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
		if N == 0 {
			break
		}
		f1 := make([]int, 100)
		f2 := make([]int, 100)
		for i = 0; i < N; i++ {
			n := N % 10
			N /= 10
			f1[10*n+N]++
			f2[n*10+n]++
		}
		ans := 0
		for i = 0; i < 100; i++ {
			ans += f1[i] * f2[i]
		}
		fmt.Println(ans)
	}
>>>>>>> 98c87cb78a (data updated)
}

