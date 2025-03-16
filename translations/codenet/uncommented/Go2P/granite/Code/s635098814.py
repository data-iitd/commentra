

import sys

# ReadString returns a WORD string.
def ReadString():
    return sys.stdin.readline().rstrip()

# ReadInt returns an integer.
def ReadInt():
    return int(ReadString())

# ReadIntSlice returns an integer slice that has n integers.
def ReadIntSlice(n):
    return [ReadInt() for _ in range(n)]

# ReadFloat64 returns an float64.
def ReadFloat64():
    return float(ReadString())

# ReadFloat64Slice returns an float64 slice that has n float64.
def ReadFloat64Slice(n):
    return [ReadFloat64() for _ in range(n)]

# ReadruneSlice returns a rune slice.
def ReadruneSlice():
    return list(ReadString())

# ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
# For debugging use.
def ZeroPaddingRuneSlice(n, digitsNum):
    sn = bin(n)[2:]
    residualLength = digitsNum - len(sn)
    if residualLength <= 0:
        return sn
    zeros = ['0'] * residualLength
    return ''.join(zeros) + sn

# ChMin accepts a pointer of integer and a target value.
# If target value is SMALLER than the first argument,
#	then the first argument will be updated by the second argument.
def ChMin(updatedValue, target):
    if updatedValue > target:
        updatedValue = target
        return True
    return False

# ChMax accepts a pointer of integer and a target value.
# If target value is LARGER than the first argument,
#	then the first argument will be updated by the second argument.
def ChMax(updatedValue, target):
    if updatedValue < target:
        updatedValue = target
        return True
    return False

# NthBit returns nth bit value of an argument.
# n starts from 0.
def NthBit(num, nth):
    return (num >> nth) & 1

# OnBit returns the integer that has nth ON bit.
# If an argument has nth ON bit, OnBit returns the argument.
def OnBit(num, nth):
    return num | (1 << nth)

# OffBit returns the integer that has nth OFF bit.
# If an argument has nth OFF bit, OffBit returns the argument.
def OffBit(num, nth):
    return num & ~(1 << nth)

# PopCount returns the number of ON bit of an argument.
def PopCount(num):
    res = 0
    for i in range(70):
        if ((num >> i) & 1) == 1:
            res += 1
    return res

# Max returns the max integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def Max(*integers):
    m = integers[0]
    for i in range(1, len(integers)):
        if m < integers[i]:
            m = integers[i]
    return m

# Min returns the min integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def Min(*integers):
    m = integers[0]
    for i in range(1, len(integers)):
        if m > integers[i]:
            m = integers[i]
    return m

# DigitSum returns digit sum of a decimal number.
# DigitSum only accept a positive integer.
def DigitSum(n):
    if n < 0:
        return -1
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    return res

# DigitNumOfDecimal returns digits number of n.
# n is non negative number.
def DigitNumOfDecimal(n):
    res = 0
    while n > 0:
        n //= 10
        res += 1
    return res

# Sum returns multiple integers sum.
def Sum(*integers):
    s = 0
    for i in range(len(integers)):
        s += integers[i]
    return s

# Kiriage returns Ceil(a/b)
# a >= 0, b > 0
def Kiriage(a, b):
    return (a + (b - 1)) // b

# PowInt is integer version of math.Pow
# PowInt calculate a power by Binary Power (二分累乗法(O(log e))).
def PowInt(a, e):
    if a < 0 or e < 0:
        raise Exception("[argument error]: PowInt does not accept negative integers")
    if e == 0:
        return 1
    if e % 2 == 0:
        halfE = e // 2
        half = PowInt(a, halfE)
        return half * half
    return a * PowInt(a, e-1)

# AbsInt is integer version of math.Abs
def AbsInt(a):
    if a < 0:
        return -a
    return a

# Gcd returns the Greatest Common Divisor of two natural numbers.
# Gcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Gcd uses the Euclidean Algorithm.
def Gcd(a, b):
    if a <= 0 or b <= 0:
        raise Exception("[argument error]: Gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a
    # Euclidean Algorithm
    while b > 0:
        div = a % b
        a, b = b, div
    return a

# Lcm returns the Least Common Multiple of two natural numbers.
# Lcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Lcd uses the Euclidean Algorithm indirectly.
def Lcm(a, b):
    if a <= 0 or b <= 0:
        raise Exception("[argument error]: Gcd only accepts two NATURAL numbers")
    # a = a'*gcd, b = b'*gcd, a*b = a'*b'*gcd^2
    # a' and b' are relatively prime numbers
    # gcd consists of prime numbers, that are included in a and b
    gcd = Gcd(a, b)
    # not (a * b / gcd), because of reducing a probability of overflow
    return (a // gcd) * b

# Strtoi is a wrapper of strconv.Atoi().
# If strconv.Atoi() returns an error, Strtoi calls panic.
def Strtoi(s):
    if i, err := strconv.Atoi(s)
    if err!= nil {
        raise Exception("[argument error]: Strtoi only accepts integer string")
    return i

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(*A):
    res = []
    for i := 0; i < len(A); i++ {
        str = str(A[i])
        // str := strconv.Itoa(A[i])
        res = append(res, []rune(str)...)

        if i!= len(A)-1 {
            res = append(res,'')
        }
    }
    return string(res)

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(num, digitsNum int) {
    sn := bin(num)[2:]
    residualLength := digitsNum - len(sn)
    if residualLength <= 0 {
        return sn
    }
    zeros := []rune{'0'}
    for i := 0; i < residualLength; i++ {
        zeros = append(zeros, '0')
    }
    return string(zeros)
}

// ChMin accepts a pointer of integer and a target value.
// If target value is SMALLER than the first argument,
//	then the first argument will be updated by the second argument.
func ChMin(updatedValue, target int) bool {
    if *updatedValue > target {
        *updatedValue = target
        return true
    }
    return false
}

// ChMax accepts a pointer of integer and a target value.
// If target value is SMALLER than the first argument,
//	then the first argument will be updated by the second argument.
func ChMax(updatedValue, target int) bool {
    if *updatedValue < target {
        *updatedValue = target
        return true
    }
    return false
}

// NthBit returns nth bit value of an argument.
// n starts from 0.
func NthBit(num, nth int) int {
    return (num >> uint(nth)) & 1
}

// OnBit returns the integer that has nth ON bit.
// If an argument has nth ON bit.
func OnBit(num, nth int) int {
    return num | (1 << uint(nth))
}

// OffBit returns the integer that has nth OFF bit.
// If an argument has nth OFF bit.
func OffBit(num, nth int) int {
    return num & ^(1 << uint(nth))
}

// PopCount returns the number of ON bit of an argument.
// n starts from 0.
func PopCount(num int) int {
    res := 0
    for i := 0; i < 70; i++ {
        if ((num >> uint(i)) & 1
		res++
	}
	return res
}

// Max returns the max integer among input set.
// n is non negative number.
func Max(integers...int) int {
    m := integers[0]
    for i := 1; i < len(integers)-1 {
        m := integers[0]
        for i := 1; i < len(integers)-1 {
        m := integers[0]
        for i := 0; i < len(integers) {
            m := 0
            for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i := 0; i < len(integers) {
                    m := integers[0]
                    for i := 0; i < len(integers) {
                m := integers[0]
                for i :