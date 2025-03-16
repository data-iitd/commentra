<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var s, t string
	fmt.Scanf("%s", &s)
	fmt.Scanf("%s", &t)
	hit := 0
	for i := 0; i < 3; i++ {
		if s[i] == t[i] {
			hit++
		}
	}
<<<<<<< HEAD
	fmt.Printf("%d\n", hit)
=======
	fmt.Println(hit)
>>>>>>> 98c87cb78a (data updated)
}

