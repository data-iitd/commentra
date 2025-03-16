
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.Replace(s, "\n", "", -1)

	for i := 'a'; i <= 'z'; i++ {
		a := 0
		for j := 0; j < len(s); j++ {
			if i == s[j] {
				a++
			}
		}
		if a == 0 {
			fmt.Println(string(i))
			break
		}
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}

