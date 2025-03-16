
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	l, r, par int
}

var N [25]Node

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

func main() {
	var n, i, id, l, r, p int
	data := bufio.NewScanner(os.Stdin)
	data.Scan()
	n, _ = strconv.Atoi(data.Text())
	init(n)
	for i = 0; i < n; i++ {
		data.Scan()
		fmt.Sscanf(data.Text(), "%d %d %d", &id, &l, &r)
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

