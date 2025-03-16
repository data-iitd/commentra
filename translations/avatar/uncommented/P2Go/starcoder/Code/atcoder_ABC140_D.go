package main
import "fmt"
func main() {
	var N, K int
	var S string
	fmt.Scanf("%d %d %s", &N, &K, &S)
	var seg_cnt int
	for i := 0; i < N-1; i++ {
		if S[i]!= S[i+1] {
			seg_cnt++
		}
	}
	var cur_happy int
	if 2*K >= seg_cnt {
		cur_happy = N - 1
	} else {
		cur_happy = N - 1 - seg_cnt
	}
	var ans int
	if cur_happy + 2*K >= N-1 {
		ans = N - 1
	} else {
		ans = cur_happy + 2*K
	}
	fmt.Println(ans)
}
