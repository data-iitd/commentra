

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type BT struct {
	parent int
	left   int
	right  int
}

var bt [26]BT
var n int

func Preorder(a int) {
	if a == -1 {
		return
	}
	fmt.Printf(" %d", a)
	Preorder(bt[a].left)
	Preorder(bt[a].right)
}

func Inorder(a int) {
	if a == -1 {
		return
	}
	Inorder(bt[a].left)
	fmt.Printf(" %d", a)
	Inorder(bt[a].right)
}

func Postorder(a int) {
	if a == -1 {
		return
	}
	Postorder(bt[a].left)
	Postorder(bt[a].right)
	fmt.Printf(" %d", a)
}

func main() {
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" {
			break
		}
		n, _ = strconv.Atoi(text)
		for i := 0; i < n; i++ {
			bt[i].parent = -1
		}
		for i := 0; i < n; i++ {
			fields := strings.Fields(scanner.Text())
			num, _ := strconv.Atoi(fields[0])
			bt[num].left = -1
			bt[num].right = -1
			if len(fields) == 3 {
				bt[num].left, _ = strconv.Atoi(fields[1])
				bt[num].right, _ = strconv.Atoi(fields[2])
				if bt[num].left!= -1 {
					bt[bt[num].left].parent = num
				}
				if bt[num].right!= -1 {
					bt[bt[num].right].parent = num
				}
			}
		}
		for i := 0; bt[i].parent!= -1; i++ {
		}
		fmt.Println("Preorder")
		Preorder(i)
		fmt.Println()
		fmt.Println("Inorder")
		Inorder(i)
		fmt.Println()
		fmt.Println("Postorder")
		Postorder(i)
		fmt.Println()
	}
}

