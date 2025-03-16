package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	startTime := time.Now().UnixNano() / int64(time.Millisecond)
	sc := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(sc.Text())
	A := make([]int64, n)
	for i := 0; i < n; i++ {
		A[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
	}
	div := int64(math.Pow(10, 9) + 7)
	ans := int64(0)
	for i := 0; i < 60; i++ {
		a := int64(0)
		count1 := int64(0)
		for j := 0; j < n; j++ {
			if (A[j]>>i&1) == 1 {
				count1++
			}
		}
		a = a + count1*(n-count1)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}
		ans += a
		ans %= div
	}
	fmt.Println(ans)
	endTime := time.Now().UnixNano() / int64(time.Millisecond)
	fmt.Printf("%d ms", endTime-startTime)
}

