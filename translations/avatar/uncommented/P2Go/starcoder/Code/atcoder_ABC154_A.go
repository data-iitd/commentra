package main
import "fmt"
func solve(S string, T string, A int, B int, U string) {
	if S == U {
		A -= 1
	}
	if T == U {
		B -= 1
	}
	fmt.Println(A, B)
}
func main() {
	var S, T, U string
	var A, B int
	fmt.Scanf("%s %s %d %d %s", &S, &T, &A, &B, &U)
	solve(S, T, A, B, U)
}
