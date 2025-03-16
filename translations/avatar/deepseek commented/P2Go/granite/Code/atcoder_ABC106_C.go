
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	s, _ := reader.ReadString('\n')
	k, _ := fmt.Scanf("%d\n", &k)

	l := 0
	for _, c := range s {
		if c!= '1' {
			break
		}
		l++
	}
	if l >= k {
		fmt.Println(1)
	} else {
		fmt.Println(string(s[l]))
	}
}

// 