
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t := make([]int, n+1)
	a := make([]int, n+1)
	ans := make([]int, 0)
	cnt := make([]int, n+1)
	for i := 1; i <= n; i++ {
		t[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}
	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}
	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := make([]int, 0)
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = crt[:]
			}
		}
	}
	ans = append(ans, 0)
	for i := 0; i < len(ans)/2; i++ {
		ans[i], ans[len(ans)-i-1] = ans[len(ans)-i-1], ans[i]
	}
	fmt.Println(len(ans) - 1)
	fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(ans[1:])), " "), "[]"))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

