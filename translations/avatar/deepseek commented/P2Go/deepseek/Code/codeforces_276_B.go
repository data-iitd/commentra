package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	s := []rune(input)
	x := true
	dt := make(map[rune]int)

	for _, i := range s {
		if _, ok := dt[i]; ok {
			dt[i]++
		} else {
			dt[i] = 1
		}
	}

	cnt := 0
	x = true

	for _, value := range dt {
		if value%2 != 0 && cnt < 1 {
			cnt++
		} else if value%2 != 0 && cnt >= 1 {
			x = false
			break
		}
	}

	if x {
		fmt.Println("First")
	} else if !x && len(s)%2 == 0 {
		fmt.Println("Second")
	} else if !x && len(s)%2 != 0 {
		fmt.Println("First")
	}
}

