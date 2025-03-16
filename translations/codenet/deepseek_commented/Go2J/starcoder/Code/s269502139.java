
package main;

import java.io.*;
import java.util.*;

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
class node {
	int key;
	node prev;
	node next;
}

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node n, StringBuilder buf) {
	buf.append(n.key);
	if (n.next!= null) {
		buf.append(" ");
		rPrint(n.next, buf);
	}
	return;
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
node Delete(node n, node first, node last) {
	if (n.prev!= null && n.next!= null) {
		//swap
		n.prev.next = n.next;
		n.next.prev = n.prev;
		return first;
	}

	if (n.next == null && n.prev == null) {
		return null;
	}

	if (n.prev == null) {
		first = n.next;
		n.next.prev = null;
	}

	if (n.next == null) {
		last = n.prev;
		n.prev.next = null;
	}

	return first;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node initNode(int key) {
	node n = new node();
	n.key = key;
	return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
public class Main {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		node first = null;
		node last = null;
		stdin.nextLine();

		while (stdin.hasNextLine()) {
			String cmd = stdin.nextLine();
			switch (cmd) {
			case "deleteFirst":
				first = Delete(first, first, last);
				break;
			case "deleteLast":
				first = Delete(last, first, last);
				break;
			default:
				String[] xcmd = cmd.split(" ");
				int k = Integer.parseInt(xcmd[1]);
				switch (xcmd[0]) {
				case "delete":
					for (node a = first; a!= null; a = a.next) {
						if (a.key == k) {
							first = Delete(a, first, last);
							break;
						}
					}
					break;
				case "insert":
					node n = initNode(k);
					n.next = first;
					if (first!= null) {
						first.prev = n;
					}

					first = n;
					if (last == null) {
						last = n;
					}
					break;
				}
			}
		}
		StringBuilder buf = new StringBuilder();
		rPrint(first, buf);
		System.out.println(buf.toString());
	}
}

