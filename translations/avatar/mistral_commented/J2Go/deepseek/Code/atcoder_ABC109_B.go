package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N := 0
	fmt.Sscanf(scanner.Text(), "%d", &N)

	m := make(map[int]string)

	for i := 0; i < N; i++ {
		scanner.Scan()
		m[i] = scanner.Text()
	}

	ans := true
	past := make(map[int]string)
	var next string

	for i := 0; i < N; i++ {
		if _, ok := past[i]; ok {
			ans = false
			break
		}
		past[i] = m[i]

		if i != 0 {
			if next != m[i][:1] {
				ans = false
				break
			}
		}
		next = m[i][len(m[i])-1:]
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
