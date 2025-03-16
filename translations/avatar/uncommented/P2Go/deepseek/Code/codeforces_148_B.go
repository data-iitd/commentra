package main

import (
	"fmt"
)

func main() {
	var princess, dragon, t, f, c int
	fmt.Scan(&princess, &dragon, &t, &f, &c)
	if dragon <= princess {
		fmt.Println(0)
		return
	}
	result := 0
	position := t * princess
	position += float64(princess) * float64(position) / float64(dragon - princess)
	for position < float64(c) {
		result += 1
		position += float64(princess) * position / float64(dragon)
		position += float64(princess) * float64(f)
		position += float64(princess) * position / float64(dragon - princess)
	}
	fmt.Println(result)
}

