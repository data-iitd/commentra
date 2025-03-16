
import java.util.*;
import java.io.*;

class s918723842 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        
        int A = Math.max(H, W);
        
        System.out.println((N + A - 1) / A);
    }
}

