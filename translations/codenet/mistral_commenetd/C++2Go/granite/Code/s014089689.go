

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the size of the string: ")
	n, _ := strconv.Atoi(reader.ReadLine())
	fmt.Print("Enter the string: ")
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	cnt := 0
	for i := 0; i < n; i++ {
		cnt++
		j := i + 1
		for ; j < n; j++ {
			if s[i]!= s[j] {
				break
			}
		}
		i = j - 1
	}
	fmt.Println(cnt)
}

