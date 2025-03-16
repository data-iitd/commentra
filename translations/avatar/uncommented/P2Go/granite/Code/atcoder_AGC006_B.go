
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
    N, X := readTwoInt64s(reader)
    from itertools import permutations
    def calc(x):
        def sub(y, debug=0):
            if debug:
                print("D", y)
            while len(y) > 1:
                y = [sorted(y[i:i+3])[1] for i in range(len(y)-2)]
                if debug:
                    print("D", y)
            return y
        y = sub(x)
        if y[0] == 2:
            pass
            sub(x, 1)
            print("=", x)
        return y[0]
    if X == 1 or X == N*2-1:
        print("No")
    else:
        print("Yes")
        if X == N*2-2:
            xs = list(range(N-1, X+2)) + list(range(1, N-1))
        else:
            ys = list(range(1, X-1)) + list(range(X+3, N*2))
            xs = ys[:N-3] + [X+2, X-1, X, X+1] + ys[N-3:]
        for x in xs:
            print(x)

func readTwoInt64s(reader *bufio.Reader) (int64, int64) {
    res := strings.Split(readLine(reader), " ")
    i0, err0 := strconv.ParseInt(res[0], 10, 64)
    checkError(err0)
    i1, err1 := strconv.ParseInt(res[1], 10, 64)
    checkError(err1)
    return i0, i1
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    panic(err)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

