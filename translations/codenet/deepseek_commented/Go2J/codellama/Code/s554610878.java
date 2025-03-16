
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String[] week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }

        System.out.println(7 - index);
    }
}

