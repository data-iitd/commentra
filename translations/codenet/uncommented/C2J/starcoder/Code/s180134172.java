import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n,k,p[],i,j,l,m,o=0;
        n=sc.nextInt();
        k=sc.nextInt();
        p=new int[n];
        for(i=0;i<n;i++){
            p[i]=sc.nextInt();
        }
        for(i=0;i<n;i++){
            l=i;
            for(j=i+1;j<n;j++){
                if(p[j]<p[l]){
                    l=j;
                }
            }
            if(l!=i) {
                m=p[i];
                p[i]=p[l];
                p[l]=m;
            }
        }
        for(i=0;i<k;i++){
            o +=p[i];
        }
        System.out.println(o);
    }
}
