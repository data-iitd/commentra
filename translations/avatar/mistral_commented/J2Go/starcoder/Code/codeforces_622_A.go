
package main

import (
"bufio"
"fmt"
"os"
"strconv"
"strings"
)

const BUFFER\_SIZE = 512000

func main() {
init()
solve()
closeIO()
}

func init() {
in.init(os.Stdin)
}

func closeIO() {
in.close()
}

func solve() {
position := in.nextLong()
solveHelper(position)
}

func solveHelper(position int64) {
nrstSeqStartIndx := int64(1)

// Binary search for the start index of the sequence containing the position
for getValueAtIndex(nrstSeqStartIndx*2) < position {
nrstSeqStartIndx *= 2
}

// Linear search for the end index of the sequence containing the position
for getValueAtIndex(nrstSeqStartIndx+1) <= position {
nrstSeqStartIndx++
}

// Print the answer
startIndex := getValueAtIndex(nrstSeqStartIndx)
fmt.Println(position - startIndex + 1)
}

func getValueAtIndex(index int64) int64 {
return 1 + (index-1)*(index/2)
}

type in struct {
reader *bufio.Reader
tokenizer *strings.Tokenizer
}

func (i *in) init(input io.Reader) {
i.reader = bufio.NewReader(input)
i.tokenizer = new(strings.Tokenizer)
}

func (i *in) close() {
i.reader.Close()
}

func (i *in) next() (string, error) {
if!i.tokenizer.Scan() {
return "", i.tokenizer.Err()
}
return i.tokenizer.Text(), nil
}

func (i *in) nextInt() (int, error) {
n, err := strconv.Atoi(i.next())
return n, err
}

func (i *in) nextLong() (int64, error) {
n, err := strconv.ParseInt(i.next(), 10, 64)
return n, err
}

func (i *in) nextDouble() (float64, error) {
n, err := strconv.ParseFloat(i.next(), 64)
return n, err
}

func (i *in) nextLine() (string, error) {
line, err := i.reader.ReadString('\n')
if err!= nil {
return "", err
}
return strings.TrimSpace(line), nil
}

func (i *in) nextString() (string, error) {
s, err := i.next()
return s, err
}

func (i *in) nextStrings(n int) ([]string, error) {
ss := make([]string, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = s
}
return ss, nil
}

func (i *in) nextInts(n int) ([]int, error) {
is := make([]int, n)
for j := 0; j < n; j++ {
s, err := i.nextInt()
if err!= nil {
return nil, err
}
is[j] = s
}
return is, nil
}

func (i *in) nextLongs(n int) ([]int64, error) {
ls := make([]int64, n)
for j := 0; j < n; j++ {
s, err := i.nextLong()
if err!= nil {
return nil, err
}
ls[j] = s
}
return ls, nil
}

func (i *in) nextDoubles(n int) ([]float64, error) {
fs := make([]float64, n)
for j := 0; j < n; j++ {
s, err := i.nextDouble()
if err!= nil {
return nil, err
}
fs[j] = s
}
return fs, nil
}

func (i *in) nextBool() (bool, error) {
s, err := i.next()
if err!= nil {
return false, err
}
return s == "true", nil
}

func (i *in) nextFloats(n int) ([]float32, error) {
fs := make([]float32, n)
for j := 0; j < n; j++ {
s, err := i.nextFloat()
if err!= nil {
return nil, err
}
fs[j] = s
}
return fs, nil
}

func (i *in) nextFloat() (float32, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseFloat(s, 32)
}

func (i *in) nextInt64() (int64, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseInt(s, 10, 64)
}

func (i *in) nextInt32() (int32, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseInt(s, 10, 32)
}

func (i *in) nextInt16() (int16, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseInt(s, 10, 16)
}

func (i *in) nextInt8() (int8, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseInt(s, 10, 8)
}

func (i *in) nextUint() (uint, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseUint(s, 10, 64)
}

func (i *in) nextUint64() (uint64, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseUint(s, 10, 64)
}

func (i *in) nextUint32() (uint32, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseUint(s, 10, 32)
}

func (i *in) nextUint16() (uint16, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseUint(s, 10, 16)
}

func (i *in) nextUint8() (uint8, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseUint(s, 10, 8)
}

func (i *in) nextRune() (rune, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return []rune(s)[0], nil
}

func (i *in) nextByte() (byte, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return []byte(s)[0], nil
}

func (i *in) nextBytes(n int) ([]byte, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return []byte(s)[:n], nil
}

func (i *in) nextTime() (time.Time, error) {
s, err := i.next()
if err!= nil {
return time.Time{}, err
}
return time.Parse(time.RFC3339, s)
}

func (i *in) nextDuration() (time.Duration, error) {
s, err := i.next()
if err!= nil {
return time.Duration(0), err
}
return time.ParseDuration(s)
}

func (i *in) nextComplex64() (complex64, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseComplex(s, 64)
}

func (i *in) nextComplex128() (complex128, error) {
s, err := i.next()
if err!= nil {
return 0, err
}
return strconv.ParseComplex(s, 128)
}

func (i *in) nextAny() (interface{}, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return s, nil
}

func (i *in) nextIntsLine() ([]int, error) {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextFloatsLine() ([]float64, error) {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextStringsLine() ([]string, error) {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextIntsLines(n int) ([][]int, error) {
ss := make([][]int, n)
for j := 0; j < n; j++ {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextFloatsLines(n int) ([][]float64, error) {
ss := make([][]float64, n)
for j := 0; j < n; j++ {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextStringsLines(n int) ([][]string, error) {
ss := make([][]string, n)
for j := 0; j < n; j++ {
s, err := i.nextLine()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextIntsLineSlice() ([]int, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextFloatsLineSlice() ([]float64, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextStringsLineSlice() ([]string, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextIntsLinesSlice(n int) ([][]int, error) {
ss := make([][]int, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextFloatsLinesSlice(n int) ([][]float64, error) {
ss := make([][]float64, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextStringsLinesSlice(n int) ([][]string, error) {
ss := make([][]string, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextIntsLineSlice() ([]int, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextFloatsLineSlice() ([]float64, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextStringsLineSlice() ([]string, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextIntsLinesSlice(n int) ([][]int, error) {
ss := make([][]int, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextFloatsLinesSlice(n int) ([][]float64, error) {
ss := make([][]float64, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextStringsLinesSlice(n int) ([][]string, error) {
ss := make([][]string, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextIntsLineSlice() ([]int, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextFloatsLineSlice() ([]float64, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextStringsLineSlice() ([]string, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextIntsLinesSlice(n int) ([][]int, error) {
ss := make([][]int, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextFloatsLinesSlice(n int) ([][]float64, error) {
ss := make([][]float64, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextStringsLinesSlice(n int) ([][]string, error) {
ss := make([][]string, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, " ")
}
return ss, nil
}

func (i *in) nextIntsLineSlice() ([]int, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextFloatsLineSlice() ([]float64, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextStringsLineSlice() ([]string, error) {
s, err := i.next()
if err!= nil {
return nil, err
}
return strings.Split(s, " "), nil
}

func (i *in) nextIntsLinesSlice(n int) ([][]int, error) {
ss := make([][]int, n)
for j := 0; j < n; j++ {
s, err := i.next()
if err!= nil {
return nil, err
}
ss[j] = strings.Split(s, 