#include <stdio.h>
#include <string.h>

public class Main {
    public static void main(String[] args) {
        char[] buf = new char[512];
        int len;
        try {
            len = System.in.read(buf);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(buf[0] + len - 3 + buf[len - 2]);
    }
}

