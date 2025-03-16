

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	sz   int
	prime = []int{
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
		73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
		127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
		233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
		353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
		467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
		547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
		607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
		739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
		811, 821, 823, 827, 829, 839, 853,
	}
	sqp = []int{
		4, 9, 25, 49, 121, 169, 289, 361, 529, 841, 961,
		1369, 1681, 1849, 2209, 2809, 3481, 3721, 4489, 5041,
		5329, 6241, 6889, 7921, 9409, 10201, 10609, 11449, 11881, 12769,
		16129, 17161, 18769, 19321, 22201, 22801, 24649, 26569, 27889, 29929,
		32041, 32761, 36481, 37249, 38809, 39601, 44521, 49729, 51529, 52441,
		54289, 57121, 58081, 63001, 66049, 69169, 72361, 73441, 76729, 78961,
		80089, 85849, 94249, 96721, 97969, 100489, 109561, 113569, 120409, 121801,
		124609, 128881, 134689, 139129, 143641, 146689, 151321, 157609, 160801,
		167281, 175561, 177241, 185761, 187489, 192721, 196249, 201601, 208849,
		212521, 214369, 218089, 229441, 237169, 241081, 249001, 253009, 259081,
		271441, 273529, 292681, 299209, 310249, 316969, 323761, 326041, 332929,
		344569, 351649, 358801, 361201, 368449, 375769, 380689, 383161, 398161,
		410881, 413449, 418609, 426409, 434281, 436921, 452929, 458329, 466489,
		477481, 491401, 502681, 516961, 528529, 537289, 546121, 552049, 564001,
		573049, 579121, 591361, 597529, 619369, 635209, 654481, 657721, 674041,
		677329, 683929, 687241, 703921, 727609,
	}
	tbl = make([]byte, MAX)
)

func main() {
	var (
		i, k, p, ans int64
		a, b, ll, rr int64
	)

	sieve()

	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d\n", &a, &b)
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	sz = int64(bsch(int(math.Sqrt(float64(b>>1)))))

	memset(idx, 1)
	for i = 0; i <= sz; i++ {
		p = int64(prime[i])
		for k = 1, j = p; j <= b; j *= p {
			pp[k] = j
			k++
		}
		for k--; k > 0; k-- {
			j = pp[k]
			ll = j * (1 + (a-1)/j)
			rr = j * (b / j)
			for ; ll <= rr; ll += j {
				x := ll - a
				if idx[x] == 0 || base[x] == p {
					continue
				}
				if idx[x] < k {
					idx[x] = 0
				} else {
					base[x] = p
					idx[x] = k
				}
			}
		}
	}

	ans = 0
	i = b - a + 1
	for ; i > 0; i-- {
		if idx[i]!= 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

func memset(idx []int, v int) {
	for i := range idx {
		idx[i] = v
	}
}

func bsch(x int) int {
	l, r := 0, sz
	for l < r {
		m := (l + r) / 2
		if prime[m] == x {
			return m
		}
		if prime[m] < x {
			l = m + 1
		} else {
			r = m
		}
	}
	return l - 1
}

const MAX = 1000000

var (
	idx []int
	base []int
	pp   [41]int64
)

func sieve() {
	for i := 1; i < 147; i++ {
		k := prime[i]
		for j := sqp[i]; j < MAX; j += k {
			tbl[j] = 1
		}
	}
	for i := 146; i < MAX; i++ {
		if tbl[i] == 0 {
			continue
		}
		for j := i + i; j < MAX; j += i {
			tbl[j] = 1
		}
	}
	sz = 146
	for i = sz; i > 0; i-- {
		if tbl[i] == 0 {
			continue
		}
		idx[i] = 0
		for j := i + i; j < MAX; j += i {
			tbl[j] = 1
		}
	}
}

func main() {
	var (
		a, b int64
		fmt.Fscanf(bufio.NewReader(os.Stdin), &a, &b)
		if b <= 1 {
			b = 2
		}
		if a <= 1 {
			a = 2
		}
		if a <= 1 {
			a = 2
		}
		ans := 0
		i := b - a + 1
		for ; i >= 1; i-- {
			p := prime[i]
			for k := 1; k-- {
				for j := p * p; j <= b; j += p {
					if tbl[j] == 0 {
						if idx[j-a] == 0 {
							idx[j-a] = 0 {
								ans++
							}
		}
		}
		fmt.Println(ans)
	}
}

func bsch(x int) int {
	return 0
}

func main() {
	var (
		i, k int) {
	for ; i >= 1; i-- {
		p := prime[i]
		for k = 1; k-- {
			for j := p * p; j <= b; j += p {
				if tbl[j] == 0 {
					if idx[j-a] == 0 {
						if idx[j-a] == 0 {
							ans++
						}
	}
	fmt.Println(ans)
}

func memset(idx []int, 0)
}

func bsch(x int) int {
	return 0
}

func main() {
	var (
		i, k int) {
	for ; i >= 1; i-- {
		p := prime[i]
		for k = 1; k-- {
			for j := p * p; j <= b; j += p {
				if tbl[j] == 0 {
					if idx[j-a] == 0 {
						if idx[j-a] == 0 {
							ans++
						}
	}
	fmt.Println(ans)
}

func memset(idx []int, 0)

func sieve() {
	int sz = 0
}

func main() {
	int prime[sz]
	int sqp[sz]
	int b = 0
}

func bsch(x int) int {
	for (int i = 0; i <= sz; i-- {
	int p = prime[i]
	for (int k = 1; k-- {
		for k = 1; k-- {
		for k = 1; k-- {
			for k = 1; k-- {
			for k = 1; k-- {
				if tbl[k] == 0 {
				if tbl[k] == 0 {
					if tbl[k] == 0 {
					if tbl[k] == 0 {
						if tbl[k] == 0 {
						if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
							if tbl[k] == 0 {
						9990








if tbl[k] == 0 {


if tbl[k] == 0 {