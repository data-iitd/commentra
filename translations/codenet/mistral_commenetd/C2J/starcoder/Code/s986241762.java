
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n;
		long sum=0;
		System.out.print("Enter the number of elements in the array: ");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.print("Enter "+n+" integers:\n");
		for(int i=0;i<n;i++){
			System.out.print("Enter element number "+(i+1)+": ");
			a[i] = sc.nextInt();
		}
		for(int i=1;i<n;i++){
			if(a[i-1]>a[i]){
				sum += a[i-1]-a[i];
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
			}
		}
		System.out.print("The sum of the differences is: "+sum);
	}
}
