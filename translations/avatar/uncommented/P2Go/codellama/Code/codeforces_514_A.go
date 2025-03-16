
package main

import "fmt"

func main() {
    var ip string
    fmt.Scan(&ip)
    st := ""
    if len(ip) != 1 {
        if ip[0] == "9" {
            st = "9"
            ip = ip[1:]
        }
        for _, i := range ip {
            if i > 4 {
                n := 9 - int(i)
                st += string(n)
            } else {
                st += string(i)
            }
        }
    } else {
        st = ip
    }
    fmt.Println(st)
}

