
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int ans = N / (D*2+1);
        int rem = N % (D*2+1);
        if(rem != 0){
            ans = ans + 1;
        }
        System.out.println(ans);
    }
}

