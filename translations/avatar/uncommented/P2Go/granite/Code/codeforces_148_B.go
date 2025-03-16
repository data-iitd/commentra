
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var (
    princess int
    dragon int
    t int
    f int
    c int
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        var err error
        princess, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    if scanner.Scan() {
        var err error
        dragon, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    if scanner.Scan() {
        var err error
        t, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    if scanner.Scan() {
        var err error
        f, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    if scanner.Scan() {
        var err error
        c, err = strconv.Atoi(scanner.Text())
        if err!= nil {
            panic(err)
        }
    }
    if dragon <= princess {
        fmt.Println(0)
        return
    }
    result := 0
    position := t * princess
    position += princess * position / (dragon - princess)
    for position < c {
        result += 1
        position += princess * position / dragon
        position += princess * f
        position += princess * position / (dragon - princess)
    }
    fmt.Println(result)
}
