package main

import (
 "bufio"
 "fmt"
 "os"
)

func main() {
 in := bufio.NewScanner(os.Stdin)
 in.Split(bufio.ScanWords)
 out := bufio.NewWriter(os.Stdout)
 defer out.Flush()

 in.Scan()
 n := parseInt(in.Text())
 ara := make([]int, n)
 freqMap := make(map[int]int)

 for i := 0; i < n; i++ {
 in.Scan()
 v := parseInt(in.Text())
 ara[i] = v
 if _, exists := freqMap[v]; !exists {
 freqMap[v] = 1
 } else {
 freqMap[v]++
 }
 }

 maxFreq := 0
 for _, freq := range freqMap {
 if freq > maxFreq {
 maxFreq = freq
 }
 }

 mm := make(map[int]int)
 for i := 0; i < n; i++ {
 if _, exists := mm[ara[i]]; !exists {
 mm[ara[i]] = 1
 if mm[ara[i]] == maxFreq {
 fmt.Fprintln(out, ara[i])
 break
 }
 } else {
 mm[ara[i]]++
 if mm[ara[i]] == maxFreq {
 fmt.Fprintln(out, ara[i])
 break
 }
 }
 }
}

func parseInt(s string) int {
 var res int
 for i := 0; i < len(s); i++ {
 res = res*10 + int(s[i]-'0')
 }
 return res
}

