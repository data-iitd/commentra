// Package main provides
//
// File:  a.java
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
package main;

import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        if (A + B >= C) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

