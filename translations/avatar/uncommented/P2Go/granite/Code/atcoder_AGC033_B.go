
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    H, W, N int
    s_r, s_c int
    S, T     string
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialBufSize = 4096
    const maxBufSize = 1000000
    scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
    scanner.Split(bufio.ScanWords)
    var err error
    H, err = scanner.nextInt()
    if err!= nil {
        panic(err)
    }
    W, err = scanner.nextInt()
    if err!= nil {
        panic(err)
    }
    N, err = scanner.nextInt()
    if err!= nil {
        panic(err)
    }
    s_r, err = scanner.nextInt()
    if err!= nil {
        panic(err)
    }
    s_c, err = scanner.nextInt()
    if err!= nil {
        panic(err)
    }
    S, err = scanner.nextString()
    if err!= nil {
        panic(err)
    }
    T, err = scanner.nextString()
    if err!= nil {
        panic(err)
    }
    scanner.Scan()
    Judge := false
    S_L, S_R, S_U, S_D := 0, 0, 0, 0
    T_L, T_R, T_U, T_D := 0, 0, 0, 0
    for x := 0; x < N; x++ {
        if S[x] == 'L' {
            S_L++
            if S_L-T_R-s_c == 0 {
                Judge = true
            }
        } else if S[x] == 'R' {
            S_R++
            if s_c+(S_R-T_L) == W+1 {
                Judge = true
            }
        } else if S[x] == 'U' {
            S_U++
            if S_U-T_D-s_r == 0 {
                Judge = true
            }
        } else if S[x] == 'D' {
            S_D++
            if s_r+(S_D-T_U) == H+1 {
                Judge = true
            }
        }
        if T[x] == 'L' {
            if S_R-T_L+s_c!= 1 {
                T_L++
            }
        }
        if T[x] == 'R' {
            if s_c+(T_R-S_L)!= W {
                T_R++
            }
        }
        if T[x] == 'U' {
            if S_D-T_U+s_r!= 1 {
                T_U++
            }
        }
        if T[x] == 'D' {
            if s_r+(T_D-S_U)!= H {
                T_D++
            }
        }
    }
    if Judge {
        fmt.Println("NO")
    } else {
        fmt.Println("YES")
    }
}

func (scanner *bufio.Scanner) nextInt() (int, error) {
    scanner.Scan()
    if err := scanner.Err(); err!= nil {
        return 0, err
    }
    num, err := strconv.Atoi(scanner.Text())
    if err!= nil {
        return 0, err
    }
    return num, nil
}

func (scanner *bufio.Scanner) nextString() (string, error) {
    scanner.Scan()
    if err := scanner.Err(); err!= nil {
        return "", err
    }
    return scanner.Text(), nil
}

