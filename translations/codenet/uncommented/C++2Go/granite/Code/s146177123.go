
package main

import (
	"bufio"
	"fmt"
	"os"
)

var seg = [][]bool{
	{false, true, true, true, true, true, true},
	{false, false, false, false, true, true, false},
	{true, false, true, true, false, true, true},
	{true, false, false, true, true, true, true},
	{true, true, false, false, true, true, false},
	
	{true, true, false, true, true, false, true},
	{true, true, true, true, true, false, true},
	{false, true, false, false, true, true, true},
	{true, true, true, true, true, true, true},
	{true, true, false, true, true, true, true},
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n := toInt(sc.Text())
	for n > 0 {
		sc.Scan()
		t := toInt(sc.Text())
		st := make([]bool, 7)
		for i := 0; i < 7; i++ {
			st[i] = false
		}
		for i := 0; i < n; i++ {
			ans := make([]byte, 8)
			for j := 0; j < 7; j++ {
				ans[j] = '0' + byte(st[j]^seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
		sc.Scan()
		n = toInt(sc.Text())
	}
}

func toInt(s string) int {
	x, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return x
}

