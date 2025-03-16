
package main;

import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    for (int i = 0; i < 5; i++) {
      int a = scanner.nextInt();

      if (a == 0) {
        System.out.println(i + 1);
      }
    }
  }
}

