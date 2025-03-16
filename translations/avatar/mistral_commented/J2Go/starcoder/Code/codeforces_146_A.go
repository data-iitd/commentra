
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
	fmt.Println("Enter the length of the string")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the string")
	str := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	l := make([]rune, n)
	for i := 0; i < n; i++ {
		l[i] = rune(str[i])
	}
	t := 0
	for i := 0; i < n; i++ {
		if l[i]!= '4' && l[i]!= '7' {
			t = 1
		}
	}
	if t == 1 {
		fmt.Println("NO")
	} else {
		x := 0
		y := 0
		for i := 0; i < n/2; i++ {
			x = x + int(l[i]-'0')
		}
		for i := n - 1; i > n/2-1; i-- {
			y = y + int(l[i]-'0')
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

