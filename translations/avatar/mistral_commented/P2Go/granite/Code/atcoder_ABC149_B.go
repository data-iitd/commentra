
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var cookies []int
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" {
			break
		}
		cookie, _ := strconv.Atoi(text)
		cookies = append(cookies, cookie)
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := 0
	if leftOver > 0 {
		takahashi = leftOver
	}
	fmt.Println(takahashi, cookies[1]-takahashi)
}
