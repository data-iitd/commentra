
import sys

# Reading the first integer from the standard input and assigning it to the variable N
N = int ( sys.stdin.readline ( ).strip ( ) )

# Reading the second integer from the standard input and assigning it to the variable K
K = int ( sys.stdin.readline ( ).strip ( ) )

# Reading a string from the standard input and assigning it to the variable S
S = sys.stdin.readline ( ).strip ( )

# Initializing a boolean flag1 to false
flag1 = False

# Initializing an integer counter count1 to zero
count1 = 0

# The first for loop is used to process the character array c1
for i in range ( N ) :
  if flag1 and S [ i ] == 'R' : # If flag1 is true and the current character in c1 is 'R'
    flag1 = False # Setting flag1 to false
    count1 += 1 # Incrementing the counter count1
  if count1 == K : # If the counter count1 has reached the value K
    break # Exiting the for loop
  if S [ i ] == 'L' : # If the current character in c1 is 'L'
    flag1 = True # Setting flag1 to true

# Initializing a boolean flag3 to false
flag3 = False

# Initializing an integer counter count3 to zero
count3 = 0

# The second for loop is used to process the character array c3
for i in range ( N ) :
  if flag3 and S [ i ] == 'L' : # If flag3 is true and the current character in c3 is 'L'
    flag3 = False # Setting flag3 to false
    count3 += 1 # Incrementing the counter count3
  if count3 == K : # If the counter count3 has reached the value K
    break # Exiting the for loop
  if S [ i ] == 'R' : # If the current character in c3 is 'R'
    flag3 = True # Setting flag3 to true

# Creating a new String object S1 from the character array c1
S1 = ''.join ( S )

# Creating a new String object S3 from the character array c3
S3 = ''.join ( S )

# Initializing an integer counter count2 to one
count2 = 1

# Initializing an integer variable sum1 to zero
sum1 = 0

# Initializing an integer variable sum3 to zero
sum3 = 0

# Initializing an integer variable sum2 to zero
sum2 = 0

# Initializing an integer variable sum4 to zero
sum4 = 0

# Initializing an integer variable sum5 to zero
sum5 = 0

# Initializing an integer variable sum6 to zero
sum6 = 0

# Initializing an integer variable sum7 to zero
sum7 = 0

# Initializing an integer variable sum8 to zero
sum8 = 0

# Initializing an integer variable sum9 to zero
sum9 = 0

# Initializing an integer variable sum10 to zero
sum10 = 0

# Initializing an integer variable sum11 to zero
sum11 = 0

# Initializing an integer variable sum12 to zero
sum12 = 0

# Initializing an integer variable sum13 to zero
sum13 = 0

# Initializing an integer variable sum14 to zero
sum14 = 0

# Initializing an integer variable sum15 to zero
sum15 = 0

# Initializing an integer variable sum16 to zero
sum16 = 0

# Initializing an integer variable sum17 to zero
sum17 = 0

# Initializing an integer variable sum18 to zero
sum18 = 0

# Initializing an integer variable sum19 to zero
sum19 = 0

# Initializing an integer variable sum20 to zero
sum20 = 0

# Initializing an integer variable sum21 to zero
sum21 = 0

# Initializing an integer variable sum22 to zero
sum22 = 0

# Initializing an integer variable sum23 to zero
sum23 = 0

# Initializing an integer variable sum24 to zero
sum24 = 0

# Initializing an integer variable sum25 to zero
sum25 = 0

# Initializing an integer variable sum26 to zero
sum26 = 0

# Initializing an integer variable sum27 to zero
sum27 = 0

# Initializing an integer variable sum28 to zero
sum28 = 0

# Initializing an integer variable sum29 to zero
sum29 = 0

# Initializing an integer variable sum30 to zero
sum30 = 0

# Initializing an integer variable sum31 to zero
sum31 = 0

# Initializing an integer variable sum32 to zero
sum32 = 0

# Initializing an integer variable sum33 to zero
sum33 = 0

# Initializing an integer variable sum34 to zero
sum34 = 0

# Initializing an integer variable sum35 to zero
sum35 = 0

# Initializing an integer variable sum36 to zero
sum36 = 0

# Initializing an integer variable sum37 to zero
sum37 = 0

# Initializing an integer variable sum38 to zero
sum38 = 0

# Initializing an integer variable sum39 to zero
sum39 = 0

# Initializing an integer variable sum40 to zero
sum40 = 0

# Initializing an integer variable sum41 to zero
sum41 = 0

# Initializing an integer variable sum42 to zero
sum42 = 0

# Initializing an integer variable sum43 to zero
sum43 = 0

# Initializing an integer variable sum44 to zero
sum44 = 0

# Initializing an integer variable sum45 to zero
sum45 = 0

# Initializing an integer variable sum46 to zero
sum46 = 0

# Initializing an integer variable sum47 to zero
sum47 = 0

# Initializing an integer variable sum48 to zero
sum48 = 0

# Initializing an integer variable sum49 to zero
sum49 = 0

# Initializing an integer variable sum50 to zero
sum50 = 0

# Initializing an integer variable sum51 to zero
sum51 = 0

# Initializing an integer variable sum52 to zero
sum52 = 0

# Initializing an integer variable sum53 to zero
sum53 = 0

# Initializing an integer variable sum54 to zero
sum54 = 0

# Initializing an integer variable sum55 to zero
sum55 = 0

# Initializing an integer variable sum56 to zero
sum56 = 0

# Initializing an integer variable sum57 to zero
sum57 = 0

# Initializing an integer variable sum58 to zero
sum58 = 0

# Initializing an integer variable sum59 to zero
sum59 = 0

# Initializing an integer variable sum60 to zero
sum60 = 0

# Initializing an integer variable sum61 to zero
sum61 = 0

# Initializing an integer variable sum62 to zero
sum62 = 0

# Initializing an integer variable sum63 to zero
sum63 = 0

# Initializing an integer variable sum64 to zero
sum64 = 0

# Initializing an integer variable sum65 to zero
sum65 = 0

# Initializing an integer variable sum66 to zero
sum66 = 0

# Initializing an integer variable sum67 to zero
sum67 = 0

# Initializing an integer variable sum68 to zero
sum68 = 0

# Initializing an integer variable sum69 to zero
sum69 = 0

# Initializing an integer variable sum70 to zero
sum70 = 0

# Initializing an integer variable sum71 to zero
sum71 = 0

# Initializing an integer variable sum72 to zero
sum72 = 0

# Initializing an integer variable sum73 to zero
sum73 = 0

# Initializing an integer variable sum74 to zero
sum74 = 0

# Initializing an integer variable sum75 to zero
sum75 = 0

# Initializing an integer variable sum76 to zero
sum76 = 0

# Initializing an integer variable sum77 to zero
sum77 = 0

# Initializing an integer variable sum78 to zero
sum78 = 0

# Initializing an integer variable sum79 to zero
sum79 = 0

# Initializing an integer variable sum80 to zero
sum80 = 0

# Initializing an integer variable sum81 to zero
sum81 = 0

# Initializing an integer variable sum82 to zero
sum82 = 0

# Initializing an integer variable sum83 to zero
sum83 = 0

# Initializing an integer variable sum84 to zero
sum84 = 0

# Initializing an integer variable sum85 to zero
sum85 = 0

# Initializing an integer variable sum86 to zero
sum86 = 0

# Initializing an integer variable sum87 to zero
sum87 = 0

# Initializing an integer variable sum88 to zero
sum88 = 0

# Initializing an integer variable sum89 to zero
sum89 = 0

# Initializing an integer variable sum90 to zero
sum90 = 0

# Initializing an integer variable sum91 to zero
sum91 = 0

# Initializing an integer variable sum92 to zero
sum92 = 0

# Initializing an integer variable sum93 to zero
sum93 = 0

# Initializing an integer variable sum94 to zero
sum94 = 0

# Initializing an integer variable sum95 to zero
sum95 = 0

# Initializing an integer variable sum96 to zero
sum96 = 0

# Initializing an integer variable sum97 to zero
sum97 = 0

# Initializing an integer variable sum98 to zero
sum98 = 0

# Initializing an integer variable sum99 to zero
sum99 = 0

# Initializing an integer variable sum100 to zero
sum100 = 0

# Initializing an integer variable sum101 to zero
sum101 = 0

# Initializing an integer variable sum102 to zero
sum102 = 0

# Initializing an integer variable sum103 to zero
sum103 = 0

# Initializing an integer variable sum104 to zero
sum104 = 0

# Initializing an integer variable sum105 to zero
sum105 = 0

# Initializing an integer variable sum106 to zero
sum106 = 0

# Initializing an integer variable sum107 to zero
sum107 = 0

# Initializing an integer variable sum108 to zero
sum108 = 0

# Initializing an integer variable sum109 to zero
sum109 = 0

# Initializing an integer variable sum110 to zero
sum110 = 0

# Initializing an integer variable sum111 to zero
sum111 = 0

# Initializing an integer variable sum112 to zero
sum112 = 0

# Initializing an integer variable sum113 to zero
sum113 = 0

# Initializing an integer variable sum114 to zero
sum114 = 0

# Initializing an integer variable sum115 to zero
sum115 = 0

# Initializing an integer variable sum116 to zero
sum116 = 0

# Initializing an integer variable sum117 to zero
sum117 = 0

# Initializing an integer variable sum118 to zero
sum118 = 0

# Initializing an integer variable sum119 to zero
sum119 = 0

# Initializing an integer variable sum120 to zero
sum120 = 0

# Initializing an integer variable sum121 to zero
sum121 = 0

# Initializing an integer variable sum122 to zero
sum122 = 0

# Initializing an integer variable sum123 to zero
sum123 = 0

# Initializing an integer variable sum124 to zero
sum124 = 0

# Initializing an integer variable sum125 to zero
sum125 = 0

# Initializing an integer variable sum126 to zero
sum126 = 0

# Initializing an integer variable sum127 to zero
sum127 = 0

# Initializing an integer variable sum128 to zero
sum128 = 0

# Initializing an integer variable sum129 to zero
sum129 = 0

# Initializing an integer variable sum130 to zero
sum130 = 0

# Initializing an integer variable sum131 to zero
sum131 = 0

# Initializing an integer variable sum132 to zero
sum132 = 0

# Initializing an integer variable sum133 to zero
sum133 = 0

# Initializing an integer variable sum134 to zero
sum134 = 0

# Initializing an integer variable sum135 to zero
sum135 = 0

# Initializing an integer variable sum136 to ze