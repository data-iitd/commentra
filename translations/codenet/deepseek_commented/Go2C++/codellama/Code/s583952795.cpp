
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Go:

// type Pair struct {
//     p1, p2 interface{}
// }

// const (
//     initialBufSize = 1e4
//     maxBufSize     = 1e8
// )

// var (
//     scanner = bufio.NewScanner(os.Stdin)
//     writer  = bufio.NewWriter(os.Stdout)
// )

// func main() {
//     buf := make([]byte, initialBufSize)
//     scanner.Buffer(buf, maxBufSize)
//     scanner.Split(bufio.ScanWords)

//     // Read two integers N and K from standard input
//     N, K := readInt(), readInt()

//     // Convert N to base K and print the length of the resulting string
//     s := TenToN(N, K)
//     fmt.Println(len(s))
// }

// // TenToN converts a decimal number to a base N string
// func TenToN(number int, n int) string {
//     var s string
//     tmp := number
//     for {
//         s = i2s(tmp%n) + s
//         if tmp < n {
//             break
//         }
//         tmp /= n
//     }
//     return s
// }

// /*==========================================
//  *             Library
//  *==========================================*/

// // write writes a string to the writer
// func write(s string) {
//     writer.WriteString(s)
// }

// // print flushes the writer to ensure all buffered data is written to the output
// func print() {
//     writer.Flush()
// }

// // readLine reads a single line from the standard input
// func readLine() (s string) {
//     if scanner.Scan() {
//         s = scanner.Text()
//     }
//     return s
// }

// // readInt reads an integer from the standard input
// func readInt() (read int) {
//     scanner.Scan()
//     read, err := strconv.Atoi(scanner.Text())
//     if err != nil {
//         panic(err)
//     }
//     return
// }

// // readFloat reads a float from the standard input
// func readFloat() (read float64) {
//     scanner.Scan()
//     read, err := strconv.ParseFloat(scanner.Text(), 64)
//     if err != nil {
//         panic(err)
//     }
//     return
// }

// // readRunes reads a slice of runes from the standard input
// func readRunes() (read []rune) {
//     scanner.Scan()
//     for _, v := range scanner.Text() {
//         read = append(read, v)
//     }
//     return
// }

// // readString reads a string from the standard input
// func readString() (read string) {
//     scanner.Scan()
//     read = scanner.Text()
//     return
// }

// // readStrings reads a slice of strings from the standard input
// func readStrings() (read []string) {
//     scanner.Scan()
//     for _, v := range scanner.Text() {
//         read = append(read, string(v))
//     }
//     return
// }

// // s2i converts a string to an integer
// func s2i(s string) int {
//     var intVal, e = strconv.Atoi(s)
//     if e != nil {
//         panic(e)
//     }
//     return intVal
// }

// // i2s converts an integer to a string
// func i2s(i int) string {
//     var strVal = strconv.Itoa(i)
//     return strVal
// }

// // s2f converts a string to a float
// func s2f(s string) float64 {
//     var floatVal, e = strconv.ParseFloat(s, 64)
//     if e != nil {
//         panic(e)
//     }
//     return floatVal
// }

// // sum calculates the sum of integers in a slice
// func sum(i []int) int {
//     sum := 0
//     for _, val := range i {
//         sum += val
//     }
//     return sum
// }

// // split splits a string into a slice of words
// func split(s string) []string {
//     return strings.Fields(s)
// }

// // strAry2intAry converts a slice of strings to a slice of integers
// func strAry2intAry(strs []string) []int {
//     var ret = make([]int, 0, len(strs))
//     for _, str := range strs {
//         var intVal, e = strconv.Atoi(string(str))
//         if e != nil {
//             panic(e)
//         }
//         ret = append(ret, intVal)
//     }
//     return ret
// }

// // intAry2strAry converts a slice of integers to a slice of strings
// func intAry2strAry(nums []int) []string {
//     var ret = make([]string, 0, len(nums))
//     for _, num := range nums {
//         var strVal = strconv.Itoa(num)
//         ret = append(ret, strVal)
//     }
//     return ret
// }

// // ary2str joins a slice of strings into a single string with spaces
// func ary2str(strs []string) string {
//     return strings.Join(strs, " ")
// }

// // reverse reverses a slice of integers
// func reverse(res []int) []int {
//     for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
//         res[i], res[j] = res[j], res[i]
//     }
//     return res
// }

// // initalize initializes a slice with a given value
// func initalize(res []int, init int) {
//     if len(res) == 0 {
//         return
//     }
//     res[0] = init
//     for i := 0; i < len(res); i++ {
//         copy(res[i:], res[:i])
//     }
// }

// // func regexpExample() {
// //     // Your code here!
// //     var str = "13:20"
// //     r := regexp.MustCompile(`(\d+):(\d+)`)
// //     fmt.Println(r.FindStringSubmatch(str))
// // }

// // type Country struct {
// //     gold int
// //     silver int
// //     blonze int
// // }

// // // 複数ソートのサンプル
// // func stableSortExample() []Country{
// //     var country = []Country {
// //         {gold:1, silver:2, blonze:3},
// //         {gold:1, silver:2, blonze:3},
// //         {gold:1, silver:3, blonze:2},
// //         {gold:1, silver:3, blonze:3},
// //     }
// //     sort.SliceStable(country, func(i, j int) bool { return country[i].blonze > country[j].blonze })
// //     sort.SliceStable(country, func(i, j int) bool { return country[i].silver > country[j].silver })
// //     sort.SliceStable(country, func(i, j int) bool { return country[i].gold > country[j].gold })
// //     return country
// // }

// 