
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	cookies := make([]int, 3)
	for i, part := range strings.Split(line, " ") {
		cookies[i], _ = strconv.Atoi(part)
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := 0
	if leftOver > 0 {
		takahashi = leftOver
	}
	fmt.Println(takahashi, cookies[1]-takahashi)
}

