
const int mod = 100000007;
int n;
cin >> n;
vector<int> c(n);
for (int i = 0; i < n; i++) {
    cin >> c[i];
}
sort(c.begin(), c.end(), greater<int>());
long long b = pow(2, 2 * n - 2, mod);
long long a = 2 * b % mod;
long long ans = 0;
for (int i = 0; i < n; i++) {
    ans += c[i] * (a + i * b) % mod;
    ans %= mod;
}
cout << ans << endl;



Translate the above Python code to Java and end with comment "