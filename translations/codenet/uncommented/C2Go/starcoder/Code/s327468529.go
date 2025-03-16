
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const (
	N_MAX = 1048576
)

var (
	n, m, h, w, k, q int
	va, vb, vc, vd, ve, vf int64
	ua, ub, uc, ud, ue, uf uint64
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
	umin, umax, smin, smax, gcd, bitpow, divide, udiff, sdiff, bitcount uint64
	BEGCMP = func(NAME func(left, right interface{}) int) func(left, right interface{}) int {
		return func(left, right interface{}) int {
			l := left.(TYPE)
			r := right.(TYPE)
			if l < r {
				return -1
			}
			if l > r {
				return +1
			}
			return 0
		}
	}
	DEFLR = func(TYPE interface{}) (l, r interface{}) {
		l = left.(TYPE)
		r = right.(TYPE)
	}
	CMPRET = func(L, R interface{}) {
		if L.(TYPE) < R.(TYPE) {
			return -1
		}
		if L.(TYPE) > R.(TYPE) {
			return +1
		}
	}
	pullcomp = func(left, right interface{}) int {
		l := left.(uint64)
		r := right.(uint64)
		if l < r {
			return -1
		}
		if l > r {
			return +1
		}
		return 0
	}
	prevcomp = func(left, right interface{}) int {
		l := left.(int64)
		r := right.(int64)
		if r < l {
			return -1
		}
		if r > l {
			return +1
		}
		return 0
	}
	psllcomp = func(left, right interface{}) int {
		l := left.(int64)
		r := right.(int64)
		if l < r {
			return -1
		}
		if l > r {
			return +1
		}
		return 0
	}
	pcharcomp = func(left, right interface{}) int {
		l := left.(byte)
		r := right.(byte)
		if l < r {
			return -1
		}
		if l > r {
			return +1
		}
		return 0
	}
	pdoublecomp = func(left, right interface{}) int {
		l := left.(float64)
		r := right.(float64)
		if l < r {
			return -1
		}
		if l > r {
			return +1
		}
		return 0
	}
	pstrcomp = func(left, right interface{}) int {
		l := left.(string)
		r := right.(string)
		return strings.Compare(l, r)
	}
	phwllABcomp = func(left, right interface{}) int {
		l := left.(hwll)
		r := right.(hwll)
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		return 0
	}
	phwllREVcomp = func(left, right interface{}) int {
		l := left.(hwll)
		r := right.(hwll)
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		return 0
	}
	ptriplecomp = func(left, right interface{}) int {
		l := left.(hwllc)
		r := right.(hwllc)
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		if l.c < r.c {
			return -1
		}
		if l.c > r.c {
			return +1
		}
		return 0
	}
	ptripleREVcomp = func(left, right interface{}) int {
		l := left.(hwllc)
		r := right.(hwllc)
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		if l.c < r.c {
			return -1
		}
		if l.c > r.c {
			return +1
		}
		return 0
	}
	ptripleCABcomp = func(left, right interface{}) int {
		l := left.(hwllc)
		r := right.(hwllc)
		if l.c < r.c {
			return -1
		}
		if l.c > r.c {
			return +1
		}
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		return 0
	}
	phwrealcomp = func(left, right interface{}) int {
		l := left.(hwreal)
		r := right.(hwreal)
		if l.a < r.a {
			return -1
		}
		if l.a > r.a {
			return +1
		}
		if l.b < r.b {
			return -1
		}
		if l.b > r.b {
			return +1
		}
		return 0
	}
	pquadcomp = func(left, right interface{}) int {
		l := left.(linell)
		r := right.(linell)
		ac := phwllABcomp(l.a, r.a)
		if ac!= 0 {
			return ac
		}
		bc := phwllABcomp(l.b, r.b)
		if bc!= 0 {
			return bc
		}
		return 0
	}
	pfracomp = func(left, right interface{}) int {
		l := left.(hwllc)
		r := right.(hwllc)
		if l.a*r.b < l.b*r.a {
			return -1
		}
		if l.a*r.b > l.b*r.a {
			return +1
		}
		return 0
	}
	isinrange = func(left, x, right interface{}) bool {
		return left.(int64) <= x.(int64) && x.(int64) <= right.(int64)
	}
	isinrange_soft = func(left, x, right interface{}) bool {
		return left.(int64) <= x.(int64) && x.(int64) <= right.(int64) || left.(int64) >= x.(int64) && x.(int64) >= right.(int64)
	}
	sw = func(l, r *int64) {
		if *l == *r {
			return
		}
		t := *l
		*l = *r
		*r = t
	}
	frac [N_MAX * 3]uint64
	invf [N_MAX * 3]uint64
	ncr  func(n, r, m uint64) uint64
	a    [N_MAX + 5]int64
	b    [N_MAX + 5]int64
	c    [N_MAX + 5]int64
	d    [N_MAX + 5]int64
	e    [N_MAX * 4]int64
	s    [N_MAX + 1]byte
	t    [N_MAX + 1]byte
	u    [N_MAX + 1]byte
	xy   [N_MAX + 5]hwll
	tup  [N_MAX + 5]hwllc
	table [3005][3005]int64
	gin  [N_MAX]uint64
	cnt  [3]int64
	pcnt int64
	x    [3005][3005]uint64
)

func main() {
	var (
		i, j int
	)
	n, m = 4, 0
	// fmt.Scanf("%v", &m)
	// fmt.Scanf("%v%v", &h, &w)
	fmt.Scanf("%v", &n, &m)
	// fmt.Scanf("%v", &k, &n, &m)
	// fmt.Scanf("%v%v", &h, &w)
	// fmt.Scanf("%v", &q)
	// fmt.Scanf("%v%v%v%v", &va, &vb, &vc, &vd)
	// va--
	// vb--
	// fmt.Scanf("%v%v%v%v%v", &ua, &ub, &uc, &ud, &ue)
	fmt.Scanf("%s", s)
	// fmt.Scanf("%s", t)
	// fmt.Scanf("%s", u)
	// fmt.Scanf("%v", &k)
	// fmt.Scanf("%v", &m)
	// for i = 0; i < n; i++ {
	// 	// fmt.Scanf("%v", &a[i])
	// 	fmt.Scanf("%v", &d[i])
	// }
	// fmt.Scanf("%v", &q)
	for i = 0; i < 0; i++ {
		// fmt.Scanf("%v%v", &xy[i].a, &xy[i].b)
		// fmt.Scanf("%v%v%v", &tup[i].a, &tup[i].b, &tup[i].c)
		// fmt.Scanf("%v", &c[i])

		fmt.Scanf("%v", &a[i])
		// fmt.Scanf("%v", &b[i])
		// fmt.Scanf("%v", &c[i])
		// fmt.Scanf("%v", &d[i])
		// a[i]--
		// b[i]--
		// c[i]--
		// d[i]--
		// xy[i].a--
		// xy[i].b--
		// tup[i].a--
		// tup[i].b--
	}
	// fmt.Scanf("%v", &m)
	// fmt.Scanf("%v", &q)
	// for i = 0; i < n; i++ {
	// 	// fmt.Scanf("%v%v", &a[i], &b[i])
	// 	fmt.Scanf("%v", &b[i])
	// 	// a[i]--
	// 	// b[i]--
	// 	// fmt.Scanf("%v", &c[i])
	// 	// fmt.Scanf("%v", &d[i])
	// 	// fmt.Scanf("%v", &e[i])
	// 	// c[i]--
	// 	// d[i]--
	// }

	// for i = 0; i < q; i++ {
	// 	// fmt.Scanf("%v%v", &xy[i].a, &xy[i].b)
	// 	fmt.Scanf("%v", &c[i])
	// 	// xy[i].a--
	// 	// xy[i].b--
	// }

	// for i = 0; i < h; i++ {
	// 	for j = 0; j < w; j++ {
	// 		fmt.Scanf("%v", &table[i][j])
	// 		// table[i][j]--
	// 	}
	// }
	// for i = 0; i < h; i++ {
	// 	fmt.Scanf("%s", s[i])
	// }
	// fmt.Scanf("%v", &q)

	solve()
}

func init() {
	var (
		i, j int
	)
	n, m = 4, 0
	// fmt.Scanf("%v", &m)
	// fmt.Scanf("%v%v", &h, &w)
	fmt.Scanf("%v", &n, &m)
	// fmt.Scanf("%v", &k, &n, &m)
	// fmt.Scanf("%v%v", &h, &w)
	// fmt.Scanf("%v", &q)
	// fmt.Scanf("%v%v%v%v", &va, &vb, &vc, &vd)
	// va--
	// vb--
	// fmt.Scanf("%v%v%v%v%v", &ua, &ub, &uc, &ud, &ue)
	fmt.Scanf("%s", s)
	// fmt.Scanf("%s", t)
	// fmt.Scanf("%s", u)
	// fmt.Scanf("%v", &k)
	// fmt.Scanf("%v", &m)
	// for i = 0; i < n; i++ {
	// 	// fmt.Scanf("%v", &a[i])
	// 	fmt.Scanf("%v", &d[i])
	// }
	// fmt.Scanf("%v", &q)
	for i = 0; i < 0; i++ {
		// fmt.Scanf("%v%v", &xy[i].a, &xy[i].b)
		// fmt.Scanf("%v%v%v", &tup[i].a, &tup[i].b, &tup[i].c)
		// fmt.Scanf("%v", &c[i])

		fmt.Scanf("%v", &a[i])
		// fmt.Scanf("%v", &b[i])
		// fmt.Scanf("%v", &c[i])
		// fmt.Scanf("%v", &d[i])
		// a[i]--
		// b[i]--
		// c[i]--
		// d[i]--
		// xy[i].a--
		// xy[i].b--
		// tup[i].a--
		// tup[i].b--
	}
	// fmt.Scanf("%v", &m)
	// fmt.Scanf("%v", &q)
	// for i = 0; i < n; i++ {
	// 	// fmt.Scanf("%v%v", &a[i], &b[i])
	// 	fmt.Scanf("%v", &b[i])
	// 	// a[i]--
	// 