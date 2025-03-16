
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
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine())
	}
	s := reader.ReadLine()[2:]
	sum := int64(0)
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += int64(a[i])
		}
	}
	ans := sum
	sum1 := sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}
		if ans < sum1 {
			ans = sum1
		}
	}
	sum1 = sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}
		if ans < sum1 {
			ans = sum1
		}
	}
	fmt.Println(ans)
}

