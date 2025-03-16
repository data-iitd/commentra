import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1, math[] = new int[N+1];
        int a, sum = 0, ans, i, j;

        math[0] = 1;

        num1 = sc.nextInt();
        for(i = 0; i < num1; i++){
            a = sc.nextInt();
            sum += a;
            for(j = sum - a; j >= 0; j--){
                if(math[j] == 1) math[j + a] = 1;
            }
        }

        num2 = sc.nextInt();
        for(i = 0; i < num2; i++){
            ans = sc.nextInt();
            if(math[ans] == 1) System.out.println("yes");
            else System.out.println("no");
        }
    }
}
