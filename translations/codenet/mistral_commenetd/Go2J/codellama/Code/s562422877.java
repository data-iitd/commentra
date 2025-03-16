
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize variables and read input
        // Code for A - Initialize variables and read input
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array:");
        int N = scanner.nextInt();

        int[] A = new int[N];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Sort the array in ascending order
        // Code for C - Sort the array
        sort(A);

        // Calculate the answer
        // Code for D - Calculate the answer
        int ans = 0;
        System.out.println("Calculating the answer...");
        for (int i = 1; i < N; i++) {
            ans += A[i] - A[i-1];
        }

        // Print the answer
        // Code for E - Print the answer
        System.out.println("The answer is: " + ans);
    }

    public static void sort(int[] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
    }
}

