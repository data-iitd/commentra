package main
import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d%d", &n, &m)
	e := make([][3]int, m * 2)
	for i := 0; i < m * 2; i++ {
		e[i][0], e[i][1], e[i][2] = 0, 0, 0
	}
	for i := 0; i < m; i++ {
		fmt.Scanf("%d%d", &e[i][0], &e[i][1])
		e[i][2] = 1
		e[m + i][0], e[m + i][1], e[m + i][2] = e[i][1], e[i][0], 2
	}
	var ans int64
	for i := 1; i <= n; i++ {
		var cnt [3]int
		var vis [1000010]bool
		var d [1000010]int
		var T int
		var ok bool
		var dfs func(int, int)
		dfs = func(x, l int) {
			vis[x] = true
			cnt[l]++
			d[x] = l
			for i := e[T]; i[0]!= 0; i = e[i[0]] {
				T++
				if!vis[i[1]] {
					dfs(i[1], (l + i[2]) % 3)
				} else if (l + i[2]) % 3!= d[i[1]] {
					ok = false
				}
			}
		}
		dfs(i, 0)
		s := cnt[0] + cnt[1] + cnt[2]
		if!ok {
			ans += s * s
		} else {
			if cnt[0] && cnt[1] && cnt[2] {
				ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
			} else {
				ans += T / 2
			}
		}
	}
	fmt.Println(ans)
}

