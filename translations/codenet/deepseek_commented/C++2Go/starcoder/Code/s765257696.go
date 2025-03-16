<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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
    p := make([]int, n)
    for i := 0; i < n; i++ {
        p[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }
    ans := 0
    for i := 0; i < n-2; i++ {
        if p[i] > p[i+1] && p[i+1] > p[i+2] {
            ans++
        }
        if p[i] < p[i+1] && p[i+1] < p[i+2] {
            ans++
        }
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

<<<<<<< HEAD
=======
Translate the above Go code to Python and end with comment "
>>>>>>> 98c87cb78a (data updated)
