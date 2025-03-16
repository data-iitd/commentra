import re

def regexBU(src, pat):
    # Create a 2D boolean array to store the matching results
    strg = [[False] * (len(pat) + 1) for _ in range(len(src) + 1)]
    
    # Initialize the bottom-right cell to true (empty string matches empty pattern)
    strg[len(src)][len(pat)] = True

    # Iterate over the source string in reverse order
    for row in range(len(src), -1, -1):
        # Iterate over the pattern string in reverse order
        for col in range(len(pat) - 1, -1, -1):
            # Handle the case when the source string is empty
            if row == len(src):
                # If the current pattern character is '*', check if the next pattern character can match
                if pat[col] == '*':
                    strg[row][col] = strg[row][col + 1]
                else:
                    # If not, set the current cell to false
                    strg[row][col] = False
            else:
                # Get the current characters from the source and pattern
                chs = src[row]
                chp = pat[col]
                ans = False

                # Check for character match or '?' wildcard
                if chs == chp or chp == '?':
                    ans = strg[row + 1][col + 1]
                # Handle '*' wildcard which can match zero or more characters
                elif chp == '*':
                    blank = strg[row][col + 1] # Match '*' with zero characters
                    multiple = strg[row + 1][col] # Match '*' with one or more characters
                    ans = blank or multiple
                else:
                    # If characters do not match, set answer to false
                    ans = False
                # Store the result in the current cell
                strg[row][col] = ans
    # Return the result of the match for the entire source and pattern
    return strg[0][0]


# Test the regexBU method with the following inputs
src = "abcd"
pat = "a*b*c*d"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*m"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*m*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*m*n"
print(regexBU(src, pat)) # Output: False

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*m*n*"
print(regexBU(src, pat)) # Output: True

src = "abcd"
pat = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*a*b*c*d*e*f*g*h*i*j*k*l*m*n*o"
print(regexBU(src, pat)) # Output: False

src = "a