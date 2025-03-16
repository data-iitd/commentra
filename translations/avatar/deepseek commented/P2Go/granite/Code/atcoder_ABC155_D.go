
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	sort.Ints(a)

	ll := -1e18 - 1
	rr := 1e18 + 1

	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := 0

		for i := 0; i < n; i++ {
			if a[i] < 0 {
				l, r := -1, n
				for l+1 < r {
					c := (l + r) / 2
					if a[i]*a[c] < x {
						r = c
					} else {
						l = c
					}
				}
				tot += n - r
			} else {
				l, r := -1, n
				for l+1 < r {
					c := (l + r) / 2
					if a[i]*a[c] < x {
						l = c
					} else {
						r = c
					}
				}
				tot += r
			}

			if a[i]*a[i] < x {
				tot--
			}
		}

		tot /= 2

		if tot < k {
			ll = x
		} else {
			rr = x
		}
	}

	fmt.Println(ll)
}

