package main
import "fmt"
func main() {
	var a,b,i,max,n int
	fmt.Scanf("%d",&n)
	a = make([]int,n+1)
	b = make([]int,n+1)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d",&a[i+1])
	}
	max = a[1]
	for i = 1; i < n; i++ {
		if a[i+1] > max {
			max = a[i+1]
		}
	}
	countingSort(a,b,n,max)
	fmt.Printf("%d",b[1])
	for i = 2; i < n+1; i++ {
		fmt.Printf(" %d",b[i])
	}
	fmt.Printf("\n")
}
func countingSort(a []int,b []int,k,max int) {
	var c [I]int
	for i := 0; i <= I; i++ {
		c[i] = 0
	}
	for j := 0; j < k; j++ {
		c[a[j+1]]++
	}
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1]
	}
	for j := k; 0 < j; j-- {
		b[c[a[j]]] = a[j]
		c[a[j]]--
	}
}
