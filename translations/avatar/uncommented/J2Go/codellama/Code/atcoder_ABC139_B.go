package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	var A, B int
	sc.Scan()
	A, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	B, _ = strconv.Atoi(sc.Text())
	var amari, result int
	result = (B - 1) / (A - 1)
	amari = (B - 1) % (A - 1)
	if amari != 0 {
		result += 1
	}
	fmt.Println(result)
	sc.Close()
	// 