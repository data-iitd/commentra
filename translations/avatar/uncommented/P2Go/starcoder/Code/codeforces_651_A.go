package main
import "fmt"
func main() {
	var x, y int
	fmt.Scanf("%d %d", &x, &y)
	fmt.Printf("%d\n", max(x+y-3+(y-x)%3>0, 0))
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func num_inp() int {
	var x int
	fmt.Scanf("%d", &x)
	return x
}
func arr_inp() []int {
	var x []int
	fmt.Scanf("%v", &x)
	return x
}
func sp_inp() (int, int) {
	var x, y int
	fmt.Scanf("%d %d", &x, &y)
	return x, y
}
func str_inp() string {
	var x string
	fmt.Scanf("%s", &x)
	return x
}
