import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int t = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int da = sc.nextInt();
        int db = sc.nextInt();
        if(x == 0){
            System.out.println("YES");
            return;
        }
        int a_time = Math.min(a/da, t-1);
        int b_time = Math.min(b/db, t-1);
        for(int i = 0; i <= a_time; i++){
            for(int j = 0; j <= b_time; j++){
                if(a - da*i == x || b - db*j == x){
                    System.out.println("YES");
                    return;
                }
                if(a - da*i + b - db*j == x){
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}
