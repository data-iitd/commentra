package main
import "fmt"
func main() {
	var N, A int
	fmt.Scanf("%d %d", &N, &A)
	fmt.Printf("%s\n", (N%500 <= A) && "Yes" || "No")
}
