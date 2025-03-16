<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Computes the greatest common divisor of two numbers x and y
func gcd(x, y int) int {
	if x < y {
		x, y = y, x
	}
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x
}

// Computes the least common multiple of two numbers x and y
func lcm(x, y int) int {
	return x / gcd(x, y) * y
}

// Computes the factorial of a number k modulo 10^9 + 7
func kaijo(k int) int {
	sum := 1
	for i := 1; i <= k; i++ {
		sum *= i
		sum %= 1000000000 + 7
	}
	return sum
}

// Utility functions to find the maximum and minimum of two numbers
func lmax(s, t int) int {
	if s > t {
		return s
	} else {
		return t
	}
}

func lmin(s, t int) int {
	if s < t {
		return s
	} else {
		return t
	}
}

// Computes the sum of all integers from 1 to n that are divisible by b
func sum(n, b int) int {
	sum := 0
	for b <= n {
		sum += n / b
<<<<<<< HEAD
		n = n % b
		b++
=======
		n = (n + 1) % b
>>>>>>> 98c87cb78a (data updated)
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k
func sum2(n, b, k int) int {
	sum := 0
	for b <= n {
		sum += n / b
<<<<<<< HEAD
		n = n % b
		b++
	}
	return sum + lmax(n-k, 0)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum3(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum4(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum5(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum6(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum7(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum8(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum9(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum10(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum11(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum12(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum13(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum14(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum15(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum16(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum17(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum18(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum19(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum20(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum21(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum22(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum23(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum24(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum25(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum26(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum27(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum28(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum29(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum30(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum31(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum32(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum33(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum34(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum35(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum36(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum37(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum38(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum39(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum40(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum41(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum42(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, but only if k is not 0
func sum43(n, b, k int) int {
	if k == 0 {
		return sum(n, b)
	}
	return sum2(n, b, k)
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// 
=======
		n = (n + 1) % b
		if n >= k {
			sum++
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m
func sum3(n, b, k, m int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l
func sum4(n, b, k, m, l int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even
func sum5(n, b, k, m, l int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r
func sum6(n, b, k, m, l, r int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s
func sum7(n, b, k, m, l, r, s int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d
func sum8(n, b, k, m, l, r, s, d int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t
func sum9(n, b, k, m, l, r, s, d, t int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u
func sum10(n, b, k, m, l, r, s, d, t, u int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u, and are divisible by v
func sum11(n, b, k, m, l, r, s, d, t, u, v int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
		if sum%v!= 0 {
			return u
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u, and are divisible by v,
// and are less than or equal to w
func sum12(n, b, k, m, l, r, s, d, t, u, v, w int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
		if sum%v!= 0 {
			return u
		}
		if sum > w {
			return w
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u, and are divisible by v,
// and are less than or equal to w, and are greater than or equal to x
func sum13(n, b, k, m, l, r, s, d, t, u, v, w, x int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
		if sum%v!= 0 {
			return u
		}
		if sum > w {
			return w
		}
		if sum < x {
			return x
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u, and are divisible by v,
// and are less than or equal to w, and are greater than or equal to x, and
// are divisible by y
func sum14(n, b, k, m, l, r, s, d, t, u, v, w, x, y int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
		if sum%v!= 0 {
			return u
		}
		if sum > w {
			return w
		}
		if sum < x {
			return x
		}
		if sum%y!= 0 {
			return x
		}
	}
	return sum
}

// Computes the sum of all integers from 1 to n that are divisible by b and
// have a remainder of k, and are less than or equal to m, and are greater
// than or equal to l, and are even, and are less than or equal to r, and
// are greater than or equal to s, and are divisible by d, and are less than
// or equal to t, and are greater than or equal to u, and are divisible by v,
// and are less than or equal to w, and are greater than or equal to x, and
// are divisible by y, and are less than or equal to z
func sum15(n, b, k, m, l, r, s, d, t, u, v, w, x, y, z int) int {
	sum := 0
	for b <= n {
		sum += n / b
		n = (n + 1) % b
		if n >= k {
			sum++
		}
		if sum > m {
			return sum
		}
		if sum < l {
			return l
		}
		if sum%2!= 0 {
			return l
		}
		if sum > r {
			return r
		}
		if sum < s {
			return s
		}
		if sum%d!= 0 {
			return s
		}
		if sum > t {
			return t
		}
		if sum < u {
			return u
		}
		if sum%v!= 0 {
			return u
		}
		if su
>>>>>>> 98c87cb78a (data updated)
