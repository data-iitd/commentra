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
	var n int
<<<<<<< HEAD
	var i int
=======
>>>>>>> 98c87cb78a (data updated)
	var h [100001]int
	var max int = -1
	var flag int = 0

	fmt.Scanf("%d", &n)

<<<<<<< HEAD
	for i = 0; i < n; i++ {
=======
	for i := 0; i < n; i++ {
>>>>>>> 98c87cb78a (data updated)
		fmt.Scanf("%d", &h[i])
		if max < h[i] {
			max = h[i]
		}
		if max-h[i] >= 2 {
			flag = 1
		}
	}

	if flag == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

