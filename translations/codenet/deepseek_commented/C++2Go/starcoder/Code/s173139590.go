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
<<<<<<< HEAD
    n, _ := strconv.Atoi(readLine(reader))
=======
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

>>>>>>> 98c87cb78a (data updated)
    ac_count := 0
    wa_count := 0
    tle_count := 0
    re_count := 0
<<<<<<< HEAD
    for i := 0; i < n; i++ {
        s := readLine(reader)
=======

    for i := 0; i < n; i++ {
        s := strings.TrimSpace(readLine(reader))
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    fmt.Printf("AC x %d\n", ac_count)
    fmt.Printf("WA x %d\n", wa_count)
    fmt.Printf("TLE x %d\n", tle_count)
    fmt.Printf("RE x %d\n", re_count)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

