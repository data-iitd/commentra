
import sys

def new_data():
    n, m = map(int, sys.stdin.readline().split())
    n_img = load(n)
    m_img = load(m)

    return n, m, n_img, m_img

def load(cnt):
    ret = []
    for i in range(cnt):
        ret.append(sys.stdin.readline().strip())

    return ret

def exist(n, m, n_img, m_img):
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            if match(i, j, n, m, n_img, m_img):
                return True

    return False

def match(x, y, n, m, n_img, m_img):
    for i in range(m):
        for j in range(m):
            if n_img[x + i][y + j] != m_img[i][j]:
                return False

    return True

if __name__ == "__main__":
    n, m, n_img, m_img = new_data()
    if exist(n, m, n_img, m_img):
        print("Yes")
    else:
        print("No")

