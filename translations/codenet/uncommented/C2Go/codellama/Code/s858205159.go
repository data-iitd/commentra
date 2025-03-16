#include<stdio.h>
#include<stdlib.h>
#include<string.h>

type node struct{
	key int
	next *node
	prev *node
}

var nil *node

func listSearch(key int) *node{
	cur := nil.next
	for cur != nil {
		if cur.key == key { break }
		cur = cur.next
	}
	return cur
}

func init(){
	nil = &node{next: nil, prev: nil}
}

func printList(){
	cur := nil.next
	isf := 1
	for {
		if cur == nil { break }
		if isf == 0 { printf(" ") }
		printf("%d", cur.key)
		cur = cur.next
		isf = 0
	}
	printf("\n")
}

func deleteNode(t *node){
	if t == nil { return }
	t.prev.next = t.next
	t.next.prev = t.prev
	free(t)
}

func deleteFirst(){
	t := nil.next
	if t == nil { return }
	deleteNode(t)
}

func deleteLast(){
	t := nil.prev
	if t == nil { return }
	deleteNode(t)
}

func deleteKey(key int){
	t := listSearch(key)
	if t != nil { deleteNode(t) }
}


func insert(key int){
	x := &node{key: key, next: nil, prev: nil}
	x.prev = nil
	x.next = nil.next
	x.next.prev = x
	nil.next = x
}

func main(){
	var key, n, i int
	var size int
	var com [20]byte
	var np, nd int
	scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		scanf("%s%d", com, &key)
		if com[0] == 'i' { insert(key); np++; size++ }
		else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' { deleteFirst() }
				else if com[6] == 'L' { deleteLast() }
			}
			else {
				deleteKey(key); nd++
			}
			size--
		}
	}

	printList()
	return 0
}

