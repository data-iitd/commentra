import sys

def main():
  # Initialize input reader with a buffer size of 1,000,000 bytes
  input = Input(sys.stdin.buffer, 1000000)
  
  # Read the number of elements and the array of integers from input
  n = input.NextInt()
  s = input.NextIntArray()
  
  # Create a boolean slice to track used indices
  u = [False] * n
  
  # Initialize variables to store the maximum sum and a temporary sum
  m, f = 0, 0
  
  # Iterate through possible values of c from 1 to n-2
  for c in range(1, n-1):
    f = 0 # Reset the temporary sum for each c
    
    # Iterate to find pairs of indices based on the current value of c
    for k in range(0, n-1-k*c):
      u[k*c] = True # Mark the current index as used
      
      # Break if the corresponding index is already used
      if u[n-1-k*c]: break
      
      # Calculate the sum of the elements at the current indices
      f += s[n-1-k*c] + s[k*c]
      
      # Update the maximum sum if the current sum is greater
      if m < f: m = f
    
    # Reset the used indices for the next iteration of c
    for k in range(0, n-1-k*c): u[k*c] = False
  print(m)

# Input struct to handle reading from standard input
class Input:
  def __init__(self, stream, bufsize):
    self.stream = stream
    self.bufsize = bufsize
    self.buffer = ''
    self.pos = 0

  def readline(self):
    while True:
      if self.pos == len(self.buffer):
        self.buffer = self.stream.read(self.bufsize)
        self.pos = 0
        if len(self.buffer) == 0:
          return ''
      eol = self.buffer.find('\n', self.pos)
      if eol!= -1:
        r = self.buffer[self.pos:eol+1]
        self.pos = eol+1
        return r
      self.pos = len(self.buffer)

  def NextLine(self):
    return self.readline()

  def NextInt(self):
    return int(self.readline())

  def NextIntArray(self):
    return [int(x) for x in self.readline().split()]

if __name__ == '__main__':
  main()

