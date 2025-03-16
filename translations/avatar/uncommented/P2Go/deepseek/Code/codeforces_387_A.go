package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var h1, m1 int
	var h2, m2 int

	fmt.Scanf("%d:%d", &h1, &m1)
	m1 += h1 * 60
	fmt.Scanf("%d:%d", &h2, &m2)
	m2 += h2 * 60
	m2 = m1 - m2
	m2 %= 1440
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

