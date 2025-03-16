
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func solve() bool {
	var maxsize int
	var maxcnt int
	var ans_num int
	var ans_num2 int
	var str_v []string

	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break
		}
		str_v = append(str_v, in)
		if maxsize < len(in) {
			maxsize = len(in)
			ans_num = len(str_v) - 1
		}
	}
	for i := 0; i < len(str_v); i++ {
		cnt := 0
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++
			}
		}
		if maxcnt < cnt {
			maxcnt = cnt
			ans_num2 = i
		}
	}

	fmt.Println(str_v[ans_num2], " ", str_v[ans_num])

	return true
}

func main() {
	fmt.Printf("%.10f", math.Pi)
	fmt.Println()
	fmt.Println(strings.ToUpper("Hello, World!"))
	fmt.Println(strings.ToLower("Hello, World!"))
	fmt.Println(strings.Trim("   Hello, World!  ", " "))
	fmt.Println(strings.TrimLeft("   Hello, World!  ", " "))
	fmt.Println(strings.TrimRight("   Hello, World!  ", " "))
	fmt.Println(strings.TrimPrefix("Hello, World!", "Hello"))
	fmt.Println(strings.TrimSuffix("Hello, World!", "World!"))
	fmt.Println(strings.Contains("Hello, World!", "World"))
	fmt.Println(strings.Count("Hello, World!", "l"))
	fmt.Println(strings.Replace("Hello, World!", "World", "Go", 1))
	fmt.Println(strings.Replace("Hello, World!", "World", "Go", -1))
	fmt.Println(strings.Split("Hello, World!", " "))
	fmt.Println(strings.Join([]string{"Hello", "World", "!"}, " "))
	fmt.Println(strings.Repeat("Hello", 3))
	fmt.Println(strings.Index("Hello, World!", "World"))
	fmt.Println(strings.LastIndex("Hello, World!", "World"))
	fmt.Println(strings.Fields("Hello, World!  "))
	fmt.Println(strings.ToValidUTF8("\xff\xfe\xff", "?"))
	fmt.Println(strings.NewReplacer("?", "!", "!", "?").Replace("Hello, World!"))
	fmt.Println(strings.Map(func(r rune) rune {
		if r == 'l' {
			return 'L'
		}
		return r
	}, "Hello, World!"))
	fmt.Println(strings.EqualFold("Hello", "hello"))
	fmt.Println(strings.Compare("Hello", "hello"))
	fmt.Println(strings.ContainsAny("Hello, World!", "HW"))
	fmt.Println(strings.ContainsRune("Hello, World!", 'W'))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(strings.NewReader("Hello, World!").Available())
	fmt.Println(strings.NewReader("Hello, World!").Buffered())
	fmt.Println(strings.NewReader("Hello, World!").Reset("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(strings.NewReader("Hello, World!").Available())
	fmt.Println(strings.NewReader("Hello, World!").Buffered())
	fmt.Println(strings.NewReader("Hello, World!").Reset("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(strings.NewReader("Hello, World!").Available())
	fmt.Println(strings.NewReader("Hello, World!").Buffered())
	fmt.Println(strings.NewReader("Hello, World!").Reset("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(strings.NewReader("Hello, World!").Available())
	fmt.Println(strings.NewReader("Hello, World!").Buffered())
	fmt.Println(strings.NewReader("Hello, World!").Reset("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(strings.NewReader("Hello, World!").Available())
	fmt.Println(strings.NewReader("Hello, World!").Buffered())
	fmt.Println(strings.NewReader("Hello, World!").Reset("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Read(make([]byte, 5)))
	fmt.Println(strings.NewReader("Hello, World!").ReadString('!'))
	fmt.Println(strings.NewReader("Hello, World!").ReadAt(make([]byte, 5), 7))
	fmt.Println(strings.NewReader("Hello, World!").ReadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadByte())
	fmt.Println(strings.NewReader("Hello, World!").UnreadRune())
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_SET))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_CUR))
	fmt.Println(strings.NewReader("Hello, World!").Seek(6, os.SEEK_END))
	fmt.Println(strings.NewReader("Hello, World!").WriteTo(os.Stdout))
	fmt.Println(strings.NewReader("Hello, World!").WriteString("Hello, World!"))
	fmt.Println(strings.NewReader("Hello, World!").Write([]byte("Hello, World!")))
	fmt.Println(strings.NewReader("Hello, World!").WriteAt([]byte("Hello, World!"), 0))
	fmt.Println(strings.NewReader("Hello, World!").WriteByte('!'))
	fmt.Println(strings.NewReader("Hello, World!").WriteRune('!'))
	fmt.Println(strings.NewReader("Hello, World!").Len())
	fmt.Println(strings.NewReader("Hello, World!").Size())
	fmt.Println(string