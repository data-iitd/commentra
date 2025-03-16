// ABC 152-D
// 2020.1.19 bal4u

package main

import (
	"bufio"
	"fmt"
	"os"
)

func in() int { // 非負整数の入力
	var n int
	for {
		fmt.Scan(&n)
		if n >= 0 {
			break
		}
	}
	return n
}

func calc(n int) { // nを処理する関数
	k := n % 10 // nの最後の桁を取得
	for n >= 10 { // nが10の倍数である限りnを10で割る
		n /= 10
	}
	f1[10*k+n]++ // f1配列の[10*k+n]番目にカウントアップ
	f2[n*10+k]++ // f2配列の[n*10+k]番目にカウントアップ
}

var f1 [100]int
var f2 [100]int

func main() {
	var i, N, ans int

	N = in() // 入力数を入力する
	for N > 0 { // Nが0以外である限り
		calc(N) // calc関数を呼び出す
		N-- // Nを1減らす
	}

	ans = 0 // 答えを初期化
	for i = 0; i < 100; i++ { // f1, f2配列をループして答えを計算
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans) // 答えを出力
}

