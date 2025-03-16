<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
	var a,b,x,w int
	for {
		_,err := fmt.Scanf("%d %d",&a,&b)
		if err!= nil {
			break
		}
		x = a+b
		w = 0
		for x!= 0 {
			w++
			x /= 10
		}
		fmt.Printf("%d\n",w)
	}
}
