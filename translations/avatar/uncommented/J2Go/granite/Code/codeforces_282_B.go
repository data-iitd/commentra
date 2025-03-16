
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	s1, s2 := 0, 0
	ans := ""
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		y, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		if s1+x-s2 <= 500 {
			s1 += x
			ans += "A"
		} else if s2+y-s1 <= 500 {
			s2 += y
			ans += "G"
		} else {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

