package main
import "fmt"
func main() {
	var N, K int
	fmt.Scanf("%d %d", &N, &K)
	L := make([]int, N+1)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &L[i])
	}
	L = append(L, -1)
	path := []int{1}
	ind := 0
	count := 0
	x := 1
	t := -1
	flag := false
	Hash := make(map[int]int)
	for i := 0; i < N+1; i++ {
		ne := L[x]
		if Hash[ne]!= 0 {
			flag = true
			t = Hash[ne]
			break
		}
		path = append(path, ne)
		ind += 1
		Hash[ne] = ind
		x = ne
	}
	if flag == true {
		loop := path[t:]
		if K < len(path) {
			fmt.Println(path[K])
		} else {
			K = K - len(path)
			K = K % len(loop)
			fmt.Println(loop[K])
		}
	} else {
		fmt.Println(path[K-1])
	}
}
