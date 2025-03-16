package main
import "fmt"
func main() {
	var W,H,x,y,r int
	fmt.Scanf("%d %d %d %d %d",&W,&H,&x,&y,&r)
	if x-r<0 || x+r>W || y-r<0 || y+r>H {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

Translate the above Go code to Python and end with comment "