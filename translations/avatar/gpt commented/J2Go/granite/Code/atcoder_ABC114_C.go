
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	N int
	i int64
	c int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 4096
	const growthFactor = 1.618033988749894848204586834365638117720309179805762862135448622705260462818902449707806377697667551818420401041333592437909898799876695564039457584007913129639935
	var buf []rune
	buf = make([]rune, 0, initialCapacity)
	scanner.Buffer(buf, growthFactor)
	scanner.Split(bufio.ScanWords)
	N, _ = strconv.Atoi(scanner.Text())
	i = 357
	for i <= int64(N) {
		s := fmt.Sprintf("%d", i)
		if contains(s, "3") && contains(s, "5") && contains(s, "7") {
			c++
		}
		var sb []rune
		sb = make([]rune, 0, initialCapacity)
		f := false
		for j := len(s) - 1; j >= 0; j-- {
			a := s[j]
			if f {
				sb = append(sb, a)
			} else {
				if a == '3' {
					sb = append(sb, '5')
					f = true
				} else if a == '5' {
					sb = append(sb, '7')
					f = true
				} else {
					sb = append(sb, '3')
				}
			}
		}
		if!f {
			sb = append(sb, '3')
		}
		s2 := string(sb)
		i, _ = strconv.ParseInt(s2, 10, 64)
	}
	fmt.Println(c)
}

func contains(s string, substr string) bool {
	return len(s) >= len(substr) && s[len(s)-len(substr):] == substr
}

