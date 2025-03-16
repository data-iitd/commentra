import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sz, i, k, p, ans;
		long A, B, a, b, j, ll, rr;
		int[] prime = new int[57100];	// Declare an array 'prime' of size 57100 to store prime numbers
		int[] base = new int[1000002];	// Declare an array 'base' of size 1000002 to store the prime number at each index
		int[] idx = new int[1000002];	// Declare an array 'idx' of size 1000002 to store the index of the prime number at each index
		long[] pp = new long[41];		// Declare an array 'pp' of size 41 to store powers of prime numbers

		// Initialize the prime array with the first few prime numbers
		// The rest of the prime numbers will be calculated using the Sieve of Eratosthenes algorithm
		prime[0] = 2;
		prime[1] = 3;
		prime[2] = 5;
		prime[3] = 7;
		prime[4] = 11;
		prime[5] = 13;
		prime[6] = 17;
		prime[7] = 19;
		prime[8] = 23;
		prime[9] = 29;
		prime[10] = 31;
		prime[11] = 37;
		prime[12] = 41;
		prime[13] = 43;
		prime[14] = 47;
		prime[15] = 53;
		prime[16] = 59;
		prime[17] = 61;
		prime[18] = 67;
		prime[19] = 71;
		prime[20] = 73;
		prime[21] = 79;
		prime[22] = 83;
		prime[23] = 89;
		prime[24] = 97;
		prime[25] = 101;
		prime[26] = 103;
		prime[27] = 107;
		prime[28] = 109;
		prime[29] = 113;
		prime[30] = 127;
		prime[31] = 131;
		prime[32] = 137;
		prime[33] = 139;
		prime[34] = 149;
		prime[35] = 151;
		prime[36] = 157;
		prime[37] = 163;
		prime[38] = 167;
		prime[39] = 173;
		prime[40] = 179;
		prime[41] = 181;
		prime[42] = 191;
		prime[43] = 193;
		prime[44] = 197;
		prime[45] = 199;
		prime[46] = 211;
		prime[47] = 223;
		prime[48] = 227;
		prime[49] = 229;
		prime[50] = 233;
		prime[51] = 239;
		prime[52] = 241;
		prime[53] = 251;
		prime[54] = 257;
		prime[55] = 263;
		prime[56] = 269;
		prime[57] = 271;
		prime[58] = 277;
		prime[59] = 281;
		prime[60] = 283;
		prime[61] = 293;
		prime[62] = 307;
		prime[63] = 311;
		prime[64] = 313;
		prime[65] = 317;
		prime[66] = 331;
		prime[67] = 337;
		prime[68] = 347;
		prime[69] = 349;
		prime[70] = 353;
		prime[71] = 359;
		prime[72] = 367;
		prime[73] = 373;
		prime[74] = 379;
		prime[75] = 383;
		prime[76] = 389;
		prime[77] = 397;
		prime[78] = 401;
		prime[79] = 409;
		prime[80] = 419;
		prime[81] = 421;
		prime[82] = 431;
		prime[83] = 433;
		prime[84] = 439;
		prime[85] = 443;
		prime[86] = 449;
		prime[87] = 457;
		prime[88] = 461;
		prime[89] = 463;
		prime[90] = 467;
		prime[91] = 479;
		prime[92] = 487;
		prime[93] = 491;
		prime[94] = 499;
		prime[95] = 503;
		prime[96] = 509;
		prime[97] = 521;
		prime[98] = 523;
		prime[99] = 541;
		prime[100] = 547;
		prime[101] = 557;
		prime[102] = 563;
		prime[103] = 569;
		prime[104] = 571;
		prime[105] = 577;
		prime[106] = 587;
		prime[107] = 593;
		prime[108] = 599;
		prime[109] = 601;
		prime[110] = 607;
		prime[111] = 613;
		prime[112] = 617;
		prime[113] = 619;
		prime[114] = 631;
		prime[115] = 641;
		prime[116] = 643;
		prime[117] = 647;
		prime[118] = 653;
		prime[119] = 659;
		prime[120] = 661;
		prime[121] = 673;
		prime[122] = 677;
		prime[123] = 683;
		prime[124] = 691;
		prime[125] = 701;
		prime[126] = 709;
		prime[127] = 719;
		prime[128] = 727;
		prime[129] = 733;
		prime[130] = 739;
		prime[131] = 743;
		prime[132] = 751;
		prime[133] = 757;
		prime[134] = 761;
		prime[135] = 769;
		prime[136] = 773;
		prime[137] = 787;
		prime[138] = 797;
		prime[139] = 809;
		prime[140] = 811;
		prime[141] = 821;
		prime[142] = 823;
		prime[143] = 827;
		prime[144] = 829;
		prime[145] = 839;
		prime[146] = 853;
		sz = 146;

		for (i = 0; i < sz; i++) {
			p = prime[i];			// Get the current prime number
			for (k = 1, j = p; j <= b; j *= p) pp[k++] = j;	// Calculate all powers of 'p' less than or equal to 'b'
			for (; k--; ) {
				j = pp[k], ll = j*(1+(a-1)/j), rr = j*(b/j);	// Calculate the lower and upper bounds of the segment to search for 'a' in
				for (; ll <= rr; ll += j) {
					int x = (int)(ll-a);	// Calculate the index 'x' of the segment
					if (idx[x] == 1 || base[x] == p) continue;	// If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
					base[x] = p, idx[x] = k;	// Otherwise, set the prime number at 'x' to 'p' and its index to 'k'
				}
			}
		}

		ans = 0, i = (int)(b-a+1);	// Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
		while (i--) if (idx[i] == 1) ans++;	// Increment 'ans' if the current segment has been processed
		System.out.println(ans);			// Output the result 'ans' and terminate the program
	}
}

