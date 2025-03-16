<<<<<<< HEAD

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
=======
package main

import (
    "fmt"
    "os"
    "strconv"
>>>>>>> 98c87cb78a (data updated)
)

func main() {
    var i int = 1
    var Input int
<<<<<<< HEAD
    var InputString string
    var InputStringSlice []string
    var InputStringScanner *bufio.Scanner
    var InputStringReader *bufio.Reader
    var InputStringSplit []string
    var InputStringSplitLen int
    var InputStringSplitIndex int
    var InputStringSplitElement string
    var InputStringSplitElementInt int
    var InputStringSplitElementInt64 int64
    var InputStringSplitElementInt64Err error
    var InputStringSplitElementFloat64 float64
    var InputStringSplitElementFloat64Err error
    var InputStringSplitElementBool bool
    var InputStringSplitElementBoolErr error
    var InputStringSplitElementString string
    var InputStringSplitElementStringErr error
    var InputStringSplitElementStringSlice []string
    var InputStringSplitElementStringSliceErr error
    var InputStringSplitElementStringSliceLen int
    var InputStringSplitElementStringSliceIndex int
    var InputStringSplitElementStringSliceElement string
    var InputStringSplitElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementFloat64 float64
    var InputStringSplitElementStringSliceElementFloat64Err error
    var InputStringSplitElementStringSliceElementBool bool
    var InputStringSplitElementStringSliceElementBoolErr error
    var InputStringSplitElementStringSliceElementString string
    var InputStringSplitElementStringSliceElementStringErr error
    var InputStringSplitElementStringSliceElementStringSlice []string
    var InputStringSplitElementStringSliceElementStringSliceErr error
    var InputStringSplitElementStringSliceElementStringSliceLen int
    var InputStringSplitElementStringSliceElementStringSliceIndex int
    var InputStringSplitElementStringSliceElementStringSliceElement string
    var InputStringSplitElementStringSliceElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementFloat64 float64
    var InputStringSplitElementStringSliceElementStringSliceElementFloat64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementBool bool
    var InputStringSplitElementStringSliceElementStringSliceElementBoolErr error
    var InputStringSplitElementStringSliceElementStringSliceElementString string
    var InputStringSplitElementStringSliceElementStringSliceElementStringErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSlice []string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceLen int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceIndex int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElement string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementFloat64 float64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementFloat64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementBool bool
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementBoolErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementString string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSlice []string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceLen int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceIndex int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElement string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementFloat64 float64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementFloat64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementBool bool
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementBoolErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementString string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSlice []string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceLen int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceIndex int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElement string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementFloat64 float64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementFloat64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementBool bool
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementBoolErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementString string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSlice []string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceLen int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceIndex int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElement string
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt int
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementIntErr error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64 int64
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementStringSliceElementInt64Err error
    var InputStringSplitElementStringSliceElementStringSliceElementStringSliceElementStringSliceEleme
=======
    for {
        _, err := fmt.Scanf("%d", &Input)
        if err!= nil {
            break
        }
        if Input == 0 {
            break
        }
        fmt.Printf("Case %d: %d\n", i, Input)
        i++
    }
}

>>>>>>> 98c87cb78a (data updated)
