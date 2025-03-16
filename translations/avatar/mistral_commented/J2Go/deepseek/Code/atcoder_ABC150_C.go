package main

import (
 "fmt"
 "strconv"
 "strings"
)

// Function to find permutations of a given string
func permutation(list []string, target string, ans string) []string {
 if len(target) <= 1 {
 list = append(list, ans+target)
 } else {
 for i := 0; i < len(target); i++ {
 permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
 }
 }
 return list
}

func main() {
 var n int
 fmt.Scan(&n)

 number := ""
 for i := 1; i <= n; i++ {
 number += strconv.Itoa(i)
 }

 listA := []string{}
 listA = permutation(listA, number, "")

 var sum int
 fmt.Scan(&sum)

 lines := make([][]string, sum)
 for i := 0; i < sum; i++ {
 lines[i] = make([]string, 1)
 fmt.Scan(&lines[i][0])
 }

 for j := 0; j < len(lines); j++ {
 for i := 0; i < len(listA); i++ {
 if strings.EqualFold(listA[i], lines[j][0]) {
 if sum == 0 {
 sum += i
 } else {
 sum -= i
 }
 }
 }
 }

 fmt.Println(abs(sum))
}

func abs(x int) int {
 if x < 0 {
 return -x
 }
 return x
}

