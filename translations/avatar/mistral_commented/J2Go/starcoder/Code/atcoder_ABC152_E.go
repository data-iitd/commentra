package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the least common multiple (lcm) of all integers in array A
func lcm ( A []int ) int {
	lcm := 1
	for _, a := range A {
		lcm = lcm * a / gcd( lcm, a )
	}
	return lcm
}

// Function to calculate the greatest common divisor (gcd) of two integers
func gcd ( a, b int ) int {
	if b == 0 {
		return a
	}
	return gcd( b, a % b )
}

// Function to calculate the modular inverse of a number
func modInv ( a, mod int ) int {
	return modPow( a, mod - 2, mod )
}

// Function to calculate the power of a number using modular arithmetic
func modPow ( b, e, mod int ) int {
	ans := 1
	x := b % mod
	for y := e ; y!= 0 ; y >>= 1 {
		if ( y & 1 ) == 1 {
			ans = ( ans * x ) % mod
		}
		x = ( x * x ) % mod
	}
	return ans
}

// Function to calculate the modular division of two numbers
func modDiv ( a, b, mod int ) int {
	return ( a % mod ) * modInv( b, mod ) % mod
}

// Function to calculate the answer using modular arithmetic
func answer ( A []int, mod int ) int {
	lcm := lcm( A )
	modLcm := lcm % mod
	ans := 0
	for _, a := range A {
		ans = ( ans + modDiv( modLcm, a, mod ) ) % mod
	}
	return ans
}

func main ( ) {
	var N int
	var A []int
	var mod int
	var ans int
	var lcm int
	var modLcm int
	var a int
	var x int
	var y int
	var z int
	var i int
	var line string
	var lines []string
	var sc *bufio.Scanner
	sc = bufio.NewScanner( os.Stdin )
	sc.Split( bufio.ScanWords )
	sc.Scan( )
	N, _ = strconv.Atoi( sc.Text( ) )
	A = make( []int, N )
	for i = 0 ; i < N ; i ++ {
		sc.Scan( )
		A[ i ], _ = strconv.Atoi( sc.Text( ) )
	}
	sc.Scan( )
	mod, _ = strconv.Atoi( sc.Text( ) )
	ans = 0
	lcm = 1
	for _, a := range A {
		lcm = lcm * a / gcd( lcm, a )
	}
	modLcm = lcm % mod
	for _, a := range A {
		ans = ( ans + modDiv( modLcm, a, mod ) ) % mod
	}
	fmt.Println( ans )
}

