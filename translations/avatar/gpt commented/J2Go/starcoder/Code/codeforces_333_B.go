package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader for efficient input reading
type FastReader struct {
	r *bufio.Reader
	buf []byte
	i int
	j int
}

func (f *FastReader) Init() {
	f.r = bufio.NewReader(os.Stdin)
	f.buf = make([]byte, 0)
	f.i = 0
	f.j = 0
}

func (f *FastReader) ReadLine() (string, error) {
	var (
		isPrefix bool = true
		err      error = nil
	)
	for isPrefix && err == nil {
		var tmp []byte
		tmp, isPrefix, err = f.r.ReadLine()
		f.buf = append(f.buf, tmp...)
	}
	if err!= nil {
		return "", err
	}
	var ret string = string(f.buf[f.i:f.j])
	f.i = f.j
	f.j = len(f.buf)
	return ret, nil
}

func (f *FastReader) ReadInt() (int, error) {
	var ret int
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret, err = strconv.Atoi(string(bs))
	if err!= nil {
		return ret, err
	}
	return ret, nil
}

func (f *FastReader) ReadLong() (int64, error) {
	var ret int64
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret, err = strconv.ParseInt(string(bs), 10, 64)
	if err!= nil {
		return ret, err
	}
	return ret, nil
}

func (f *FastReader) ReadFloat() (float64, error) {
	var ret float64
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret, err = strconv.ParseFloat(string(bs), 64)
	if err!= nil {
		return ret, err
	}
	return ret, nil
}

func (f *FastReader) ReadString() (string, error) {
	var ret string
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = string(bs)
	return ret, nil
}

func (f *FastReader) ReadBytes() ([]byte, error) {
	var ret []byte
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = []byte(bs)
	return ret, nil
}

func (f *FastReader) ReadRune() (rune, int, error) {
	var ret rune
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, 0, err
	}
	ret = []rune(bs)[0]
	return ret, 1, nil
}

func (f *FastReader) UnreadRune() error {
	if f.i <= 0 {
		return fmt.Errorf("UnreadRune: at beginning of buffer")
	}
	f.i -= 1
	return nil
}

func (f *FastReader) UnreadBytes(bs []byte) error {
	if f.i <= 0 {
		return fmt.Errorf("UnreadBytes: at beginning of buffer")
	}
	f.i -= len(bs)
	return nil
}

func (f *FastReader) Read(p []byte) (int, error) {
	var ret int
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = copy(p, bs)
	return ret, nil
}

func (f *FastReader) ReadAll() ([]byte, error) {
	var ret []byte
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = []byte(bs)
	return ret, nil
}

func (f *FastReader) ReadWord() (string, error) {
	var ret string
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = strings.Split(string(bs), " ")[0]
	return ret, nil
}

func (f *FastReader) ReadWords() ([]string, error) {
	var ret []string
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	ret = strings.Split(string(bs), " ")
	return ret, nil
}

func (f *FastReader) ReadLines() ([][]byte, error) {
	var ret [][]byte
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	ret = bytes.Split(bs, []byte("\n"))
	return ret, nil
}

func (f *FastReader) ReadFloats() ([]float64, error) {
	var ret []float64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, float64(v))
	}
	return ret, nil
}

func (f *FastReader) ReadInts() ([]int, error) {
	var ret []int
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, int(v))
	}
	return ret, nil
}

func (f *FastReader) ReadLongs() ([]int64, error) {
	var ret []int64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, int64(v))
	}
	return ret, nil
}

func (f *FastReader) ReadStrings() ([]string, error) {
	var ret []string
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, string(v))
	}
	return ret, nil
}

func (f *FastReader) ReadBool() (bool, error) {
	var ret bool
	var bs []byte
	bs, err := f.ReadLine()
	if err!= nil {
		return ret, err
	}
	if string(bs) == "true" {
		ret = true
	} else if string(bs) == "false" {
		ret = false
	} else {
		return ret, fmt.Errorf("ReadBool: invalid input")
	}
	return ret, nil
}

func (f *FastReader) ReadFloatSlice() ([]float64, error) {
	var ret []float64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, float64(v))
	}
	return ret, nil
}

func (f *FastReader) ReadIntSlice() ([]int, error) {
	var ret []int
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, int(v))
	}
	return ret, nil
}

func (f *FastReader) ReadLongSlice() ([]int64, error) {
	var ret []int64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, int64(v))
	}
	return ret, nil
}

func (f *FastReader) ReadStringSlice() ([]string, error) {
	var ret []string
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		ret = append(ret, string(v))
	}
	return ret, nil
}

func (f *FastReader) ReadBoolSlice() ([]bool, error) {
	var ret []bool
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), " ")
	for _, v := range tmp {
		if string(v) == "true" {
			ret = append(ret, true)
		} else if string(v) == "false" {
			ret = append(ret, false)
		} else {
			return ret, fmt.Errorf("ReadBoolSlice: invalid input")
		}
	}
	return ret, nil
}

func (f *FastReader) ReadFloat2D() ([][]float64, error) {
	var ret [][]float64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 []float64
		tmp2 = append(tmp2, float64(v))
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadInt2D() ([][]int, error) {
	var ret [][]int
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 []int
		tmp2 = append(tmp2, int(v))
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadLong2D() ([][]int64, error) {
	var ret [][]int64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 []int64
		tmp2 = append(tmp2, int64(v))
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadString2D() ([][]string, error) {
	var ret [][]string
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 []string
		tmp2 = append(tmp2, string(v))
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadBool2D() ([][]bool, error) {
	var ret [][]bool
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 []bool
		if string(v) == "true" {
			tmp2 = append(tmp2, true)
		} else if string(v) == "false" {
			tmp2 = append(tmp2, false)
		} else {
			return ret, fmt.Errorf("ReadBool2D: invalid input")
		}
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadFloat3D() ([][][]float64, error) {
	var ret [][][]float64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 [][]float64
		var tmp3 []float64
		tmp3 = append(tmp3, float64(v))
		tmp2 = append(tmp2, tmp3)
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadInt3D() ([][][]int, error) {
	var ret [][][]int
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 [][]int
		var tmp3 []int
		tmp3 = append(tmp3, int(v))
		tmp2 = append(tmp2, tmp3)
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadLong3D() ([][][]int64, error) {
	var ret [][][]int64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 [][]int64
		var tmp3 []int64
		tmp3 = append(tmp3, int64(v))
		tmp2 = append(tmp2, tmp3)
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadString3D() ([][][]string, error) {
	var ret [][][]string
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 [][]string
		var tmp3 []string
		tmp3 = append(tmp3, string(v))
		tmp2 = append(tmp2, tmp3)
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadBool3D() ([][][]bool, error) {
	var ret [][][]bool
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "\n")
	for _, v := range tmp {
		var tmp2 [][]bool
		var tmp3 []bool
		if string(v) == "true" {
			tmp3 = append(tmp3, true)
		} else if string(v) == "false" {
			tmp3 = append(tmp3, false)
		} else {
			return ret, fmt.Errorf("ReadBool3D: invalid input")
		}
		tmp2 = append(tmp2, tmp3)
		ret = append(ret, tmp2)
	}
	return ret, nil
}

func (f *FastReader) ReadFloat4D() ([][][][]float64, error) {
	var ret [][][][]float64
	var bs []byte
	bs, err := f.ReadAll()
	if err!= nil {
		return ret, err
	}
	tmp := strings.Split(string(bs), "