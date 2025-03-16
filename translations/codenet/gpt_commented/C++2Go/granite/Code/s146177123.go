
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var seg = [][]bool{
	{true, true, true, true, true, true}, // 0
	{false, false, false, false, true, true, false}, // 1
	{true, false, true, true, false, true, true}, // 2
	{true, false, false, true, true, true, true}, // 3
	{true, true, false, false, true, true, false}, // 4
	{true, true, false, true, true, false, true}, // 5
	{true, true, true, true, true, false, true}, // 6
	{false, true, false, false, true, true, true}, // 7
	{true, true, true, true, true, true, true}, // 8
	{true, true, false, true, true, true, true}, // 9
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "-1" {
			break
		}
		n, _ := strconv.Atoi(line)
		st := make([]bool, 7)
		for i := 0; i < n; i++ {
			scanner.Scan()
			t, _ := strconv.Atoi(scanner.Text())
			ans := make([]byte, 8)
			for i := 0; i < 7; i++ {
				ans[i] = '0' + byte(st[i]^seg[t][i])
				st[i] = seg[t][i]
			}
			fmt.Println(string(ans))
		}
	}
}

// 