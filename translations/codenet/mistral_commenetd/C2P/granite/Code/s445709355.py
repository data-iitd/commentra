
# ABC 152-D
# 2020.1.19 bal4u

import sys

def in(): # 非負 integers の入力
    n = 0
    for c in sys.stdin.buffer.read(): # getchar_unlocked()
        if c >= b'0' [0]: # c >= '0'
            n = 10 * n + (c & 0xf) # 数字の桁数を10倍して加算
    return n

f1 = [0] * 100
f2 = [0] * 100

def calc(n): # n を処理する関数
    k = n % 10 # n の最後の桁を取得
    while n >= 10: # n が10の倍数である限りnを10で割る
        n //= 10
    f1[10*k + n] += 1 # f1配列の[10*k+n]番目にカウントアップ
    f2[n*10 + k] += 1 # f2配列の[n*10+k]番目にカウントアップ

N = in() # 入力数を入力する
while N: # Nが0以外である限り
    calc(N) # calc関数を呼び出す
    N -= 1 # Nを1減らす

ans = 0 # 答えを初期化
for i in range(100): # f1, f2配列をループして答えを計算
    ans += f1[i] * f2[i]
print(ans) # 答えを出力
print("