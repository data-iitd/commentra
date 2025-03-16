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
	var (
		susum int
		j     int
	)
<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	for {
		var su string
		fmt.Fscanln(reader, &su)
		if su == "0" {
			break
		}
		for j = 0; j < len(su); j++ {
			susum += int(su[j] - '0')
=======
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		for j = 0; j <= 1000; j++ {
			susum += int(strings.TrimSpace(scanner.Text())[j] - '0')
>>>>>>> 98c87cb78a (data updated)
		}
		fmt.Println(susum)
		susum = 0
	}
}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
