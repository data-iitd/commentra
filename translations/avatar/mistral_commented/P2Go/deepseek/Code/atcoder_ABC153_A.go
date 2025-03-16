package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	h, _ := strconv.Atoi(parts[0])
	a, _ := strconv.Atoi(parts[1])

	sho := h / a
	am := h % a

	if am != 0 {
		sho += 1
	}

	fmt.Println(sho)
}
