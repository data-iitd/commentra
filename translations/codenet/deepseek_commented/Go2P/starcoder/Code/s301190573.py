# The main package declaration.
# This package uses bufio and os for efficient I/O operations.

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

# The main function.
# This function uses bufio and os for efficient I/O operations.

def main():
  # Initializes a buffered reader with a specified size for efficient reading of standard input.
  reader = bufio.NewReaderSize(os.Stdin,1000000)
  # Reads the next line of input from the standard input.
  # It handles multi-line inputs by appending lines until isPrefix is false.
  def NextLine():
    var line,buffer []byte
    var isPrefix bool = True
    var err error
    for ;isPrefix; {
      line,isPrefix,err = reader.ReadLine()
      if err!= None:
        panic(err)
      buffer += line
    }
    return string(buffer)
  # Reads two integers from a single line of input, splits the line by spaces, and converts the split strings to integers.
  def NextInts():
    var x,y int
    var s []string = strings.Split(NextLine()," ")
    x,_ = strconv.Atoi(s[0])
    y,_ = strconv.Atoi(s[1])
    return x,y
  # Reads a line of space-separated integers, converts them to integers, and decrements each value by 1.
  n,m = NextInts()
  p = NextIntArray()
  x,y = 0,0
  initialize(n)
  for i in range(m):
    x,y = NextInts()
    unite(x-1,y-1)
  s = 0
  for i in range(n):
    if same(i,p[i]-1):
      s += 1
  fmt.Println(s)
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve future queries.
def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]
# Checks if the elements i and j are in the same set.
def same(i,j):
  return root(i) == root(j)
# Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.
def unite(i,j):
  i = root(i)
  j = root(j)
  if i == j:
    return
  if rank[i] < rank[j]:
    par[i] = j
  else:
    par[j] = i
    if rank[i] == rank[j]:
      rank[i] += 1
# The main function.
# This function uses bufio and os for efficient I/O operations.

if __name__ == "__main__":
  main()
# Initializes the union-find data structure with n elements, each in its own set.
def initialize(n):
  par = [i for i in range(n)]
  rank = [0 for i in range(n)]
# Finds the root of the element i, applying path compression to improve fut