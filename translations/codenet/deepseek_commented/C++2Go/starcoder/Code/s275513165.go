<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.Replace(str, "\n", "", -1)
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

