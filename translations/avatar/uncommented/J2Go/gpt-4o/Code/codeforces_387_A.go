package main

import (
	"fmt"
	"strconv"
	"strings"
	"time"
)

func main() {
	var input string
	fmt.Scan(&input)
	s := strings.Split(input, ":")
	fmt.Scan(&input)
	t := strings.Split(input, ":")

	h1, _ := strconv.Atoi(s[0])
	m1, _ := strconv.Atoi(s[1])
	h2, _ := strconv.Atoi(t[0])
	m2, _ := strconv.Atoi(t[1])

	x := time.Date(0, 1, 1, h1, m1, 0, 0, time.UTC)
	y := time.Date(0, 1, 1, h2, m2, 0, 0, time.UTC)

	diff := x.Add(-y.Sub(time.Time{}))
	fmt.Println(diff.Format("15:04"))
}
