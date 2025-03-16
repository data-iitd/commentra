package main

import (
 "fmt"
 "sort"
)

func main() {
 var a, b, c int
 fmt.Scan(&a, &b, &c)

 // Sort the values of a, b, and c
 sort.Ints([]int{a, b, c})

 // Print the sorted values of a, b, and c
 fmt.Println(a, b, c)
}

