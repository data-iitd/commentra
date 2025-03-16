package main
import "fmt"
import "sort"
func main() {
	var a,b []int
	var i,N int
	var frontHalf,backHalf int
	fmt.Scanf("%d",&N)
	a= make([]int,N)
	b= make([]int,N)
	for i=0;i<N;i++ {
		fmt.Scanf("%d",a[i])
		b[i]=a[i]
	}
	sort.Ints(b)
	frontHalf=b[N/2-1]
	backHalf=b[N/2]
	for i=0;i<N;i++ {
		if a[i]<backHalf {
			fmt.Printf("%d\n",backHalf)
		} else {
			fmt.Printf("%d\n",frontHalf)
		}
	}
}
