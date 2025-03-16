package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	i := 1
	req := 1
	for k-req >= 0 {
		if k-req >= 0 {
			k = k - req
		} else {
			break
		}
		i++
		if i%n != 0 {
			req = i % n
		} else {
			req = n
		}
	}
	fmt.Println(k)
}

