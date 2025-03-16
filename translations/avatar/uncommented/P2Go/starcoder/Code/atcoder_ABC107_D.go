package main
import "fmt"
func main() {
	n := 0
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	m := n * (n + 1) / 4
	a = append(a, 0)
	sort.Ints(a)
	d := make(map[int]int)
	for i, x := range a {
		d[x] = i
	}
	a = make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = d[a[i]]
	}
	var check func(int) bool
	check = func(X int) bool {
		b := make([]int, n + 1)
		for i := 0; i < n; i++ {
			b[i+1] = (a[i] >= X) * 2 - 1
		}
		for i := 0; i < n; i++ {
			b[i+1] += b[i]
		}
		c := min(b)
		b = make([]int, n)
		for i := 0; i < n; i++ {
			b[i] = b[i] - c
		}
		bit := new(bitTree)
		for _, x := range b {
			bit.add(x, 1)
		}
		ans := 0
		for _, x := range b {
			ans += bit.sum(x + 1)
		}
		return ans >= m
	}
	t := []int{len(a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid) {
			t[1] = mid
		} else {
			t[0] = mid
		}
	}
	fmt.Println(_a[t[1]])
}
type bitTree struct {
	size int
	tree []int
}
func (bt *bitTree) sum(i int) int {
	ret := 0
	for i > 0 {
		ret += bt.tree[i]
		i &= i - 1
	}
	return ret
}
func (bt *bitTree) add(i, x int) {
	i++
	for i <= bt.size {
		bt.tree[i] += x
		i += i & -i
	}
}
func min(a []int) int {
	ret := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < ret {
			ret = a[i]
		}
	}
	return ret
}
