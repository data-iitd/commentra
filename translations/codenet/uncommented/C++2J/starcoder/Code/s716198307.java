import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        double avg=0,s,ans;
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
            avg+=a[i];
        }
        avg/=n;
        s=Math.abs(a[0]-avg);
        ans=0;
        for(int i=1;i<n;i++){
            if(s>Math.abs(a[i]-avg)){
                s=Math.abs(a[i]-avg);
                ans=i;
            }
        }
        System.out.println(ans);
    }
}
