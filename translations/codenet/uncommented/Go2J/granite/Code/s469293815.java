
// Package main provides
//
// File:  a.java
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
package main;

import java.util.Scanner;

public class s469293815{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int C = scanner.nextInt();

    if (A + B >= C) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}
