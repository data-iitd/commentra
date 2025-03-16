
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	bstr := fmt.Sprintf("%d", b)
	num := a * int(math.Pow(10, float64(len(bstr)))) + b

	for i := 1; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}

	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

