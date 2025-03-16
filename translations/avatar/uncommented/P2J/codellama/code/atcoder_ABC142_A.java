import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                t++;
            }
        }
        System.out.println(t / n);
    }
}



Translate the above Java code to C++ and end with comment "