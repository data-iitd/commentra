#include<stdio.h>
#include<stdlib.h>
#include<string.h>

def push(chonda):
    global top,kinbo
    top += 1
    kinbo[top] = chonda

def pop():
    global top,kinbo
    top -= 1
    return kinbo[top + 1]

top = 0
kinbo = [0] * 1000

while True:
    null = input()
    if null == '+':
        chonda = pop()
        yamagami = pop()
        push(chonda + yamagami)
    elif null == '-':
        yamagami = pop()
        chonda = pop()
        push(chonda - yamagami)
    elif null == '*':
        chonda = pop()
        yamagami = pop()
        push(chonda * yamagami)
    else:
        push(int(null))

print(pop())

