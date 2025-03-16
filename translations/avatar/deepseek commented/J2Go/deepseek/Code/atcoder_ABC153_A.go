package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	scanner := bufio.NewScanner(strings.NewReader(str))
	scanner.Split(bufio.ScanWords)

	var h, a int
	scanner.Scan()
	h = mustAtoi(scanner.Text())
	scanner.Scan()
	a = mustAtoi(scanner.Text())

	num := 0

	for h > 0 {
		h -= a
		num++
	}

	fmt.Println(num)
}

func mustAtoi(s string) int {
	num, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return num
}

