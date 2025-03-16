#include <bits/stdc++.h>

using namespace std;

/********** FAU standard libraries **********/

//int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
//int dx8[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy8[] = {0, 1, 0, -1, 1, -1, 1, -1};
//int dx8b[] = {1, 1, 1, 0, -1, -1, -1, 0}, dy8b[] = {1, 0, -1, -1, -1, 0, 1, 1};
//int dx8c[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8c[] = {1, 1, 0, -1, -1, -1, 0, 1};

/********** I/O usage **********/

//str := ReadString();
//i := ReadInt();
//X := ReadIntSlice(n);
//S := ReadRuneSlice();
//a := ReadFloat64();
//A := ReadFloat64Slice(n);

//str := ZeroPaddingRuneSlice(num, 32);
//str := PrintIntsLine(X...);

/********** End of I/O usage **********/

/********** Input **********/

//func ReadString() string {
//	s, _ := reader.ReadString('\n')
//	for (s[len(s)-1] == '\n' || s[len(s)-1] =='') {
//		s = s[:len(s)-1]
//	}
//	return s
//}
//
//func ReadInt() int {
//	i, _ := strconv.Atoi(ReadString())
//	return i
//}
//
//func ReadIntSlice(n int) []int {
//	b := make([]int, n)
//	for i := 0; i < n; i++ {
//		b[i] = ReadInt()
//	}
//	return b
//}
//
//func ReadRuneSlice() []rune {
//	s := ReadString()
//	var r []rune
//	for _, c := range s {
//		r = append(r, c)
//	}
//	return r
//}
//
//func ReadFloat64() float64 {
//	f, _ := strconv.ParseFloat(ReadString(), 64)
//	return f
//}
//
//func ReadFloat64Slice(n int) []float64 {
//	b := make([]float64, n)
//	for i := 0; i < n; i++ {
//		b[i] = ReadFloat64()
//	}
//	return b
//}

/********** Output **********/

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintIntsLine returns integers string delimited by a space.
func PrintInts64Line(A...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) // 64bit int version
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// PrintfBufStdout is function for output strings to buffered os.Stdout
func PrintfBufStdout(format string, a...interface{}) {
	fmt.Fprintf(stdout, format, a...)
}

/********** Debugging **********/

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(x int, bitSize int) []rune {
	// convert to binary expression
	s := strconv.FormatInt(x, 2)

	// check bit size and format
	if bitSize == 0 {
		bitSize = len(s)

	}

	// add prefix 0
	for len(s) < bitSize {
		s = "0" + s
	}

	var r []rune
	for i, v := range s {
		r = append(r, v)

		// add zero padding
		if i+1 < bitSize {
			r = append(r, '0')
		}
	}

	return r
}

// Strtoi is a wrapper of strconv.Atoi().
// If an error occurs, all errors are ignored and 0 is returned.
func Strtoi(s string) int {
	if res, err := strconv.Atoi(s); err == nil {
		return res
	}
	return 0
}

// Strtoui is a wrapper of strconv.ParseUint().
// If an error occurs, all errors are ignored and 0 is returned.
func Strtoui(s string) uint {
	if res, err := strconv.ParseUint(s, 10, 64); err == nil {
		return uint(res)
	}
	return 0
}

// Strtof is a wrapper of strconv.ParseFloat().
// If an error occurs, all errors are ignored and 0.0 is returned.
func Strtof(s string) float64 {
	if res, err := strconv.ParseFloat(s, 64); err == nil {
		return res
	}
	return 0.0
}

// Strtod is a wrapper of strconv.ParseFloat().
// If an error occurs, all errors are ignored and 0.0 is returned.
func Strtod(s string) float64 {
	return Strtof(s)
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintInts64Line returns integers string delimited by a space.
func PrintInts64Line(A...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10)
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// PrintfBufStdout is function for output strings to buffered os.Stdout
func PrintfBufStdout(format string, a...interface{}) {
	fmt.Fprintf(stdout, format, a...)
}

// Inputf gets float from input, but it's faster.
func Inputf(s string) float64 {
	var f float64
	fmt.Fscanf(os.Stdin, s, &f)
	return f
}

// Inputf gets float from input, but it's faster.
func InputfScan(s string, ptr *float64) {
	fmt.Fscanf(os.Stdin, s, ptr)
}

// Inputf gets float from input, but it's faster.
func InputfBuf(s string, ptr *float64) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), s, ptr)
}

// Inputi gets integer from input, but it's faster.
func Inputi(s string) int {
	var i int
	fmt.Fscanf(os.Stdin, s, &i)
	return i
}

// InputiScan gets integer from input, but it's faster.
func InputiScan(s string, ptr *int) {
	fmt.Fscanf(os.Stdin, s, ptr)
}

// InputiBuf gets integer from input, but it's faster.
func InputiBuf(s string, ptr *int) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), s, ptr)
}

// InputIntSlice gets integer slice from input, but it's faster.
func InputIntSlice(W, H int) [][]int {
	w, h := W, H
	s := make([][]int, h)
	for i := 0; i < h; i++ {
		s[i] = make([]int, w)
		for j := 0; j < w; j++ {
			s[i][j] = Inputi(" ")
		}
	}
	return s
}

// InputInt64Slice gets integer slice from input, but it's faster.
func InputInt64Slice(W, H int) [][]int64 {
	w, h := W, H
	s := make([][]int64, h)
	for i := 0; i < h; i++ {
		s[i] = make([]int64, w)
		for j := 0; j < w; j++ {
			s[i][j] = Inputi64(" ")
		}
	}
	return s
}

// InputfSlice gets float slice from input, but it's faster.
func InputfSlice(W, H int) [][]float64 {
	w, h := W, H
	s := make([][]float64, h)
	for i := 0; i < h; i++ {
		s[i] = make([]float64, w)
		for j := 0; j < w; j++ {
			s[i][j] = Inputf(" ")
		}
	}
	return s
}

// InputfMatrix2D gets float 2D matrix from input, but it's faster.
func InputfMatrix2D(W, H int) [][]float64 {
	w, h := W, H
	s := make([][]float64, h)
	for i := 0; i < h; i++ {
		s[i] = make([]float64, w)
		for j := 0; j < w; j++ {
			fmt.Fscanf(os.Stdin, "%f ", &s[i][j])
		}
	}
	return s
}

// InputfMatrix3D gets float 3D matrix from input, but it's faster.
func InputfMatrix3D(D, W, H int) [][][]float64 {
	d, w, h := D, W, H
	s := make([][][]float64, d)
	for i := 0; i < d; i++ {
		s[i] = make([][]float64, h)
		for j := 0; j < h; j++ {
			s[i][j] = make([]float64, w)
			for k := 0; k < w; k++ {
				fmt.Fscanf(os.Stdin, "%f ", &s[i][j][k])
			}
		}
	}
	return s
}

// InputfMatrix4D gets float 4D matrix from input, but it's faster.
func InputfMatrix4D(E, D, W, H int) [][][][]float64 {
	e, d, w, h := E, D, W, H
	s := make([][][][]float64, e)
	for i := 0; i < e; i++ {
		s[i] = make([][][]float64, d)
		for j := 0; j < d; j++ {
			s[i][j] = make([][]float64, h)
			for k := 0; k < h; k++ {
				s[i][j][k] = make([]float64, w)
				for l := 0; l < w; l++ {
					fmt.Fscanf(os.Stdin, "%f ", &s[i][j][k][l])
				}
			}
		}
	}
	return s
}

// InputiMatrix2D gets integer 2D matrix from input, but it's faster.
func InputiMatrix2D(W, H int) [][]int {
	w, h := W, H
	s := make([][]int, h)
	for i := 0; i < h; i++ {
		s[i] = make([]int, w)
		for j := 0; j < w; j++ {
			fmt.Fscanf(os.Stdin, "%d ", &s[i][j])
		}
	}
	return s
}

// InputiMatrix3D gets integer 3D matrix from input, but it's faster.
func InputiMatrix3D(D, W, H int) [][][]int {
	d, w, h := D, W, H
	s := make([][][]int, d)
	for i := 0; i < d; i++ {
		s[i] = make([][]int, h)
		for j := 0; j < h; j++ {
			s[i][j] = make([]int, w)
			for k := 0; k < w; k++ {
				fmt.Fscanf(os.Stdin, "%d ", &s[i][j][k])
			}
		}
	}
	return s
}

// InputiMatrix4D gets integer 4D matrix from input, but it's faster.
func InputiMatrix4D(E, D, W, H int) [][][][]int {
	e, d, w, h := E, D, W, H
	s := make([][][][]int, e)
	for i := 0; i < e; i++ {
		s[i] = make([][][]int, d)
		for j := 0; j < d; j++ {
			s[i][j] = make([][]int, h)
			for k := 0; k < h; k++ {
				s[i][j][k] = make([]int, w)
				for l := 0; l < w; l++ {
					fmt.Fscanf(os.Stdin, "%d ", &s[i][j][k][l])
				}
			}
		}
	}
	return s
}

// InputRuneSlice gets rune slice from input, but it's faster.
func InputRuneSlice(W int) []rune {
	w := W
	s := make([]rune, w)
	for i := 0; i < w; i++ {
		s[i] = InputRune(" ")
	}
	return s
}

// InputRuneMatrix2D gets rune 2D matrix from input, but it's faster.
func InputRuneMatrix2D(W, H int) [][]rune {
	w, h := W, H
	s := make([][]rune, h)
	for i := 0; i < h; i++ {
		s[i] = make([]rune, w)
		for j := 0; j < w; j++ {
			s[i][j] = InputRune(" ")
		}
	}
	return s
}

// InputRuneMatrix3D gets rune 3D matrix from input, but it's faster.
func InputRuneMatrix3D(D, W, H int) [][][]rune {
	d, w, h := D, W, H
	s := make([][][]rune, d)
	for i := 0; i < d; i++ {
		s[i] = make([][]rune, h)
		for j := 0; j < h; j++ {
			s[i][j] = make([]rune, w)
			for k := 0; k < w; k++ {
				s[i][j][k] = InputRune(" ")
			}
		}
	}
	return s
}

// InputRuneMatrix4D gets rune 4D matrix from input, but it's faster.
func InputRuneMatrix4D(E, D, W, H int) [][][][]rune {
	e, d, w, h := E, D, W, H
	s := make([][][][]rune, e)
	for i := 0; i < e; i++ {
		s[i] = make([][][]rune, d)
		for j := 0; j < d; j++ {
			s[i][j] = make([][]rune, h)
			for k := 0; k < h; k++ {
				s[i][j][k] = make([]rune, w)
				for l := 0; l < w; l++ {
					s[i][j][k][l] = InputRune(" ")
