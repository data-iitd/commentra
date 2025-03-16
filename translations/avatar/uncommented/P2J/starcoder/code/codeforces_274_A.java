import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = sc.nextInt();
        Arrays.sort(arr);
        Set<Integer> set = new HashSet<Integer>();
        int temp = 0;
        for(int x:arr){
            if(x%k!=0 ||!set.contains(x/k)) set.add(x);
            temp = Math.max(set.size(),temp);
        }
        System.out.println(temp);
    }
}
