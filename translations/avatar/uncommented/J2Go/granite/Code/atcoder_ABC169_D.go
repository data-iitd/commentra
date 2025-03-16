
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.ParseInt(reader.ReadLine()[2:len(reader.ReadLine())-1], 10, 64)
	sqrt := int(n)
	answer := 0
	for i := 2; i <= sqrt; i++ {
		count := 0
		for 0 == n%int64(i) {
			n /= int64(i)
			count++
		}
		for j := 1; count-j >= 0; j++ {
			count -= j
			answer++
		}
	}
	if n > 1 {
		answer++
	}
	fmt.Println(answer)
}

