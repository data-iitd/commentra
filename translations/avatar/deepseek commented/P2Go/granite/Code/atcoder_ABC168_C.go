

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the lengths of the sides of the triangle and the time: ")
    text, _ := reader.ReadString('\n')
    parts := strings.Split(text, " ")
    a, _ := strconv.Atoi(parts[0])
    b, _ := strconv.Atoi(parts[1])
    h, _ := strconv.Atoi(parts[2])
    m, _ := strconv.Atoi(parts[3])
    C := math.Abs(360/60*float64(m)-360/12*float64(h)-360/12/60*float64(m))
    if C > 180 {
        C = 360 - C
    }
    cosC := math.Cos(math.radians(C))
    length := math.Sqrt(float64(a*a+b*b-2*a*b*cosC))
    fmt.Println(length)
}

