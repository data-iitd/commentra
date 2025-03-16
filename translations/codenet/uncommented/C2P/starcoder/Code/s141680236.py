
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

def push(chonda):
    global top
    top += 1
    kinbo[top] = chonda

def pop():
    global top
    top -= 1
    return kinbo[top + 1]

kinbo = [0] * 1000
top = 0

while(True):
    null = raw_input()
    if(null == "