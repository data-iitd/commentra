import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n,k,p[]=new int[99999],i,j,l,m,o=0;
        // Read the number of elements (n) and the number of elements to sum (k)
        n=sc.nextInt();
        k=sc.nextInt();
        // Read n integers and store them in the array p
        for(i=0;i<n;i++){
            p[i]=sc.nextInt();
        }
        // Perform selection sort on the array p
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
        // Sum the first k elements of the sorted array
        for(i=0;i<k;i++){
            o +=p[i];
        }
        // Print the sum of the first k elements
        System.out.println(o);
    }
}
