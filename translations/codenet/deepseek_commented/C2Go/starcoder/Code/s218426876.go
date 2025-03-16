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
	var sum int
	var i int
	var x string
	for {
		x, _ = fmt.Scanf("%s", &x)
		if x[0] == '0' {
<<<<<<< HEAD
			fmt.Println(sum)
			os.Exit(0)
=======
			fmt.Printf("%d\n", sum)
			break
>>>>>>> 98c87cb78a (data updated)
		}
		for i = 0; i < len(x); i++ {
			sum += int(x[i] - '0')
		}
		sum = 0
	}
}

