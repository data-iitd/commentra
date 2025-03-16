<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
<<<<<<< HEAD
	var (
		n   int
		r   int
		c   int
		cnt int
		flag bool
	)
	for {
		fmt.Scanf("%d", &n)
		if n == 0 {
			break
		}
		flag = true
		r = (n + 1) / 2 + 1
		c = (n + 1) / 2
		arr := make([][]int, n+1)
		for i := range arr {
			arr[i] = make([]int, n+1)
		}
		arr[r][c] = cnt = 1
		for cnt!= n*n+1 {
			cnt++
			if flag {
				r++
				c++
				if c > n {
					c = 1
				}
				if r > n {
					r = 1
				}
				if arr[r][c]!= 0 {
					flag = false
					cnt--
				} else {
					arr[r][c] = cnt
				}
			} else {
				r++
				c--
				if c < 1 {
					c = n
				}
				if r > n {
					r = 1
				}
				if arr[r][c]!= 0 {
					flag = false
				} else {
					arr[r][c] = cnt
					flag = true
				}
			}
		}
		for r := 1; r < n+1; r++ {
			for c := 1; c < n+1; c++ {
				fmt.Printf("%4d", arr[r][c])
				arr[r][c] = 0
				if c == n {
					fmt.Println()
				}
=======
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Print("Enter the size of the magic square: ")
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		n, _ := strconv.Atoi(text)
		if n == 0 {
			break
		}
		magicSquare(n)
	}
}

func magicSquare(n int) {
	var r, c, cnt int
	var flag bool
	arr := make([][]int, n+1)
	for i := range arr {
		arr[i] = make([]int, n+1)
	}
	r = (n + 1) / 2 + 1
	c = (n + 1) / 2
	arr[r][c] = cnt = 1
	for cnt!= n*n+1 {
		cnt++
		if flag {
			r++
			c++
			if c > n {
				c = 1
			}
			if r > n {
				r = 1
			}
			if arr[r][c]!= 0 {
				flag = false
				cnt--
			} else {
				arr[r][c] = cnt
			}
		} else {
			r++
			c--
			if c < 1 {
				c = n
			}
			if r > n {
				r = 1
			}
			if arr[r][c]!= 0 {
				flag = false
			} else {
				arr[r][c] = cnt
				flag = true
			}
		}
	}
	for r := 1; r < n+1; r++ {
		for c := 1; c < n+1; c++ {
			fmt.Printf("%4d", arr[r][c])
			arr[r][c] = 0
			if c == n {
				fmt.Println()
>>>>>>> 98c87cb78a (data updated)
			}
		}
	}
}

