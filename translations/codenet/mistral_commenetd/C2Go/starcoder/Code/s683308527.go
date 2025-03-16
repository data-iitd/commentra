
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
	var n int
	fmt.Scanf("%d\n", &n)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s := scanner.Text()
		for strings.Contains(s, "Hoshino") {
			s = strings.Replace(s, "Hoshino", "aana", 1)
		}
		fmt.Println(s)
	}
}

