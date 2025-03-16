package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the height of the grid")
	h, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the width of the grid")
	w, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the number of moves")
	n, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the starting row")
	sr, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the starting column")
	sc, _ := strconv.Atoi(reader.ReadString())
	fmt.Println("Enter the sequence of moves in a string")
	s := reader.ReadString()
	fmt.Println("Enter the sequence of moves in a string")
	t := reader.ReadString()
	var usafe, dsafe, lsafe, rsafe int
	end := false
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

