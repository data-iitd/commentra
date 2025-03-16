
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func get_nums(num, t int) []int {
    ans := make([]int, num)
    for i := 0; i < num; i++ {
        if i < t%num {
            ans[i] = t/num + 1
        } else {
            ans[i] = t/num
        }
    }
    return ans
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    input := strings.Split(strings.TrimSpace(readLine(reader)), " ")
    var n, k, l, r, sa, sk int
    n, _ = strconv.Atoi(input[0])
    k, _ = strconv.Atoi(input[1])
    l, _ = strconv.Atoi(input[2])
    r, _ = strconv.Atoi(input[3])
    sa, _ = strconv.Atoi(input[4])
    sk, _ = strconv.Atoi(input[5])
    ans := get_nums(k, sk)
    for i := 0; i < n-k; i++ {
        ans = append(ans, get_nums(n-k, sa-sk)[i])
    }
    fmt.Println(strings.TrimSpace(strings.Join(strconv.FormatInt(int64(ans[0]), 10), " ")))
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

