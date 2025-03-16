package main
import "fmt"

func main() {
	var n int
	var array [100]int
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &array[i])
	}
	var sum int
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
		}
	}
	fmt.Printf("%d\n", sum)
}
