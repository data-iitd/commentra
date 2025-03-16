package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inputs, _ := reader.ReadString('\n')
	inputParts := strings.Split(strings.TrimSpace(inputs), " ")
	N, _ := strconv.Atoi(inputParts[0])
	K, _ := strconv.Atoi(inputParts[1])

	AInput, _ := reader.ReadString('\n')
	A := []int{}
	AParts := strings.Split(strings.TrimSpace(AInput), " ")
	for _, part := range AParts {
		num, _ := strconv.Atoi(part)
		A = append(A, num)
	}

	sort.Ints(A)

	ll := int(-1e18) - 1
	rr := int(1e18) + 1

	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := 0

		for i := 0; i < N; i++ {
			if A[i] < 0 {
				l := -1
				r := N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						r = c
					} else {
						l = c
					}
				}
				tot += N - r
			} else {
				l := -1
				r := N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}
				tot += r
			}

			if A[i]*A[i] < x {
				tot--
			}
		}

		tot /= 2

		if tot < K {
			ll = x
		} else {
			rr = x
		}
	}

	fmt.Println(ll)
}
