// Depth-first search
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[][] ab = new int[N-1][2];
        int[][] edges = new int[N][N];
        for (int i = 0; i < N-1; i++) {
            int a = in.nextInt() - 1; // Convert to zero-based index
            int b = in.nextInt() - 1; // Convert to zero-based index
            ab[i][0] = a;
            ab[i][1] = b;
            edges[a][edges[a].length-1] = b;
            edges[b][edges[b].length-1] = a;
        }
        int[] colors = new int[N-1];
        int[] q = new int[N];
        int qHead = 0;
        q[qHead] = 0;
        int usedColor = -1;
        int parentNode = -1;
        while (qHead!= -1) {
            int currentNode = q[qHead];
            qHead--;
            int color = 1;
            for (int i = 0; i < edges[currentNode].length; i++) {
                int childNode = edges[currentNode][i];
                if (childNode == parentNode) {
                    continue; // Skip the parent node to avoid backtracking
                }
                if (color == usedColor) {
                    color++; // Skip the color that was used by the parent
                }
                // Assign color to the edge between currentNode and childNode
                colors[genid(currentNode, childNode)] = color;
                // Push the child node onto the stack for further exploration
                qHead++;
                q[qHead] = childNode;
                color++; // Move to the next color for the next edge
            }
            usedColor = color - 1;
            parentNode = currentNode;
        }
        int K = -1;
        for (int i = 0; i < N; i++) {
            int t = edges[i].length; // Degree of the current node
            if (t > K) {
                K = t; // Update maximum degree if current node's degree is greater
            }
        }
        System.out.println(K); // Print the maximum degree
        for (int i = 0; i < N-1; i++) {
            System.out.println(colors[genid(ab[i][0], ab[i][1])]);
        }
    }

    // genid generates a unique identifier for an edge between two nodes a and b
    // by ensuring a is less than b and combining them into a single integer.
    public static int genid(int a, int b) {
        if (b < a) {
            a = b;
        }
        return a*100000 + b;
    }
}

// 