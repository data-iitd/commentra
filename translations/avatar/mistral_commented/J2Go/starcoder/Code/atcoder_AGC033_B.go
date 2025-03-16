
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
	fmt.Println("Enter the height of the grid:")
	h, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the width of the grid:")
	w, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the number of steps:")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the starting row of the safe zone:")
	sr, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the starting column of the safe zone:")
	sc, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the sequence of 'U' and 'D' representing the up and down movements:")
	s := reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")
	fmt.Println("Enter the sequence of 'L' and 'R' representing the left and right movements:")
	t := reader.ReadString('\n')
	t = strings.TrimSuffix(t, "\n")
	end := false
	usafe := 1
	dsafe := h
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
				dsafe = int(math.Min(float64(dsafe+1), float64(h)))
			} else if t[i-1] == 'D' {
				usafe = int(math.Max(float64(usafe-1), float64(1)))
			}
		}
	}
	lsafe := 1
	rsafe := w
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
				rsafe = int(math.Min(float64(rsafe+1), float64(w)))
			} else if t[i-1] == 'R' {
				lsafe = int(math.Max(float64(lsafe-1), float64(1)))
			}
		}
	}
	if sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe &&!end {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

