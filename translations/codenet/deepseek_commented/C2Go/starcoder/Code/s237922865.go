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
	fmt.Println("Enter the number of integers to read:")
<<<<<<< HEAD
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	cnt4 := 0
	cnt2 := 0

	for i := 0; i < n; i++ {
		fmt.Println("Enter the integer:")
		input, _ := reader.ReadString('\n')
		wk, _ := strconv.Atoi(strings.TrimSpace(input))
=======
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the integers:")
	cnt4, cnt2 := 0, 0
	for i := 0; i < n; i++ {
		var wk int
		fmt.Scanf("%d", &wk)
>>>>>>> 98c87cb78a (data updated)
		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

