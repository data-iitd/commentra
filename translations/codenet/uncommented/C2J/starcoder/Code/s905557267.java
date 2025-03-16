import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		int i, j;
		int a[] = new int[10000];
		int ans;
		int color;
		
		while (true){
			for (i = 0; i < 10000; i++){
				a[i] = 0;
			}
			
			n = in.nextInt();
			if (n == 0){
				break;
			}
			ans = n;
			
			for (i = 0; i < n; i++){
				a[i] = in.nextInt();
			}
			
			for (i = 0; i < n - 4; i++){
				int count[] = new int[3];
				for (j = i; j < i + 4; j++){
					if (a[j] - 1 >= 0){
						count[a[j] - 1]++;
					}
				}
				
				color = 0;
				for (j = 0; j < 3; j++){
					if (count[j] >= 3){
						color = j + 1;
						break;
					}
				}
				
				if (color!= 0){
					for (j = i; j < i + 4; j++){
						int buf;
						buf = a[j];
						a[j] = color;
						ans = Math.min(ans, Chain(a, n));
						a[j] = buf;
					}
				}
			}
			
			System.out.println(ans);
		}
	}
	
	public static int min(int a, int b)
	{
		if (a <= b){
			return (a);
		}
		return (b);
	}
	
	public static int Chain(int b[], int n)
	{
		int i, j;
		int count;
		int color;
		int a[] = new int[10000];
		
		for (i = 0; i < n; i++){
			a[i] = b[i];
		}
		
		for (i = 0; i < n - 4; i++){
			if (a[i]!= 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]){
				//System.out.println("-----");
				//for (j = 0; j < n; j++){
				//	System.out.println(a[j]);
				//}
				//System.out.println("-----");
				
				count = 0;
				color = a[i];
				
				for (j = i; a[j] == color; j++){
					a[j] = 0;
					count++;
				}
				
				for (j = 0; i + j + count < 10000; j++){
					a[i + j] = a[i + j + count];
					a[i + j + count] = 0;
				}
				
				//System.out.println("-----");
				//for (j = 0; j < n; j++){
				//	System.out.println(a[j]);
				//}
				//System.out.println("-----");
				//System.in.read();
				
				i = 0;
			}
			
		}
		
		count = 0;
		while (a[count]!= 0){
			count++;
		}
		
		if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]){
			return (0);
		}
		
		return (count);
	}
}

