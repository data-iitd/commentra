#######
// Package main
// File   : main.go
// Author : <NAME>
// Date   : 2021-09-13
//
// For more information, see:
// https://www.codewars.com/kata/5890000000396b0001000000
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

package main

import (
	"fmt"
	"strings"
)

// CodeforcesTask397BSolution is the solution for Codeforces Task 397B
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
type CodeforcesTask397BSolution struct {
	result string
	t      int
	queries [][]int
}

// NewCodeforcesTask397BSolution is the constructor for CodeforcesTask397BSolution
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
func NewCodeforcesTask397BSolution() CodeforcesTask397BSolution {
	return CodeforcesTask397BSolution{
		result: "",
		t:      0,
		queries: [][]int{},
	}
}

// ReadInput reads the input for CodeforcesTask397BSolution
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
func (s *CodeforcesTask397BSolution) ReadInput() {
	s.t = readInt()
	s.queries = make([][]int, s.t)
	for i := 0; i < s.t; i++ {
		s.queries[i] = make([]int, 3)
		s.queries[i][0] = readInt()
		s.queries[i][1] = readInt()
		s.queries[i][2] = readInt()
	}
}

// ProcessTask processes the task for CodeforcesTask397BSolution
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
func (s *CodeforcesTask397BSolution) ProcessTask() {
	res := make([]string, s.t)
	for i, query := range s.queries {
		k := query[0] / query[1]
		res[i] = "Yes"
		if k*query[2] < query[0] {
			res[i] = "No"
		}
	}
	s.result = strings.Join(res, "\n")
}

// GetResult returns the result for CodeforcesTask397BSolution
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
func (s *CodeforcesTask397BSolution) GetResult() string {
	return s.result
}

// readInt reads an integer from the input
//
// Copyright © 2021 <NAME>. All rights reserved.
//
// See the README.md for license information.
//
// https://www.codewars.com/kata/5890000000396b0001000000
//
func readInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// END-OF-CODE
#######

'''
