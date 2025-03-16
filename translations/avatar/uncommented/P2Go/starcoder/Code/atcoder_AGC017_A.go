package main
import "fmt"
func main() {
	var N, P int
	fmt.Scanf("%d %d", &N, &P)
	var ans int
	var lis []int
	var ls []int
	for i := 0; i < N; i++ {
		var a int
		fmt.Scanf("%d", &a)
		lis = append(lis, a)
	}
	for _, a := range lis {
		ls = append(ls, a%2)
	}
	one := 0
	zero := 0
	for _, a := range ls {
		if a == 1 {
			one++
		} else {
			zero++
		}
	}
	var pattern_a, pattern_b int
	for j := 0; j <= zero; j++ {
		pattern_b += combi(zero, j)
	}
	var time int
	for time <= one {
		if time%2 == P {
			pattern_a += combi(one, time)
		}
		time++
	}
	fmt.Println(pattern_a * pattern_b)
}
func combi(n, k int) int {
	var a int
	for i := 0; i < k; i++ {
		a *= n - i
	}
	for j := 0; j < k; j++ {
		a /= j + 1
	}
	return a
}
