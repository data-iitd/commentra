package main
import "fmt"
func main() {
	var N int
	fmt.Scanf("%d", &N)
	a := make([]int, N)
	for i := range a {
		fmt.Scanf("%d", &a[i])
	}
	max_val := 0
	max_sign := 0
	max_index := -1
	for i, a0 := range a {
		if a0 > max_val {
			max_val = a0
			max_sign = 1
			max_index = i
		} else if a0 < max_val {
			max_val = a0
			max_sign = -1
			max_index = i
		}
	}
	if max_sign == 0 {
		fmt.Println(0)
	} else if max_sign == 1 {
		fmt.Println(2*N-1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", max_index+1, i+1)
		}
		for i := 0; i < N-1; i++ {
			fmt.Printf("%d %d\n", i+1, i+2)
		}
	} else {
		fmt.Println(2*N-1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", max_index+1, i+1)
		}
		for i := 1; i < N; i++ {
			fmt.Printf("%d %d\n", i+1, i)
		}
	}
}
