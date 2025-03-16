
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	s, _ := stdin.ReadString('\n')
	s = s[:len(s)-1]
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		result := "Yes"
	} else {
		result := "No"
	}
	fmt.Println(result)
}

