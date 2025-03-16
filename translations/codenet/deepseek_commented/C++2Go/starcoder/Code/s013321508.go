<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter the number of elements in the list")
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    fmt.Println("Enter the number of operations")
    M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    L := make([]int, 100000)
    for i := 0; i < N; i++ {
        l, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        L[i] = l
    }

    sort.Ints(L)

    for i := 0; i < M; i++ {
        max_L := L[len(L)-1]
        if max_L == 0 {
            break
        }

        max_L /= 2
        itr := sort.SearchInts(L, max_L)
        L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)
        L = L[:len(L)-1]
    }

    ans := 0
    for _, l := range L {
        ans += l
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

