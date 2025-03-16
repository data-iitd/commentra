import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n,i,j,m,s,t;
        n=sc.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        t=0;
        for(i=0;i<n;i++){
            s=0;
            for(j=1;j<n;j++){
                if(j<=i){
                    continue;
                }
                m=a[i]*a[j];
                s=s+m;
            }
            t=t+s;
        }
        System.out.println(t);
    }
}
