import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int ans = 0;
        int out = 1;

        while(out<B){
            out--;
            out += A;
            ans++;
        }
        System.out.println(ans);
    }
}
