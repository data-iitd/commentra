
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var str1, str2 string
	fmt.Fscanf(reader, "%s %s\n", &str1, &str2)

	sort.Strings([]string{str1})
	sort.Strings([]string{str2})

	loop := len(str1)
	if len(str2) < loop {
		loop = len(str2)
	}

	flag := false
	for i := 0; loop > i; i++ {
		ch1 := str1[i]
		ch2 := str2[i]

		if ch1 == ch2 {
			if loop == i+1 && len(str1) < len(str2) {
				flag = true
				break
			} else {
				continue
			}
		} else {
			if ch2 > ch1 {
				flag = true
				break
			} else {
				break
			}
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
