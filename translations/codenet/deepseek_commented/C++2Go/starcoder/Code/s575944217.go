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
<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of nodes")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	ans := make([]int, n)
	fmt.Println("Enter the edges")
	for i := 0; i < n-1; i++ {
		a, _ := strconv.Atoi(reader.ReadString('\n'))
=======
	var n int
	fmt.Scanf("%d", &n)
	ans := make([]int, n)
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scanf("%d", &a)
>>>>>>> 98c87cb78a (data updated)
		a--
		ans[a]++
	}
	for i := 0; i < n; i++ {
<<<<<<< HEAD
		fmt.Println(ans[i])
=======
		fmt.Printf("%d\n", ans[i])
>>>>>>> 98c87cb78a (data updated)
	}
}

