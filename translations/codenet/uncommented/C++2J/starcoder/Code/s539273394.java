import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] innsuu = new int[11];
        int[][] A = new int[N+1][11];
        int[] prime_num = new int[1001];
        int[] prime_list = new int[1001];
        int prime_counter = 0;
        boolean[] prime_or_not = new boolean[1001];
        for (int i = 0; i <= 1000; ++i)
        {
            prime_num[i] = 0;
        }
        for (int i = 0; i <= 1000; ++i)
        {
            prime_or_not[i] = false;
        }
        for (int i = 2; i <= 1000; ++i)
        {
            if(prime_or_not[i]==false){
                prime_list[prime_counter] = i;
                prime_counter+=1;
            }
            for (int j = 2; j <= 1000/i; ++j)
            {
                if(prime_or_not[i]==false){
                    prime_or_not[i*j] = true;
                }
            }
        }
        for (int current_num = 2; current_num <= N; ++current_num)
        {
            for (int i = 0; i < prime_counter; ++i)
            {
                int time = 0;
                while(current_num%prime_list[i] == 0){
                    current_num = current_num/prime_list[i];
                    time++;
                }
                prime_num[i]+=time;
            }
        }
        for (int current_num = 2; current_num <= N; ++current_num){
            for (int i = 0; i < 11; ++i){
                innsuu[i] += A[current_num][i];
            }
        }
        long result = 1;
        for (int i = 0; i < prime_counter; ++i){
            result = (result*(prime_num[i]+1))%1000000007;
        }
        System.out.println(result);
    }
}
