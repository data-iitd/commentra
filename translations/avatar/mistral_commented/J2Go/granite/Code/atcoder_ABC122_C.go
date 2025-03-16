

package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := fmt.Fscanf(reader, "%d\n", &n)
    checkError(err)
    qTemp, err := fmt.Fscanf(reader, "%d\n", &q)
    checkError(err)

    c, err := reader.ReadString('\n')
    checkError(err)
    c = c[:len(c)-1]

    frag := make([]int, n+1)
    rui := make([]int, n+1)

    for i := 2; i <= n; i++ {
        if string(c[i-2:i]) == "AC" {
            frag[i]++
        }
        rui[i] = rui[i-1] + frag[i]
    }

    for i := 0; i < q; i++ {
        leftTemp, err := fmt.Fscanf(reader, "%d\n", &left)
        checkError(err)
        rightTemp, err := fmt.Fscanf(reader, "%d\n", &right)
        checkError(err)

        fmt.Println(rui[right] - rui[left])
    }

    fmt.Println("