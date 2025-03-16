
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to check if first pair has greater second value than second pair
func greaterSecond(f, s pair[int]) bool {
	return f.second > s.second
}

// Function to find the greatest common divisor of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to find the least common multiple of two numbers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

// Function to find the least common multiple of all numbers in a slice
<<<<<<< HEAD
func lcmSlice(s []int) int {
	res := 1
	for i := 0; i < len(s); i++ {
		res = lcm(res, s[i])
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice2(s []int) int {
	res := 1
	for _, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice3(s []int) int {
	res := 1
	for i := range s {
		res = lcm(res, s[i])
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice4(s []int) int {
	res := 1
	for _, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice5(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice6(s []int) int {
	res := 1
	for i := range s {
		res = lcm(res, s[i])
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice7(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice8(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice9(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice10(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice11(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice12(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice13(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice14(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice15(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice16(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice17(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice18(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice19(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice20(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice21(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice22(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice23(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice24(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice25(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice26(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice27(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice28(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice29(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice30(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice31(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice32(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice33(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice34(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice35(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice36(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice37(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice38(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice39(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice40(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice41(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice42(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice43(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice44(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice45(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice46(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice47(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice48(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice49(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice50(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice51(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice52(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice53(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice54(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
	return res
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice55(s []int) int {
	res := 1
	for i, v := range s {
		res = lcm(res, v)
	}
=======
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// Function to find the least common multiple of all numbers in a slice
func lcmSlice(a []int) int {
	lcm := a[0]
	for i := 1; i < len(a); i++ {
		lcm = lcm * a[i] / gcd(lcm, a[i])
	}
	return lcm
}

// 
>>>>>>> 98c87cb78a (data updated)
