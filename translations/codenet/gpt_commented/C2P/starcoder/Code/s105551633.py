# Define a type for 64-bit integers
int64 = long long int

# Macros for mathematical operations: MAX, MIN, and ABS
def MAX(a,b):
  return a if a>b else b
def MIN(a,b):
  return a if a<b else b
def ABS(a):
  return a if a>0 else -a

# Function to count the number of digits in a given integer
def digit(n):
  res=0
  while n>0:
    res+=1
    n/=10
  return res

# Function to execute the main logic of the program
def run():
  n=int(raw_input())
  min=digit(n)
  for i in range(1,int(n**0.5)+1):
    if n%i!=0: continue
    a=i
    b=n/i
    min=MIN(min,MAX(digit(a),digit(b)))
  print min

# Main function to start the program execution
if __name__=='__main__':
  run()

