

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
	scanner := bufio.NewScanner(os.Stdin)
	const eof = -1
	for scanner.Scan() {
		n := scanner.nextInt()
		if n == eof {
			break
		}
		st := make([]bool, 7)
		for i := 0; i < n; i++ {
			t := scanner.nextInt()
			ans := make([]byte, 8)
			for j := 0; j < 7; j++ {
				ans[j] = '0' + byte(st[j]^seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

func (scanner *bufio.Scanner) nextInt() int {
	scanner.Scan()
	nextInt, _ := strconv.Atoi(scanner.Text())
	return nextInt
}

