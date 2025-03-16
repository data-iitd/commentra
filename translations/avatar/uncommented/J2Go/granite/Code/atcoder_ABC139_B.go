
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var A int
	sc.Scan()
	A, _ = strconv.Atoi(sc.Text())
	var B int
	sc.Scan()
	B, _ = strconv.Atoi(sc.Text())
	var amari int
	var result int
	result = (B - 1) / (A - 1)
	amari = (B - 1) % (A - 1)
	if amari!= 0 {
		result += 1
	}
	fmt.Println(result)
}

