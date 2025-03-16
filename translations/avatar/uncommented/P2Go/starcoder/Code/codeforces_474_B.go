package main
import "fmt"
func main() {
	var L []int
	var r int
	fmt.Scanln( )
	for _, k := range(strings.Fields(fmt.Scanln( ))) {
		for i := 0; i < int(k); i++ {
			L = append(L, r)
		}
		r++
	}
	fmt.Scanln( )
	for _, j := range(strings.Fields(fmt.Scanln( ))) {
		fmt.Println(L[int(j)-1])
	}
}
