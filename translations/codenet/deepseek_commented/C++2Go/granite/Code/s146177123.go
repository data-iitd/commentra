
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var seg = [][]bool{
	{true, true, true, true, true, true}, // 0
	{false, true, false, false, false, true}, // 1
	{true, true, false, true, true, true, true}, // 2
	{true, true, true, true, false, true, true}, // 3
	{false, true, true, false, true, true, false}, // 4
	
	{true, false, true, true, true, true, true}, // 5
	{true, false, true, false, true, true, true}, // 6
	{true, true, true, false, true, true, true}, // 7
	{true, true, true, true, true, true, true}, // 8
	{true, true, true, false, true, true, true}, // 9
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	for n > 0 {
		st := make([]bool, 7)
		for i := 0; i < n; i++ {
			sc.Scan()
			t, _ := strconv.Atoi(sc.Text())
			ans := make([]byte, 8)
			for i := 0; i < 7; i++ {
				ans[i] = '0' + byte(st[i]^seg[t][i])
				st[i] = seg[t][i]
			}
			fmt.Println(string(ans))
		}
		sc.Scan()
		n, _ = strconv.Atoi(sc.Text())
	}
}

