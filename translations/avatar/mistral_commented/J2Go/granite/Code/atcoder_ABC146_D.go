

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
 n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
 g := make([][]int, n)
 for i := 0; i < n; i++ {
 g[i] = make([]int, 0)
 }
 for i := 0; i < n-1; i++ {
 a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
 b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
 a--
 b--
 g[a] = append(g[a], b)
 g[b] = append(g[b], a)
 }
 ans := make([]int, n-1)
 dfs(0, -1, -1, &ans)
 max := 0
 for _, temp := range ans {
 if temp > max {
 max = temp
 }
 }
 fmt.Println(max)
 for _, c := range ans {
 fmt.Println(c)
 }
}

func readLine(reader *bufio.Reader) string {
 str, _, err := reader.ReadLine()
 if err == nil {
 return strings.Trim(string(str), " \r\n")
 }
 return ""
}

func dfs(to int, color int, parents int, ans *[]int) {
 k := 1
 for _, e := range g[to] {
 if e == parents {
 continue
 }
 if k == color {
 k++
 }
 (*ans)[e] = k
 dfs(e, k, to, ans)
 k++
 }
}

