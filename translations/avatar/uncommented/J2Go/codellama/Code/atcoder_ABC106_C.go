
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var str string
	sc.Scan()
	str = sc.Text()
	c := []rune(str)
	var k int64
	sc.Scan()
	k, _ = strconv.ParseInt(sc.Text(), 10, 64)
	n := len(str)
	for i := 0; i < int(k); i++ {
		if c[i] == '1' {
			if i == int(k)-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(c[i])
			return
		}
	}
}

