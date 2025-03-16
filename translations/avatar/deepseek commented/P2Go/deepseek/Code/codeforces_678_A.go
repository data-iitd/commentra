package main

import (
	"fmt"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	vamshi, _ := strconv.Atoi(parts[0])
	z, _ := strconv.Atoi(parts[1])

	result := (vamshi / z + 1) * z
	fmt.Println(result)
}
