

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, k, _ := readLine(reader)
    aaa := make([]int, n)
    for i := 0; i < n; i++ {
        a, _ := strconv.Atoi(readLine(reader)[0])
        aaa[i] = a - 1
    }
    links := make([][]int, n)
    for i := 0; i < n; i++ {
        links[i] = make([]int, 0)
    }
    for i := 0; i < n; i++ {
        if aaa[i]!= 0 {
            links[aaa[i]] = append(links[aaa[i]], i)
        }
    }
    ans := dfs(links, n, k, 0, 0)
    if aaa[0]!= 1 {
        ans++
    }
    fmt.Println(ans)
}

func dfs(links [][]int, n, k, v, p int) (int, int) {
    heightFromLeaf := 0
    cutCount := 0
    for _, u := range links[v] {
        hgt, cut := dfs(links, n, k, u, v)
        heightFromLeaf = max(heightFromLeaf, hgt)
        cutCount += cut
    }
    heightFromLeaf += 1
    if p!= 0 && heightFromLeaf == k {
        heightFromLeaf = 0
        cutCount += 1
    }
    return heightFromLeaf, cutCount
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func readLine(reader *bufio.Reader) []string {
    line, _, err := reader.ReadLine()
    if err == io.EOF {
        return nil
    }

    return strings.Fields(string(line))
}

