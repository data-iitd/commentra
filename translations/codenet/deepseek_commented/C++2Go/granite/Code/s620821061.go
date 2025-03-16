
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"sort"
)

const (
	EOF = -1
)

type Reader interface {
	Read() []byte
}

type ReaderFunc func() []byte

func (f ReaderFunc) Read() []byte {
	return f()
}

type ByteReader interface {
	ReadByte() byte
}

type ByteReaderFunc func() byte

func (f ByteReaderFunc) ReadByte() byte {
	return f()
}

type Tokenizer interface {
	Next()
	NextBytes() []byte
	NextString() string
	LookBytes() []byte
	LookString() string
}

type TokenizerFunc func()

func (f TokenizerFunc) Next() {
	f()
}

func (f TokenizerFunc) NextBytes() []byte {
	return nil
}

func (f TokenizerFunc) NextString() string {
	return ""
}

func (f TokenizerFunc) LookBytes() []byte {
	return nil
}

func (f TokenizerFunc) LookString() string {
	return ""
}

type TokenizerBytes struct {
	src []byte
	cur int
}

func (z *TokenizerBytes) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerBytes) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerBytes) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerBytes) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerBytes) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerBytes(r Reader) *TokenizerBytes {
	src, _ := r.Read(), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerBytes{src, 0}
}

type TokenizerString struct {
	src string
	cur int
}

func (z *TokenizerString) Next() {
	z.cur = strings.Index(z.src[z.cur:], " ")
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur += len(" ")
	}
}

func (z *TokenizerString) NextBytes() []byte {
	res := []byte(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerString) NextString() string {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerString) LookBytes() []byte {
	res := []byte(z.src[z.cur:z.cur])
	return res
}

func (z *TokenizerString) LookString() string {
	res := z.src[z.cur:z.cur]
	return res
}

func NewTokenizerString(r Reader) *TokenizerString {
	src, _ := r.Read(), ""
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerString{src, 0}
}

type TokenizerByteReader struct {
	src []byte
	cur int
}

func (z *TokenizerByteReader) Next() {
	for z.cur < len(z.src) && z.src[z.cur]!='' {
		z.cur++
	}
	if z.cur == len(z.src) {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReader) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReader) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReader) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReader) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReader(r ByteReader) *TokenizerByteReader {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReader{src, 0}
}

type TokenizerByteReaderFunc func()

func (f TokenizerByteReaderFunc) Next() {
	f()
}

func (f TokenizerByteReaderFunc) NextBytes() []byte {
	return nil
}

func (f TokenizerByteReaderFunc) NextString() string {
	return ""
}

func (f TokenizerByteReaderFunc) LookBytes() []byte {
	return nil
}

func (f TokenizerByteReaderFunc) LookString() string {
	return ""
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) LookBytes() []byte {
	res := z.src[z.cur:z.cur]
	return res
}

func (z *TokenizerByteReaderFunc) LookString() string {
	res := string(z.src[z.cur:z.cur])
	return res
}

func NewTokenizerByteReaderFunc(r ByteReader) *TokenizerByteReaderFunc {
	src, _ := r.ReadBytes(' '), []byte{}
	for len(src) > 0 && src[len(src)-1] == '\n' {
		src = src[:len(src)-1]
	}
	return &TokenizerByteReaderFunc{src, 0}
}

type TokenizerByteReaderFunc struct {
	cur int
}

func (z *TokenizerByteReaderFunc) Next() {
	z.cur = bytes.IndexByte(z.src[z.cur:],'')
	if z.cur == -1 {
		z.cur = len(z.src)
	} else {
		z.cur++
	}
}

func (z *TokenizerByteReaderFunc) NextBytes() []byte {
	res := z.src[z.cur:z.cur]
	z.Next()
	return res
}

func (z *TokenizerByteReaderFunc) NextString() string {
	res := string(z.src[z.cur:z.cur])
	z.Next()
	return res
}

func (z *Tokeni