package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var seg = [7][7]bool{
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
	for scanner.Scan() {
		n, err := strconv.Atoi(scanner.Text())
		if err != nil || n == 0 {
			break
		}
		st := [7]bool{}
		for i := 0; i < n; i++ {
			scanner.Scan()
			t, _ := strconv.Atoi(scanner.Text())
			ans := [7]rune{}
			for j := 0; j < 7; j++ {
				ans[j] = rune('0' + (st[j] != seg[t][j]))
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans[:]))
		}
	}
}

