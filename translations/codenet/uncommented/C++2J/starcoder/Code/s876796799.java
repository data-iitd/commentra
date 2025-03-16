import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        long[] a = new long[N];
        for(int i = 0; i < N; i++){
            a[i] = in.nextLong();
        }
        long ans = 0;
        for(int i = 0; i < N; i++){
            long left_border = -1;
            long right_border = N;
            long cur_ind = a[i] - 1;
            int left_ind = 0;
            int right_ind = 0;
            for(int j = 0; j < i; j++){
                if(a[j] < a[i]){
                    left_ind = j;
                }
            }
            for(int j = i + 1; j < N; j++){
                if(a[j] > a[i]){
                    right_ind = j;
                }
            }
            if(left_ind!= 0){
                left_border = a[left_ind] - 1;
            }
            if(right_ind!= N - 1){
                right_border = a[right_ind] - 1;
            }
            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1);
        }
        System.out.println(ans);
    }
}

