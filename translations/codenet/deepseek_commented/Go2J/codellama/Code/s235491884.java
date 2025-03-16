
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length() - s.replace("o", "").length();
        System.out.println(700 + n*100);
    }
}

