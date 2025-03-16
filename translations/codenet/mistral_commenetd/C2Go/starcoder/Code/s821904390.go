<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var in int
	var h, m, s int

	fmt.Scanf("%d", &in)

	h = in / 3600
	in %= 3600

	m = in / 60
	in %= 60

	s = in

	fmt.Printf("%d:%d:%d\n", h, m, s)
}
