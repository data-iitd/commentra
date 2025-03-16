
// Package main is the entry point of the program
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;

// Define a deque (double ended queue) type
class Deque {
    Queue<Character> front; // Front queue to store the elements
    Queue<Character> back;  // Back queue to store the elements

    // Constructor to initialize the deque
    Deque() {
        front = new ArrayDeque<>();
        back = new ArrayDeque<>();
    }

    // Function to check if deque is empty at the front
    boolean isEmptyFront() {
        // Return true if the front queue is empty
        return front.isEmpty();
    }

    // Function to check if deque is empty at the back
    boolean isEmptyBack() {
        // Return true if the back queue is empty
        return back.isEmpty();
    }

    // Function to add an element at the back of the deque
    void pushBack(char v) {
        // Add the given character to the back queue
        back.add(v);
    }

    // Function to add an element at the front of the deque
    void pushFront(char v) {
        // Add the given character to the front queue
        front.add(v);
    }

    // Function to remove an element from the back of the deque and return it
    char popBack() {
        // If the deque is not empty at the back, pop the last element and return it
        char v = back.remove();
        return v;
    }

    // Function to remove an element from the front of the deque and return it
    char popFront() {
        // If the deque is not empty at the front, pop the first element and return it
        char v = front.remove();
        return v;
    }

    // Function to get an element from the deque by its index
    char get(int idx) {
        // Calculate the total length of the deque
        int tot = front.size() + back.size();
        // If the index is valid, return the corresponding element
        char v ='';
        if (idx < tot) {
            if (idx < front.size()) {
                v = front.element();
                for (int i = 0; i < idx; i++) {
                    v = front.remove();
                    front.add(v);
                }
            } else {
                v = back.element();
                for (int i = 0; i < idx - front.size(); i++) {
                    v = back.remove();
                    back.add(v);
                }
            }
        }
        return v;
    }
}

// Function to reverse a given string
String rev(String s) {
    // Create a character array with the length of the given string
    char[] r = new char[s.length()];
    // Initialize the indices i and j
    int i = s.length() - 1, j = 0;
    // Iterate through the string from the end to the beginning
    for (i = s.length() - 1; i >= 0; i--) {
        // Store the character at index i in the reverse string
        r[j] = s.charAt(i);
        // Increment j
        j++;
    }
    // Return the reversed string
    return new String(r);
}

// s323794848 function to read input and process it
public class s323794848{
    public static void main(String[] args) throws Exception {
        // Read the input string S from the standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        // Read the number of operations Q from the standard input
        int Q = Integer.parseInt(br.readLine());
        // Initialize an array of operations ops with the given size
        Op[] ops = new Op[Q];
        // Read the operations one by one and store them in the ops array
        for (int i = 0; i < Q; i++) {
            // Read the type of operation (reverse or not)
            int q = Integer.parseInt(br.readLine());
            // If the operation is to reverse the string, set the rev field to true
            if (q == 1) {
                ops[i].rev = true;
            } else {
                // Else, read the front flag and the character c from the standard input
                String[] s = br.readLine().split(" ");
                int f = Integer.parseInt(s[0]);
                char c = s[1].charAt(0);
                // Set the front field based on the front flag
                if (f == 1) {
                    ops[i].front = true;
                }
                // Set the character field
                ops[i].c = c;
            }
        }
        // Initialize an array of sums sum with the given size
        int[] sum = new int[Q + 1];
        // Initialize the sum of the first operation
        sum[0] = 0;
        // Iterate through the remaining operations and calculate their sums
        for (int i = Q - 1; i >= 0; i--) {
            // If the current operation is to reverse the string, increment the previous sum
            if (ops[i].rev) {
                sum[i - 1] = sum[i] + 1;
            } else {
                // Else, set the previous sum to the current sum
                sum[i - 1] = sum[i];
            }
        }
        // If the sum of the first operation is odd, reverse the input string
        if (sum[0] % 2 == 1) {
            S = rev(S);
        }
        // Initialize a deque deq
        Deque deq = new Deque();
        // Iterate through the operations and process them based on their type
        for (int i = 0; i < Q; i++) {
            // If the current operation is not to reverse the string
            if (!ops[i].rev) {
                // If the operation is to add a character at the front, process it accordingly
                if (ops[i].front) {
                    // If the previous sum is odd, push the character to the front of the deque
                    if (sum[i] % 2 == 1) {
                        deq.pushFront(ops[i].c);
                    } else {
                        deq.pushBack(ops[i].c);
                    }
                } else { // Else, process the operation to add a character at the end
                    // If the previous sum is odd, push the character to the end of the deque
                    if (sum[i] % 2 == 1) {
                        deq.pushBack(ops[i].c);
                    } else {
                        deq.pushFront(ops[i].c);
                    }
                }
            }
        }
        // Write the result to the standard output
        PrintWriter pw = new PrintWriter(System.out);
        // Write the characters in the deque to the standard output
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            pw.print(deq.front.remove());
        }
        // Write the input string to the standard output
        for (int i = 0; i < S.length(); i++) {
            pw.print(S.charAt(i));
        }
        // Write the characters in the deque to the standard output
        for (int i = 0; i < deq.back.size(); i++) {
            pw.print(deq.back.remove());
        }
        // Flush the buffer and exit
        pw.println();
        pw.flush();
    }
}

// Define a struct to represent an operation
class Op {
    boolean rev; // Flag to indicate if the operation is to reverse the string
    boolean front; // Flag to indicate if the operation is to add a character at the front
    char c; // Character to be added

    // Constructor to initialize the operation
    Op() {
        rev = false;
        front = false;
        c ='';
    }
}

// Translate the above Java code to C++ and end with comment "