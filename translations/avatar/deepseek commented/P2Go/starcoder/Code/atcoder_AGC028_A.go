
package main
import (
"fmt"
"math"
"os"
"strconv"
"strings"
)
func main() {
var N, M int
var S, T string
var list_S, list_T []string
var Number_i []int
var Number_iMN []int
var Number_j []int
var Kaburi_j []int
var Kaburi_i []int
var counter int
var Flag int
var Kaburi_Size int
fmt.Scanf("%d %d", &N, &M)
S = strings.TrimSpace(os.Stdin.ReadString('\n'))
T = strings.TrimSpace(os.Stdin.ReadString('\n'))
list_S = strings.Split(S, "")
list_T = strings.Split(T, "")
Number_i = make([]int, N)
for i := 0; i < N; i++ {
Number_i[i] = i
}
for i := 0; i < N; i++ {
Number_iMN = append(Number_iMN, int(float64(i)*float64(M)/float64(N)))
}
Number_j = make([]int, M)
for j := 0; j < M; j++ {
Number_j[j] = j
}
Kaburi_j = make([]int, 0)
for _, j := range Number_j {
if _, ok := map[int]bool{j: true}[int(float64(j)*float64(N)/float64(M))]; ok {
Kaburi_j = append(Kaburi_j, j)
}
}
Kaburi_i = make([]int, 0)
for _, j := range Kaburi_j {
Kaburi_i = append(Kaburi_i, int(float64(j)*float64(N)/float64(M)))
}
counter = 0
Flag = 0
Kaburi_Size = len(Kaburi_i)
for counter = 0; counter < Kaburi_Size; counter++ {
if list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]] {
Flag = 1
break
}
}
if Flag == 1 {
fmt.Println(-1)
} else {
fmt.Println(int(float64(N)*float64(M)/math.GCD(N, M)))
}
}
