
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')
	k, _ := reader.ReadString('\n')
	n = n[:len(n)-1]
	k = k[:len(k)-1]
	nInt, _ := strconv.Atoi(n)
	kInt, _ := strconv.Atoi(k)
	d := make([]bool, 10)
	for i := 0; i < kInt; i++ {
		a, _ := reader.ReadString('\n')
		a = a[:len(a)-1]
		aInt, _ := strconv.Atoi(a)
		d[aInt] = true
	}
	for {
		x := nInt
		hantei := true
		for x > 0 {
			if d[x%10] {
				hantei = false
				break
			}
			x /= 10
		}
		if hantei {
			fmt.Println(nInt)
			break
		}
		nInt++
	}
}
