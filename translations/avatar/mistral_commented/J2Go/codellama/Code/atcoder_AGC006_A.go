
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func getFail(b []byte, m int) {
    // Function declaration and initialization of variables
    j := 0
    f := make([]int, m+1)
    f[0] = f[1] = 0

    // Main logic of the function
    for i := 2; i <= m; i++ {
        for j > 0 && b[j+1] != b[i] {
            j = f[j]
        }
        if b[j+1] == b[i] {
            j++
        }
        f[i] = j
    }
}

func main() {
    // Main function declaration and initialization of variables
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)

    n, _ := strconv.Atoi(readLine(in))
    s1 := readLine(in)
    str := readLine(in)

    cnt := 0

    // Concatenating the two strings and creating character arrays for each
    for i := 0; i < n; i++ {
        b[cnt] = str[i]
        cnt++
    }
    for i := 0; i < n; i++ {
        b[cnt] = s1[i]
        cnt++
    }

    getFail(b, cnt)

    len := min(f[cnt], min(n, n))

    fmt.Println(2*n - len)

    out.Flush()
}

func readLine(in *bufio.Reader) string {
    str, _ := in.ReadString('\n')
    return str[:len(str)-1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

// 