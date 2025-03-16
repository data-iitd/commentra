package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	// <START-OF-CODE>
	N, X, A := read()
	S := make([]int, N)
	for i := 0; i < N; i++ {
		S[i] = A[i]
	}
	for i := 1; i < N; i++ {
		S[i] += S[i-1]
	}
	ans := 1000000000000000000
	for k := 1; k < N; k++ {
		E := k*X + 2*sum(S, N-2*k-1, -1, -k)
		if E < ans {
			ans = E
		}
	}
	fmt.Println(ans + N*X + 5*S[N-1])
	// 