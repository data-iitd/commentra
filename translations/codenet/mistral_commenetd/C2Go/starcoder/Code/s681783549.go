<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i int
	var S string

	S = strings.TrimSpace(string(os.Stdin.Read(6)))

	for i = 0; i < len(S); i++ {
		if S[i] == 'A' && S[i+1] == 'C' {
			fmt.Println("Yes")
			return
		}
	}

	fmt.Println("No")
}

