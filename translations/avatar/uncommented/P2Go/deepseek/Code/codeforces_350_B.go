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
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	t := make([]int, n+1)
	a := make([]int, n+1)

	input, _ = reader.ReadString('\n')
	tInput := strings.Fields(input)
	for i := 1; i <= n; i++ {
		t[i], _ = strconv.Atoi(tInput[i-1])
	}

	input, _ = reader.ReadString('\n')
	aInput := strings.Fields(input)
	for i := 1; i <= n; i++ {
		a[i], _ = strconv.Atoi(aInput[i-1])
	}

	ans := []int{}
	cnt := make([]int, n+1)

	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}

	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := []int{i}
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = append([]int{}, crt...)
			}
		}
	}

	for i := 0; i < len(ans)/2; i++ {
		ans[i], ans[len(ans)-1-i] = ans[len(ans)-1-i], ans[i]
	}

	fmt.Println(len(ans))
	fmt.Println(strings.Trim(fmt.Sprint(ans), "[]"))
}

