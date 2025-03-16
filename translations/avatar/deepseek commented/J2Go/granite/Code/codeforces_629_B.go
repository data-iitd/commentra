

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
    fmt.Println("Enter the number of entries:")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    FfriendPerDay := make([]int, 367)
    MfriendPerDay := make([]int, 367)
    answer := 0
    for i := 0; i < n; i++ {
        fmt.Println("Enter gender (M or F) and start/end day:")
        input := strings.Split(reader.ReadLine()[0], " ")
        gender := input[0][0]
        a, _ := strconv.Atoi(input[1])
        b, _ := strconv.Atoi(input[2])
        for j := a; j <= b; j++ {
            if gender == 'M' {
                MfriendPerDay[j]++
            } else {
                FfriendPerDay[j]++
            }
            if MfriendPerDay[j] < FfriendPerDay[j] {
                if MfriendPerDay[j] > answer {
                    answer = MfriendPerDay[j]
                }
            } else {
                if FfriendPerDay[j] > answer {
                    answer = FfriendPerDay[j]
                }
            }
        }
    }
    fmt.Println(answer * 2)
}
