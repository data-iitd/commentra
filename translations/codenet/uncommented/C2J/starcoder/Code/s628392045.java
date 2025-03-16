
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,i;
        int h[] = new int[100001];
        int max = -1;
        int flag = 0;

        n = sc.nextInt();

        for(i = 0;i < n;i++){
            h[i] = sc.nextInt();
            if(max < h[i]) max = h[i];

            if(max - h[i] >= 2) flag = 1;
        }

        if(flag == 1) System.out.println("No");

        else System.out.println("Yes");
    }
}

