package main
import "fmt"
import "math"
import "sort"
import "strings"

func main() {
	var N, K int
	fmt.Scanf("%d %d", &N, &K)
	S := make([]byte, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%c", &S[i])
	}
	if K >= 15 {
		fmt.Println(int64(N) * int64(min(S)))
		return
	}
	if 1<<uint(K) >= N {
		fmt.Println(int64(N) * int64(min(S)))
		return
	}
	S = append(S, S...)
	S = S[:N]
	sort.Slice(S, func(i, j int) bool { return S[i] < S[j] })
	fmt.Println(int64(N) * int64(S[0]))
}

func min(S []byte) byte {
	m := S[0]
	for _, c := range S {
		if c < m {
			m = c
		}
	}
	return m
}

