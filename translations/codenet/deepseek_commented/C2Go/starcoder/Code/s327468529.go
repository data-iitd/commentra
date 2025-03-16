#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
<<<<<<< HEAD
	"os"
	"sort"
	"strconv"
	"strings"
	"time"
=======
	"sort"
	"strconv"
	"strings"
>>>>>>> 98c87cb78a (data updated)
)

const (
	N_MAX = 1048576
)

var (
<<<<<<< HEAD
	n, m, h, w, k, q int
	va, vb, vc, vd, ve, vf int64
	ua, ub, uc, ud, ue, uf uint64
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
	umin, umax, smin, smax, gcd, bitpow, divide, udiff, sdiff, bitcount uint64
	a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z []int64
	cnt, pcnt, result, maybe, sum, item int64
	dpcell *int64
	x [3005][3005]uint64
	table [3005][3005]int64
	s [3005]byte
	t [3005]byte
	u [3005]byte
	xy [3005]hwll
	tup [3005]hwllc
)

func init() {
	n = 4
	m = 0
	// scanf("%llu", &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// va--;
	// vb--;
	// scanf("%llu%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for (i := 0; i < n; i++) {
	// 	// scanf("%lld", &a[i]);
	// 	scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for i := 0; i < 0; i++ {
		// scanf("%lld%llu", &xy[i].a, &xy[i].b);
		// scanf("%llu%llu%llu", &tup[i].a, &tup[i].b, &tup[i].c);
		// scanf("%llld", &c[i]);

		// scanf("%lld", &a[i]);
		// scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		// a[i]--
		// b[i]--
		// c[i]--
		// d[i]--
		// xy[i].a--
		// xy[i].b--
		// tup[i].a--
		// tup[i].b--
	}
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	// for (i := 0; i < n; i++) {
	// 	// scanf("%lld%llu", &a[i], &b[i]);
	// 	scanf("%lld", &b[i]);
	// 	// a[i]--
	// 	// b[i]--
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &d[i]);
	// 	// scanf("%lld", &e[i]);
	// 	// c[i]--
	// 	// d[i]--
	// }

	// for (i := 0; i < q; i++) {
	// 	// scanf("%lld%llu", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &c[i]);
	// 	// xy[i].a--
	// 	// xy[i].b--
	// }

	// for (i := 0; i < h; i++) {
	// 	for j := 0; j < w; j++ {
	// 		scanf("%lld", &table[i][j]);
	// 		// table[i][j]--;
	// 	}
	// }
	// for (i := 0; i < h; i++) {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%llu", &q);
}

func main() {
	var (
		i, j int64
	)

	n = 4
	m = 0

	// scanf("%llu", &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// va--
	// vb--
	// scanf("%llu%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for i := 0; i < n; i++ {
	// 	// scanf("%lld", &a[i]);
	// 	scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for i := 0; i < 0; i++ {
		// scanf("%lld%llu", &xy[i].a, &xy[i].b);
		// scanf("%llu%llu%llu", &tup[i].a, &tup[i].b, &tup[i].c);
		// scanf("%llld", &c[i]);

		// scanf("%lld", &a[i]);
		// scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		// a[i]--
		// b[i]--
		// c[i]--
		// d[i]--
		// xy[i].a--
		// xy[i].b--
		// tup[i].a--
		// tup[i].b--
	}
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	// for i := 0; i < n; i++ {
	// 	// scanf("%lld%llu", &a[i], &b[i]);
	// 	scanf("%lld", &b[i]);
	// 	// a[i]--
	// 	// b[i]--
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &d[i]);
	// 	// scanf("%lld", &e[i]);
	// 	// c[i]--
	// 	// d[i]--
	// }

	// for i := 0; i < q; i++ {
	// 	// scanf("%lld%llu", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &c[i]);
	// 	// xy[i].a--
	// 	// xy[i].b--
	// }

	// for i := 0; i < h; i++ {
	// 	for j := 0; j < w; j++ {
	// 		scanf("%lld", &table[i][j]);
	// 		// table[i][j]--;
	// 	}
	// }
	// for i := 0; i < h; i++ {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%llu", &q);

	solve()
}

func solve() {
	var (
		i, j int64
	)

	result = 1
	for i := 0; i < n*3; i++ {
		var (
			v int64
		)
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}
		// printf("%llu %llu %llu\n", cnt[0], cnt[1], cnt[2]);

		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			// result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {

			if (cnt[(v+1)%3]+cnt[(v+2)%3]) > cnt[v] {
				// printf("*%llu\n", (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]);
				result *= (cnt[(v+1)%3]+cnt[(v+2)%3]) - cnt[v]
				result %= FOD
				pcnt++
				// printf("pcnt: %llu\n", pcnt);
			}

			cnt[v]++
		}
		// printf("%llu\n", result);
	}

	for i := 1; i <= n; i++ {
		result = (result * i) % FOD
	}

	fmt.Println(result)
	// printf("%.15f\n", dresult);
	// puts(s);

	return
}

func isinrange(left, x, right int64) bool {
	return left <= x && x <= right
}

func isinrange_soft(left, x, right int64) bool {
	return left <= x && x <= right || left >= x && x >= right
}

func sw(l, r *int64) {
	if *l == *r {
		return
	}
	t := *l
	*l = *r
	*r = t
}

func frac(n, r, m uint64) uint64 {
	if n < 0 || r < 0 || n < r {
		return 0
	}
	return frac[n] * (invf[r] * invf[n-r] % m) % m
}

func ncr(n, r, m uint64) uint64 {
	if n < 0 || r < 0 || n < r {
		return 0
	}
	return frac[n] * (invf[r] * invf[n-r] % m) % m
}

func main() {
	var (
		i, j int64
	)

	n = 4
	m = 0

	// scanf("%llu", &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &k, &n, &m);
	// scanf("%llu%llu", &h, &w);
	// scanf("%llu", &q);
	// scanf("%lld%lld", &va, &vb, &vc, &vd);
	// va--
	// vb--
	// scanf("%llu%llu%llu%llu", &ua, &ub, &uc, &ud, &ue);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%s", u);
	// scanf("%llu", &k);
	// scanf("%lld", &m);
	// for i := 0; i < n; i++ {
	// 	// scanf("%lld", &a[i]);
	// 	scanf("%lld", &d[i]);
	// }
	// scanf("%llu", &q);
	for i := 0; i < 0; i++ {
		// scanf("%lld%llu", &xy[i].a, &xy[i].b);
		// scanf("%llu%llu%llu", &tup[i].a, &tup[i].b, &tup[i].c);
		// scanf("%llld", &c[i]);

		// scanf("%lld", &a[i]);
		// scanf("%lld", &b[i]);
		// scanf("%lld", &c[i]);
		// scanf("%lld", &d[i]);
		// a[i]--
		// b[i]--
		// c[i]--
		// d[i]--
		// xy[i].a--
		// xy[i].b--
		// tup[i].a--
		// tup[i].b--
	}
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	// for i := 0; i < n; i++ {
	// 	// scanf("%lld%llu", &a[i], &b[i]);
	// 	scanf("%lld", &b[i]);
	// 	// a[i]--
	// 	// b[i]--
	// 	// scanf("%lld", &c[i]);
	// 	// scanf("%lld", &d[i]);
	// 	// scanf("%lld", &e[i]);
	// 	// c[i]--
	// 	// d[i]--
	// }

	// for i := 0; i < q; i++ {
	// 	// scanf("%lld%llu", &xy[i].a, &xy[i].b);
	// 	scanf("%lld", &c[i]);
	// 	// xy[i].a--
	// 	// xy[i].b--
	// }

	// for i := 0; i < h; i++ {
	// 	for j := 0; j < w; j++ {
	// 		scanf("%lld", &table[i][j]);
	// 		// table[i][j]--;
	// 	}
	// }
	// for i := 0; i < h; i++ {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%llu", &q);

	solve()
}

func solve() {
	var (
		i, j int64
	)

	result = 1
	for i := 0; i < n*3; i++ {
		var (
			v int64
		)
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}
		// printf("%llu %llu %llu\n", cnt[0], cnt[1], cnt[2]);

		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			// result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD);
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {

			if (cnt[(v+1)%3]+cnt[(v+2)%
=======
	n, m, k, q int
	va, vb, vc, vd int64
	ua, ub, uc, ud, ue uint64
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
	h, w        int64
	gin         [N_MAX]uint64
	a           [N_MAX]int64
	b           [N_MAX]int64
	c           [N_MAX]int64
	d           [N_MAX]int64
	e           [N_MAX]int64
	s           [N_MAX]byte
	t           [N_MAX]byte
	u           [N_MAX]byte
	xy          [N_MAX]struct {
		a, b int64
	}
	tup [N_MAX]struct {
		a, b, c uint64
	}
	table [N_MAX][N_MAX]int64
	cnt   [3]int64
	pcnt  int64
	x     [N_MAX][N_MAX]uint64
)

func main() {
	n, m = 4, 0
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000000000
	// n, m = 1000000000, 1000
>>>>>>> 98c87cb78a (data updated)
