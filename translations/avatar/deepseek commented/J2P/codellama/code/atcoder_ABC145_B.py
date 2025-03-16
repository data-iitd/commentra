
import math 
import os 
import random 
import re 
import sys 

# Complete the is_palindrome function below. 
def is_palindrome(s): 
    return s == s[::-1] 

if __name__ == '__main__': 
    n = int(input()) 
    s = input() 
    result = is_palindrome(s) 
    if result: 
        print("Yes") 
    else: 
        print("No") 

# 