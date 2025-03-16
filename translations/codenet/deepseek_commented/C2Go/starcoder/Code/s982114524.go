<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
	var i, N, x int
	x = 0
<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
=======
	fmt.Scanf("%d", &N)
>>>>>>> 98c87cb78a (data updated)
	for i = 1; i <= N; i++ {
		x += i
	}
	fmt.Printf("%d\n", x)
}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
