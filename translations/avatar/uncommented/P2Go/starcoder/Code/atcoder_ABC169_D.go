package main
import "fmt"
func main() {
	var n int
	fmt.Scanf("%d", &n)
	if n == 1 {
		fmt.Println(0)
		return
	}
	fac := make(map[int]int)
	for _, v := range primeFactorize(n) {
		fac[v]++
	}
	ans := 0
	for p, e := range fac {
		x := e
		for i := 1; i < 100000000; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}
	fmt.Println(ans)
}
func primeFactorize(n int) []int {
	a := make([]int, 0)
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	f := 3
	for f*f <= n {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		} else {
			f += 2
		}
	}
	if n!= 1 {
		a = append(a, n)
	}
	return a
}
