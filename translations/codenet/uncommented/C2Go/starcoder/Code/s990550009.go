package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var a [100000]int
	var cnt int = 1
	var isup bool
	var issame bool = false
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	if a[0] < a[1] {
		isup = true
	} else if a[0] > a[1] {
		isup = false
	} else {
		issame = true
	}
	for i := 1; i < n-1; i++ {
		if issame {
			if a[i]!= a[i+1] {
				issame = false
				if a[i] < a[i+1] {
					isup = true
				} else {
					isup = false
				}
			}
		} else {
			if isup && a[i] <= a[i+1] {
				;
			} else if!isup && a[i] >= a[i+1] {
				;
			} else {
				if i+2 < n {
					if a[i+1] < a[i+2] {
						isup = true
					} else if a[i+1] > a[i+2] {
						isup = false
					} else {
						issame = true
					}
					cnt++
				} else {
					cnt++
					break
				}
			}
		}
	}
	fmt.Printf("%d\n", cnt)
}

