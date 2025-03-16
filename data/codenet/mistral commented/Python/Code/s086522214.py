# Define a function to calculate the prime decomposition of a given integer
def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(int(i))
    i += 1
  if n > 1:
    table.append(int(n))
  return table   

# Define a function to calculate the digit list of a given integer
def digit(i):
    if i > 0:
        return digit(i//10) + [i%10]
    else:
        return []

# Function to get the index of the nearest value in a list to a given number
def getNearestValueIndex(list, num):
    """
    概要: リストからある値に最も近い値のインデックスを取得する関数
    @param list: データ配列
    @param num: 対象値
    @return 対象値に最も近い値
    """

    # リスト要素と対象値の差分を計算し最小値のインデックスを取得
    idx = np.abs(np.asarray(list) - num).argmin()
    return idx

# Read input values N and X
N, X = map(int, input().split())

# Read N integers x[i]
x = [0]*N
x[:] = map(int, input().split())

# Read N pairs of integers P[i] and Y[i]
P = [0]*N
Y = [0]*N
for n in range(N):
    P[n], Y[n] = map(int, input().split())

# Calculate prime decomposition of each x[i]
decomposition = [prime_decomposition(i) for i in x]

# Calculate digit list of each P[i]
digits_P = [digit(i) for i in P]

# Calculate index of the nearest value in digits_P to '753'
index = getNearestValueIndex(digits_P, ['7', '5', '3'])

# Print the index
print(index)
