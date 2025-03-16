

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var min int64 = 9223372036854775807

func main() {
    reader := bufio.NewReader(os.Stdin)
    var arr []int64
    for i := 0; i < 4; i++ {
        num, _ := reader.ReadString('\n')
        num = strings.TrimSpace(num)
        n, _ := strconv.ParseInt(num, 10, 64)
        arr = append(arr, n)
    }
    var ops []string
    for i := 0; i < 3; i++ {
        op, _ := reader.ReadString('\n')
        op = strings.TrimSpace(op)
        ops = append(ops, op)
    }
    util(arr, ops, 0)
    fmt.Println(min)
}

func util(arr []int64, ops []string, idx int) {
    if idx == 3 {
        min = int64(math.Min(float64(min), float64(arr[0])))
        return
    }
    for i := 0; i < len(arr); i++ {
        for j := i + 1; j < len(arr); j++ {
            var a []int64
            for k := 0; k < len(arr); k++ {
                if k!= j && k!= i {
                    a = append(a, arr[k])
                }
            }
            var res int64
            if idx < 3 && ops[idx] == "+" {
                res = arr[i] + arr[j]
            } else {
                res = arr[i] * arr[j]
            }
            a = append(a, res)
            util(a, ops, idx+1)
        }
    }
}

This code is almost identical to the Java code, with the only difference being the syntax for reading input and printing output. The logic for finding the minimum value remains the same.

Please note that the code provided is just an example and may need to be modified based on your specific requirements.