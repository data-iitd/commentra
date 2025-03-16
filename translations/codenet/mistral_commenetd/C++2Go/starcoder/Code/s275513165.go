
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
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
<<<<<<< HEAD

	if str[2] == str[3] {
		if str[4] == str[5] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
=======
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
>>>>>>> 98c87cb78a (data updated)
	}
}

