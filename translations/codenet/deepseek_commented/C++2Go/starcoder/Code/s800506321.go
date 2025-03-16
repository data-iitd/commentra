<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
	var n,k,x,y,z int
	fmt.Scanf("%d",&n)
	fmt.Scanf("%d",&k)
	x=n/k
	y=n%k
	if y!=0 {
		z=x+1-x
	}
	else {
		z=x-x
	}
	fmt.Printf("%d\n",z)
}
