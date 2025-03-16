
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	a, b, t := getInput()
	cookie := 0
	time := a
	for time <= t+0.5 {
		cookie += b
		time += a
	}
	fmt.Println(cookie)
}

func getInput() (int, int, int) {
	a, b, t := 0, 0, 0
	fmt.Scanf("%d %d %d", &a, &b, &t)
	return a, b, t
}

