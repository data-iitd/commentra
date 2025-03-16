<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var i, t, n int
	for i = 0; i < 4; i++ {
<<<<<<< HEAD
		fmt.Scanf("%d %d", &t, &n)
		if t == 1 {
			fmt.Println(6000 * n)
		} else if t == 2 {
			fmt.Println(4000 * n)
		} else if t == 3 {
			fmt.Println(3000 * n)
		} else if t == 4 {
			fmt.Println(2000 * n)
=======
		fmt.Scanf("%d %d\n", &t, &n)
		if t == 1 {
			fmt.Printf("%d\n", 6000*n)
		} else if t == 2 {
			fmt.Printf("%d\n", 4000*n)
		} else if t == 3 {
			fmt.Printf("%d\n", 3000*n)
		} else if t == 4 {
			fmt.Printf("%d\n", 2000*n)
>>>>>>> 98c87cb78a (data updated)
		}
	}
}

