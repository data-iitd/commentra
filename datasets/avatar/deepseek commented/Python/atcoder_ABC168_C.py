
a , b , h , m = map ( int , input ( ).split ( ) )
# Taking input values for the lengths of the sides of the triangle and the time

import math
# Importing the math module to use mathematical functions

C = abs ( 360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m )
# Calculating the angle C between the hour and minute hands of a clock

if C > 180 :
    C = 360 - C
# Adjusting the angle C if it is greater than 180 degrees

cosC = math.cos ( math.radians ( C ) )
# Calculating the cosine of angle C in radians

print ( math.sqrt ( a ** 2 + b ** 2 - 2 * a * b * cosC ) )
# Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines

