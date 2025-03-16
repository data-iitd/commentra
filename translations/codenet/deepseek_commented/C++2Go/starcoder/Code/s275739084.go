<<<<<<< HEAD
import "fmt"
import "os"
import "strconv"

=======
package main
import "fmt"
>>>>>>> 98c87cb78a (data updated)
func main() {
	var A, B int
	fmt.Scanf("%d %d", &A, &B)
	C := A + B
	if A%3!= 0 && B%3!= 0 && C%3!= 0 {
		fmt.Println("Impossible")
	} else {
		fmt.Println("Possible")
	}
}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
