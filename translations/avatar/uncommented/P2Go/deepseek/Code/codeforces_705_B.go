package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	w := make([]int, 0)
	for i := 0; i < len(n)-1; i++ {
		w = append(w, int(n[i]-'0'))
	}
	c := 2
	for _, i := range w {
		if i == 1 {
			fmt.Println(c)
		} else if i%2 == 0 {
			c = 3 - c
			fmt.Println(c)
		} else {
			fmt.Println(c)
		}
	}
}

