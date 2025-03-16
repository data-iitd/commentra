package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    n, _ := strconv.Atoi(os.Args[1])
    ac_count := 0
    wa_count := 0
    tle_count := 0
    re_count := 0
    for i := 0; i < n; i++ {
        s := strings.TrimSpace(os.Args[2+i])
        if s == "AC" {
            ac_count += 1
        } else if s == "WA" {
            wa_count += 1
        } else if s == "TLE" {
            tle_count += 1
        } else if s == "RE" {
            re_count += 1
        }
    }
    fmt.Printf("AC x %d\n", ac_count)
    fmt.Printf("WA x %d\n", wa_count)
    fmt.Printf("TLE x %d\n", tle_count)
    fmt.Printf("RE x %d\n", re_count)
}

