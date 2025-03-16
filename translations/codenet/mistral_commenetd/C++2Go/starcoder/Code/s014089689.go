
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
	fmt.Println("Enter the size of the string: ")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the string: ")
	s := reader.ReadString('\n')
	s = strings.Replace(s, "\n", "", -1)
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

