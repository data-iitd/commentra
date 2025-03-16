
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(x int, y int) string {
	if y%2 == 0 {
		t := (y / 2) - x
		if t >= 0 && (x-t) >= 0 {
			return "Yes"
		}
	}
	return "No"
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	x, _ := strconv.Atoi(read(reader))
	y, _ := strconv.Atoi(read(reader))

	fmt.Println(check(x, y))
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

