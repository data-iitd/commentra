
#include <stdio.h>
#include <string.h>
#define LEN 100005

class pp:
    def __init__(self):
        self.name = ""
        self.t = 0

Q = [pp() for i in range(LEN)] # queue to store process information
head, tail, n = 0, 0, 0 # head and tail indices of the queue, and total number of processes

def enqueue(x): # function to add a process to the queue
    Q[tail] = x
    tail = (tail + 1) % LEN

def dequeue(): # function to remove a process from the queue
    x = Q[head]
    head = (head + 1) % LEN
    return x

def min(a, b): # helper function to find the minimum of two integers
    return a < b and a or b

def main(): # main function
    elaps = 0 # elapsed time
    c = 0 # the number of units processed in each iteration
    i = 0 # loop variable
    u = pp() # variable to store the process dequeued from the queue

    n, q = map(int, raw_input().split()) # read the number of processes and the number of queries

    for i in range(1, n + 1): # initialize the queue with process information
        u.name, u.t = raw_input().split()
        u.t = int(u.t)
        enqueue(u) # enqueue each process
    head = 1
    tail = n + 1

    while head!= tail: # processing loop
        u = dequeue() # dequeue a process
        c = min(q, u.t) # calculate the number of units to be processed in this iteration
        u.t -= c # update the remaining time for the process
        elaps += c # update the elapsed time
        if u.t > 0: # if the process still has remaining time, enqueue it again
            enqueue(u)
        else: # if the process has been fully processed, print the result
            print u.name, elaps

    return 0

main()

