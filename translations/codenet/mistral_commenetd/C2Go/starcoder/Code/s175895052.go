
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var n [10]byte
	fmt.Scanf("%s", &n)
	if n[0] == n[1] && n[1] == n[2] || n[1] == n[2] && n[2] == n[3] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

