package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	var k int
	fmt.Scan(&k)

	l := 0
	for _, c := range s {
		if c != '1' {
			break
		}
		l++
	}

	if l >= k {
		fmt.Println(1)
		return
	}
	fmt.Println(string(s[l]))
}

// <END-OF-CODE>
