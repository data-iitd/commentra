package main
import "fmt"
func main() {
	var a, b int
	var S string
	for {
		fmt.Scanf("%d %s %d", &a, &S, &b)
		if S == "+" {
			fmt.Println(a + b)
		}
		if S == "-" {
			fmt.Println(a - b)
		}
		if S == "*" {
			fmt.Println(a * b)
		}
		if S == "/" {
			fmt.Println(a / b)
		}
		if S == "?" {
			break
		}
	}
}
