#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, x; // 1. Reading the number of courses, the number of skills, and the minimum required skill level.
	cin >> n >> m >> x;

	vector<vector<int>> a(n); // 2. Dynamically allocating memory for the 2D slice representing the cost of each course for each skill.
	vector<int> p(n);   // 3. Allocating memory for the slice representing the cost of each course.
	for (int i = 0; i < n; i++) {

		cin >> p[i]; // 4. Reading the cost of each course.
		a[i] = vector<int>(m); // 5. Dynamically allocating memory for each course's skill levels.
		for (int j = 0; j < m; j++) {
			cin >> a[i][j]; // 6. Reading the skill levels for each course.
		}
	}

	int ans = 1200001; // 7. Initializing the answer with a large number. This will hold the minimum cost of courses that meet the skill requirement.
	int tot = 0; // 8. A variable to keep track of the total cost of the current combination of courses.
	bool ok = true; // 9. A flag to check if the current combination meets the skill requirement.
	for (int bits = 0; bits < 1<<n; bits++) { // 10. Iterating through all possible combinations of courses using bitwise operations.
		tot = 0;
		ok = true;
		vector<int> skill(m); // 11. Initializing a slice to keep track of the total skill level for the current combination.
		for (int i = 0; i < n; i++) {
			if (bits>>i)&1 == 1 { // 12. Checking if the i-th course is included in the current combination.
				tot += p[i];
				for (int j = 0; j < m; j++) {
					skill[j] += a[i][j]; // 13. Updating the total skill level for each skill.
				}
			}
		}

		for (int v : skill) { // 14. Checking if all skill levels are at least x.
			if (v < x) {
				ok = false;
				break;
			}
		}

		if (ok) { // 15. If the current combination meets the skill requirement, updating the answer if the cost is lower.
			if (ans > tot) {
				ans = tot;
			}
		}
	}

	if (ans!= 1200001) { // 16. Printing the result.
		cout << ans << endl;
	} else {
		cout << "-1" << endl;
	}

}

