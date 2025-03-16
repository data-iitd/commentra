package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	h, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	w, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	sr, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	sc, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s := scanner.Text()
	scanner.Scan()
	t := scanner.Text()
	var end bool
	var usafe, dsafe, lsafe, rsafe int
	usafe = 1
	dsafe = h
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'U' {
			usafe++
		} else if s[i] == 'D' {
			dsafe--
		}
		if usafe > dsafe {
			end = true
			break
		}
		if i > 0 {
			if t[i-1] == 'U' {
				dsafe = min(dsafe+1, h)
			} else if t[i-1] == 'D' {
				usafe = max(usafe-1, 1)
			}
		}
	}
	lsafe = 1
	rsafe = w
	for i := n - 1; i >= 0; i-- {
		if s[i] == 'L' {
			lsafe++
		} else if s[i] == 'R' {
			rsafe--
		}
		if lsafe > rsafe {
			end = true
			break
		}
		if i > 0 {
			if t[i-1] == 'L' {
				rsafe = min(rsafe+1, w)
			} else if t[i-1] == 'R' {
				lsafe = max(lsafe-1, 1)
			}
		}
	}
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe &&!end {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

