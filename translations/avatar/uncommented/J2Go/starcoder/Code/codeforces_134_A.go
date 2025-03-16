package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	arr := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text())
		sum += arr[i]
	}
	c := 0
	sb := strings.Builder{}
	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(fmt.Sprintf("%d ", i+1))
		}
	}
	fmt.Println(c)
	fmt.Println(sb.String())
}

