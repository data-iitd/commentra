
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# Initialize stack top and array kinbo
top = 0
kinbo = [0] * 1000

def push(chonda):
  # Increment top and push element chonda into kinbo array
  global top
  kinbo[top] = chonda
  top += 1

def pop():
  # Decrement top and return the top element
  global top
  top -= 1
  return kinbo[top]

def main():
  chonda, yamagami = 0, 0 # Initialize variables chonda and yamagami

  # Initialize stack top to 0
  top = 0

  null = "" # Initialize a character array null of size 100

  # Read input strings from standard input until EOF is reached
  while True:
    null = input()
    if null == "":
      break
    # Check if the first character of the input string is '+'
    if null[0] == '+':
      # Pop two elements from the stack
      chonda = pop()
      yamagami = pop()

      # Add the popped elements and push the result onto the stack
      push(chonda + yamagami)
    # Check if the first character of the input string is '-'
    elif null[0] == '-':
      # Pop two elements from the stack
      yamagami = pop()
      chonda = pop()

      # Subtract the second popped element from the first popped element and push the result onto the stack
      push(chonda - yamagami)
    # Check if the first character of the input string is '*'
    elif null[0] == '*':
      # Pop two elements from the stack
      chonda = pop()
      yamagami = pop()

      # Multiply the popped elements and push the result onto the stack
      push(chonda * yamagami)
    # If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
    else:
      push(int(null))

  # Print the top element of the stack, which is the final result
  print(pop())

if __name__ == "__main__":
  main()

