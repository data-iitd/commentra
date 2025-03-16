#include <stdio.h>
#include <string.h>

public class Main {
    public static void main(String[] args) {
        char[] s = new char[26];

        scanf("%s", s);

        for (int j = 0; j < strlen(s); j++) {
            for (int i = 0; i < strlen(s); i++) {
                if ((i != j) && (s[i] == s[j])) {
                    System.out.println("no");
                    return;
                }
            }
        }

        System.out.println("yes");
    }
}

