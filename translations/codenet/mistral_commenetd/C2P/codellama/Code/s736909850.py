
#include<stdio.h>

# Declare two integer variables to store the number of sheep and wolves
sheep = 0
wolf = 0

# Read two integers from the standard input and store them in the sheep and wolf variables
scanf("%d %d",&sheep,&wolf)

# Check if the number of wolves is greater than or equal to the number of sheep
if(wolf >= sheep):
   # If the condition is true, print the message "unsafe" to the standard output
   print("unsafe\n")
else:
   # If the condition is false, print the message "safe" to the standard output
   print("safe\n")

# End the main function by returning 0 to indicate successful execution
return 0

