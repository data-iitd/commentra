

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the first string:")
	str1, _ := reader.ReadString('\n')
	fmt.Println("Enter the second string:")
	str2, _ := reader.ReadString('\n')
	str1 = strings.TrimSpace(str1)
	str2 = strings.TrimSpace(str2)
	slen := len(str1)
	plen := len(str2)
	flag := false
	for i := 0; i < slen-plen; i++ {
		if str1[i:i+plen] == str2 {
			flag = true
			break
		}
	}
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

