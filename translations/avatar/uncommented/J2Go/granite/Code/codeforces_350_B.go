
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
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)
	for i := 1; i <= n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}
	for i := 1; i <= n; i++ {
		b[i], _ = strconv.Atoi(reader.ReadLine()[2:])
		num[b[i]]++
	}
	ss := ""
	ans := 0
	st := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			sb := new(strings.Builder)
			x := b[i]
			sss := new(strings.Builder)
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(sss.String())
			s := 1
			for!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1 {
				sss = new(strings.Builder)
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

