
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX = 25

type Node struct {
	l, r, par int
}

var N [MAX]Node

func main() {
	var n, i, id, l, r, p int

	data := bufio.NewReader(os.Stdin)

	fmt.Fscanf(data, "%d\n", &n)

	init(n)

	for i = 0; i < n; i++ {
		fmt.Fscanf(data, "%d %d %d\n", &id, &l, &r)

		if l!= -1 {
			N[id].l = l
			N[l].par = id
		}
		if r!= -1 {
			N[id].r = r
			N[r].par = id
		}
	}

	for i = 0; i < n; i++ {
		if N[i].par == -1 {
			p = i
			break
		}
	}

	fmt.Println("Preorder")
	Preorder(p)
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println()
}

func init(n int) {
	for i := 0; i < n; i++ {
		N[i].par = N[i].l = N[i].r = -1
	}
}

func Preorder(p int) {
	if p!= -1 {
		fmt.Printf(" %d", p)
		Preorder(N[p].l)
		Preorder(N[p].r)
	}
}

func Inorder(p int) {
	if p!= -1 {
		Inorder(N[p].l)
		fmt.Printf(" %d", p)
		Inorder(N[p].r)
	}
}

func Postorder(p int) {
	if p!= -1 {
		Postorder(N[p].l)
		Postorder(N[p].r)
		fmt.Printf(" %d", p)
	}
}

