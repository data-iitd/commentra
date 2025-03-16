
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers N and K from input
	N, K := readTwoInts()

	// Read a list of integers from input
	lst := readNInt64s(N)

	// Initialize lists to hold positive and negative numbers
	lstP := make([]int64, 0)
	lstM := make([]int64, 0)

	// Iterate through the list to categorize numbers
	for i := 0; i < N; i++ {
		// Decrease K for each zero encountered
		if lst[i] == 0 {
			K--
		}
		// Add positive numbers to lstP
		if lst[i] > 0 {
			lstP = append(lstP, lst[i])
		}
		// Add negative numbers to lstM
		if lst[i] < 0 {
			lstM = append(lstM, lst[i])
		}
	}

	// Initialize variables to track the last indices of positive and negative lists
	p, m := 0, 0
	x, y := 0, len(lstM)-1
	lastX, lastY := len(lstP), len(lstM)

	// Define a function to check the minimum value based on K
	check := func(k int) int64 {
		ans := int64(1e9) // Initialize answer with a large number
		// Iterate through possible counts of positive numbers used
		for j := 0; j <= k; j++ {
			// Check if the current count of positives and negatives is valid
			if j > lastX || k-j > lastY {
				continue // Skip invalid combinations
			}
			// Determine the maximum positive number used
			if j == 0 {
				p = 0 // No positive numbers used
			} else {
				p = int(lstP[j-1]) // Get the largest positive number used
			}
			// Determine the maximum negative number used
			if k-j == 0 {
				m = 0 // No negative numbers used
			} else {
				m = int(lstM[lastY-(k-j)]) // Get the largest negative number used
			}
			// Calculate the minimum value based on the current combination
			ans = min(ans, int64(2*p+abs(m)), int64(p+2*abs(m)))
		}
		return ans // Return the minimum value found
	}

	// Print the result of the check function with K
	fmt.Println(check(K))
}

// Read two integers from input
func readTwoInts() (int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	split := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(split[0])
	k, _ := strconv.Atoi(split[1])
	return n, k
}

// Read N integers from input
func readNInt64s(n int) []int64 {
	res := make([]int64, n)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		ok := scanner.Scan()
		if!ok {
			panic("Scan failed")
		}
		num, err := strconv.ParseInt(scanner.Text(), 10, 64)
		if err!= nil {
			panic("Parse failed")
		}
		res[i] = num
	}
	return res
}

// Calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Calculate the minimum of two integers
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Calculate the minimum of three integers
func min3(a, b, c int64) int64 {
	return min(min(a, b), c)
}

// Calculate the minimum of four integers
func min4(a, b, c, d int64) int64 {
	return min(min3(a, b, c), d)
}

// Calculate the minimum of five integers
func min5(a, b, c, d, e int64) int64 {
	return min(min4(a, b, c, d), e)
}

// Calculate the minimum of six integers
func min6(a, b, c, d, e, f int64) int64 {
	return min(min5(a, b, c, d, e), f)
}

// Calculate the minimum of seven integers
func min7(a, b, c, d, e, f, g int64) int64 {
	return min(min6(a, b, c, d, e, f), g)
}

// Calculate the minimum of eight integers
func min8(a, b, c, d, e, f, g, h int64) int64 {
	return min(min7(a, b, c, d, e, f, g), h)
}

// Calculate the minimum of nine integers
func min9(a, b, c, d, e, f, g, h, i int64) int64 {
	return min(min8(a, b, c, d, e, f, g, h), i)
}

// Calculate the minimum of ten integers
func min10(a, b, c, d, e, f, g, h, i, j int64) int64 {
	return min(min9(a, b, c, d, e, f, g, h, i), j)
}

// Calculate the minimum of eleven integers
func min11(a, b, c, d, e, f, g, h, i, j, k int64) int64 {
	return min(min10(a, b, c, d, e, f, g, h, i, j), k)
}

// Calculate the minimum of twelve integers
func min12(a, b, c, d, e, f, g, h, i, j, k, l int64) int64 {
	return min(min11(a, b, c, d, e, f, g, h, i, j, k), l)
}

// Calculate the minimum of thirteen integers
func min13(a, b, c, d, e, f, g, h, i, j, k, l, m int64) int64 {
	return min(min12(a, b, c, d, e, f, g, h, i, j, k, l), m)
}

// Calculate the minimum of fourteen integers
func min14(a, b, c, d, e, f, g, h, i, j, k, l, m, n int64) int64 {
	return min(min13(a, b, c, d, e, f, g, h, i, j, k, l, m), n)
}

// Calculate the minimum of fifteen integers
func min15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o int64) int64 {
	return min(min14(a, b, c, d, e, f, g, h, i, j, k, l, m, n), o)
}

// Calculate the minimum of sixteen integers
func min16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p int64) int64 {
	return min(min15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o), p)
}

// Calculate the minimum of seventeen integers
func min17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q int64) int64 {
	return min(min16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p), q)
}

// Calculate the minimum of eighteen integers
func min18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r int64) int64 {
	return min(min17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q), r)
}

// Calculate the minimum of nineteen integers
func min19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s int64) int64 {
	return min(min18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r), s)
}

// Calculate the minimum of twenty integers
func min20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t int64) int64 {
	return min(min19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s), t)
}

// Calculate the minimum of twenty-one integers
func min21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u int64) int64 {
	return min(min20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t), u)
}

// Calculate the minimum of twenty-two integers
func min22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v int64) int64 {
	return min(min21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u), v)
}

// Calculate the minimum of twenty-three integers
func min23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w int64) int64 {
	return min(min22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v), w)
}

// Calculate the minimum of twenty-four integers
func min24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x int64) int64 {
	return min(min23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w), x)
}

// Calculate the minimum of twenty-five integers
func min25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y int64) int64 {
	return min(min24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x), y)
}

// Calculate the minimum of twenty-six integers
func min26(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z int64) int64 {
	return min(min25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y), z)
}

// Calculate the minimum of twenty-seven integers
func min27(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1 int64) int64 {
	return min(min26(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z), a1)
}

// Calculate the minimum of twenty-eight integers
func min28(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1 int64) int64 {
	return min(min27(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1), b1)
}

// Calculate the minimum of twenty-nine integers
func min29(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1 int64) int64 {
	return min(min28(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1), c1)
}

// Calculate the minimum of thirty integers
func min30(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1 int64) int64 {
	return min(min29(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1), d1)
}

// Calculate the minimum of thirty-one integers
func min31(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1, e1 int64) int64 {
	return min(min30(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1), e1)
}

// Calculate the minimum of thirty-two integers
func min32(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1, e1, f1 int64) int64 {
	return min(min31(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1, e1), f1)
}

// Calculate the minimum of thirty-three integers
func min33(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1, e1, f1, g1 int64) int64 {
	return min(min32(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1, t1, u1, v1, w1, x1, y1, z1, a2, b2, c2, d2, e2, f2, g2, h2, i2, j2, k2, l2, m2, n2, o2, p2, q2, r2, s2, t2, u2, v2, w2, x2, y2, z2, a3, b3, c3, d3, e3, f3, g3, h3, i3, j3, k3, l3, m3, n3, o3, p3, q3, r3, s3, t3, u3, v3, w3, x3, y3, z3, a4, b4, c4, d4, e4, f4, g4, h4, i4, j4, k4, l4, m4, n4, o4, p4, q4, r4, s4, t4, u4, v4, w4, x4, y4, z4, a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5, n5, o5, p5, q5, r5, s5, t5, u5, v5, w5, x5, y5, z5, a6, b6, c6, d6, e6, f6, g6, h6, i6, j6, k6, l6, m6, n6, o6, p6, q6, r6, s6, t6, u6, v6, w6, x6, y6, z6, a7, b7, c7, d7, e7, f7, g7, h7, i7, j7, k7, l7, m7, n7, o7, p7, q7, r7, s7, t7, u7, v7, w7, x7, y7, z7, a8, b8, c8, d8, e8, f8, g8, h8, i8, j8, k8, l8, m8, n8, o8, p8, q8, r8, s8, t8, u8, v8, w8, x8, y8, z8, a9, b9, c9, d9, e9, f9, g9, h9, i9, j9, k9, l9, m9, n9, o9, p9, q9, r9, s9, t9, u9, v9, w9, x9, y9, z9, a10, b10, c10, d10, e10, f10, g10, h10, i10, j10, k10, l10, m10, n10, o10, p10, q10, r10, s10, t10, u10, v10, w10, x10, y10, z10, a11, b11, c11, d11, e11, f11, g11, h11, i11, j11, k11, l11, m11, n11, o11