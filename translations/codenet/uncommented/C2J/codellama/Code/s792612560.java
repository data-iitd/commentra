
public class Main {
	public static void main(String[] args) {
		int n;
		long m;
		n = Integer.parseInt(args[0]);
		m = n;
		n--;
		for (; n > 1; n--) {
			m *= n;
		}
		System.out.println(m);
	}
}

