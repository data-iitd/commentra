
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)
	for i := 1; i <= n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 1; i <= n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}
	ss := ""
	ans := 0
	st := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			sb := strings.Builder{}
			x := b[i]
			sss := strings.Builder{}
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(" " + sss.String())
			s := 1
			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss = strings.Builder{}
				sss.WriteString(strconv.Itoa(x))
				sb.WriteString(" " + sss.String())
				st[x] = true
				x = b[x]
				s++
			}
			if s > ans {
				ans = s
				ss = sb.String()
			}
		}
	}
	fmt.Println(ans)
	fmt.Println(ss)
}

