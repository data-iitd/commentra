package main
import "fmt"
func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	res := 0
	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			res = max(res, ans)
			return
		}
		last_max := 1
		if len(A) > 0 {
			last_max = A[len(A)-1]
		}
		for i := last_max; i <= M; i++ {
			rec(append(A, i))
		}
	}
	rec([]int{})
	fmt.Println(res)
}
func main() {
	var N, M, Q int
	fmt.Scanf("%d %d %d\n", &N, &M, &Q)
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)
	for i := 0; i < Q; i++ {
		fmt.Scanf("%d %d %d %d\n", &a[i], &b[i], &c[i], &d[i])
	}
	solve(N, M, Q, a, b, c, d)
}
