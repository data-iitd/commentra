
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	if a < b && b < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

