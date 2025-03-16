def main():
    S = input()

    # 後ろから解くかわりにすべての文字列を「左右反転」する
    S = S[::-1]
    divide = ["dream", "dreamer", "erase", "eraser"]
    for i in range(4):
        divide[i] = divide[i][::-1]

    # 端から切っていく
    can = True
    i = 0
    while i < len(S):
        can2 = False  # 4 個の文字列たちどれかで divide できるか
        for d in divide:
            if S[i:i+len(d)] == d:  # d で divide できるか
                can2 = True
                i += len(d)  # divide できたら i を進める
        if not can2:  # divide できなかったら
            can = False
            break

    if can:
        print("YES")
    else:
        print("NO")

main()
