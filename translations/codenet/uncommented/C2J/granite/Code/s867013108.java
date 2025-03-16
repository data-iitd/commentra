
/*
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] nyuyoku_ticket = new int[n];
		int[] pool_ticket = new int[n];
		int[] nyuyoku_member = new int[n];
		int[] pool_member = new int[n];
		int[] seiki_ryoukin = new int[n];
		int[] waribiki_ryoukin = new int[n];
		int[] saiyasune = new int[n];
		for(int i = 0; i < n; i++) {
			nyuyoku_ticket[i] = sc.nextInt();
			pool_ticket[i] = sc.nextInt();
			nyuyoku_member[i] = sc.nextInt();
			pool_member[i] = sc.nextInt();
			if(nyuyoku_member[i] >= 5 && pool_member[i] >= 2) {
				seiki_ryoukin[i] = (int)Math.floor(((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8) / 10));
				saiyasune[i] = seiki_ryoukin[i];
			} else if(nyuyoku_member[i] >= 5) {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (int)Math.floor(((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * 2)) * 8) / 10));
				if(seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
					saiyasune[i] = waribiki_ryoukin[i];
				} else {
					saiyasune[i] = seiki_ryoukin[i];
				}
			} else if(pool_member[i] >= 2) {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (int)Math.floor(((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8) / 10));
				if(seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
					saiyasune[i] = waribiki_ryoukin[i];
				} else {
					saiyasune[i] = seiki_ryoukin[i];
				}
			} else {
				seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
				waribiki_ryoukin[i] = (int)Math.floor(((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) / 10));
				if(seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
					saiyasune[i] = waribiki_ryoukin[i];
				} else {
					saiyasune[i] = seiki_ryoukin[i];
				}
			}
		}
		for(int i = 0; i < n; i++) {
			System.out.println(saiyasune[i]);
		}
	}
*/
