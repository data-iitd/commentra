<<<<<<< HEAD

import "fmt"

func main() {
	var m, f, r int
	for {
		_, err := fmt.Scanf("%d %d %d\n", &m, &f, &r)
		if err!= nil {
			break
		}
		if m == -1 || f == -1 {
			fmt.Println("F")
			continue
		}
		if m+f >= 80 {
			fmt.Println("A")
			continue
		}
		if m+f >= 65 {
			fmt.Println("B")
			continue
		}
		if m+f >= 50 || r >= 50 {
			fmt.Println("C")
			continue
		}
		if m+f >= 30 {
			fmt.Println("D")
			continue
		}
		fmt.Println("F")
	}
}

=======
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		line = strings.TrimSpace(line)
		if line == "
>>>>>>> 98c87cb78a (data updated)
