

package main

import (
 "bufio"
 "fmt"
 "io"
 "os"
 "strconv"
 "strings"
)

const BUFFER_SIZE = 512000

var (
 in  = bufio.NewReaderSize(os.Stdin, BUFFER_SIZE)
 out = bufio.NewWriterSize(os.Stdout, BUFFER_SIZE)
)

func main() {
 position, _ := strconv.ParseInt(read(), 10, 64)
 solve(position)
 out.Flush()
}

func solve(position int64) {
 seqStartIndx := int64(1)
 for getValueAtIndex(seqStartIndx * 2) < position {
 seqStartIndx *= 2
 }
 for getValueAtIndex(seqStartIndx+1) <= position {
 seqStartIndx++
 }
 startIndex := getValueAtIndex(seqStartIndx)
 fmt.Println(position - startIndex + 1)
}

func getValueAtIndex(index int64) int64 {
 return 1 + (index-1)*index/2
}

func read() string {
 scanner := bufio.NewScanner(in)
 scanner.Scan()
 return scanner.Text()
}

func readInt() int {
 result, _ := strconv.Atoi(read())
 return result
}

func readNInt(n int) []int {
 result := make([]int, n)
 for i := 0; i < n; i++ {
 result[i] = readInt()
 }
 return result
}

func readLong() int64 {
 result, _ := strconv.ParseInt(read(), 10, 64)
 return result
}

func readNLong(n int) []int64 {
 result := make([]int64, n)
 for i := 0; i < n; i++ {
 result[i] = readLong()
 }
 return result
}

func readFloat() float64 {
 result, _ := strconv.ParseFloat(read(), 64)
 return result
}

func readNFloat(n int) []float64 {
 result := make([]float64, n)
 for i := 0; i < n; i++ {
 result[i] = readFloat()
 }
 return result
}

func readLine() string {
 scanner := bufio.NewScanner(in)
 if scanner.Scan() {
 return scanner.Text()
 }
 return ""
}

func readNLine(n int) []string {
 result := make([]string, n)
 for i := 0; i < n; i++ {
 result[i] = readLine()
 }
 return result
}

func out(str string) {
 fmt.Fprint(out, str)
}

func outf(str string, args...interface{}) {
 fmt.Fprintf(out, str, args...)
}

func outn() {
 fmt.Fprint(out, "\n")
}

func outs(str string) {
 fmt.Fprint(out, str, " ")
}

func outsn(str string) {
 fmt.Fprint(out, str, "\n")
}

func outsfl(str string, args...interface{}) {
 fmt.Fprintf(out, str, args...)
 outn()
}

func outsfn(str string, args...interface{}) {
 fmt.Fprintf(out, str, args...)
 out()
}

func debug(args...interface{}) {
 fmt.Fprintln(os.Stderr, args...)
}

func debugn(args...interface{}) {
 fmt.Fprint(os.Stderr, args...)
}

func debugs(args...interface{}) {
 fmt.Fprint(os.Stderr, args..., " ")
}

func debugsn(args...interface{}) {
 fmt.Fprintln(os.Stderr, args...)
}

func debugsfl(args...interface{}) {
 fmt.Fprint(os.Stderr, args..., " ")
}

func debugsfn(args...interface{}) {
 fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
 fmt.Fprintf(os.Stderr, format, args...)
}

func debugfn(format string, args...interface{}) {
 fmt.Fprintf(os.Stderr, format, args...)
 os.Exit(0)
}

func debuga(a interface{}) {
 debug(a)
 outn()
}

func debugaf(format string, a interface{}) {
 debugf(format, a)
 outn()
}

func debugal(a...interface{}) {
 debug(a...)
 outn()
}

func debugal2d(a...[]interface{}) {
 for _, v := range a {
 debug(v...)
 outn()
 }
}

func debugal3d(a...[][]interface{}) {
 for _, v := range a {
 debugal2d(v...)
 }
}

func debugal4d(a...[][][]interface{}) {
 for _, v := range a {
 debugal3d(v...)
 }
}

func debugal5d(a...[][][][]interface{}) {
 for _, v := range a {
 debugal4d(v...)
 }
}

func debugal6d(a...[][][][][]interface{}) {
 for _, v := range a {
 debugal5d(v...)
 }
}

func debugal7d(a...[][][][][][]interface{}) {
 for _, v := range a {
 debugal6d(v...)
 }
}

func debugal8d(a...[][][][][][][]interface{}) {
 for _, v := range a {
 debugal7d(v...)
 }
}

func debugal9d(a...[][][][][][][][]interface{}) {
 for _, v := range a {
 debugal8d(v...)
 }
}

func debugal10d(a...[][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal9d(v...)
 }
}

func debugal11d(a...[][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal10d(v...)
 }
}

func debugal12d(a...[][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal11d(v...)
 }
}

func debugal13d(a...[][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal12d(v...)
 }
}

func debugal14d(a...[][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal13d(v...)
 }
}

func debugal15d(a...[][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal14d(v...)
 }
}

func debugal16d(a...[][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal15d(v...)
 }
}

func debugal17d(a...[][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal16d(v...)
 }
}

func debugal18d(a...[][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal17d(v...)
 }
}

func debugal19d(a...[][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal18d(v...)
 }
}

func debugal20d(a...[][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal19d(v...)
 }
}

func debugal21d(a...[][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal20d(v...)
 }
}

func debugal22d(a...[][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal21d(v...)
 }
}

func debugal23d(a...[][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal22d(v...)
 }
}

func debugal24d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal23d(v...)
 }
}

func debugal25d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal24d(v...)
 }
}

func debugal26d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal25d(v...)
 }
}

func debugal27d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal26d(v...)
 }
}

func debugal28d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal27d(v...)
 }
}

func debugal29d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal28d(v...)
 }
}

func debugal30d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal29d(v...)
 }
}

func debugal31d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal30d(v...)
 }
}

func debugal32d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal31d(v...)
 }
}

func debugal33d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal32d(v...)
 }
}

func debugal34d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal33d(v...)
 }
}

func debugal35d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal34d(v...)
 }
}

func debugal36d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal35d(v...)
 }
}

func debugal37d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal36d(v...)
 }
}

func debugal38d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal37d(v...)
 }
}

func debugal39d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal38d(v...)
 }
}

func debugal40d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal39d(v...)
 }
}

func debugal41d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal40d(v...)
 }
}

func debugal42d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal41d(v...)
 }
}

func debugal43d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal42d(v...)
 }
}

func debugal44d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal43d(v...)
 }
}

func debugal45d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal44d(v...)
 }
}

func debugal46d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal45d(v...)
 }
}

func debugal47d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal46d(v...)
 }
}

func debugal48d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]interface{}) {
 for _, v := range a {
 debugal47d(v...)
 }
}

func debugal49d(a...[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]