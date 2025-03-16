#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//  長い入力を読む
vector<string> ReadLongLines(int times) {
	vector<string> result(times);
	string buffer;
	for (int i = 0; i < times; i++) {
		getline(cin, buffer);
		result[i] = buffer;
	}
	return result;
}

// 出力 for 競プロ
class Console {
public:
	Console() : writer(new ofstream(stdout)) {}
	~Console() {
		delete writer;
	}
	void Printf(const char* format,...) {
		va_list arg;
		va_start(arg, format);
		vfprintf(writer, format, arg);
		va_end(arg);
	}
	void Println(const string& s) {
		fprintf(writer, "%s\n", s.c_str());
	}
	void Flush() {
		fflush(writer);
	}
private:
	ofstream* writer;
};

void PrintList(vector<int>& list) {
	Console con;
	for (int i = 0; i < list.size(); i++) {
		if (i == 0) {
			con.Printf("%d", list[i]);
		} else {
			con.Printf(" %d", list[i]);
		}
	}
	con.Println("");
}

int main() {
	Console con;
	map<int, bool> m;
	vector<string> lines = ReadLongLines(4);
	vector<string> a = split(lines[1], " ");
	for (int i = 0; i < a.size(); i++) {
		int n = atoi(a[i].c_str());
		m[n] = true;
	}

	vector<int> result;
	vector<string> b = split(lines[3], " ");
	for (int i = 0; i < b.size(); i++) {
		int n = atoi(b[i].c_str());
		if (m.find(n)!= m.end()) {
			m.erase(n);
		} else {
			m[n] = true;
		}
	}
	for (auto it = m.begin(); it!= m.end(); it++) {
		result.push_back(it->first);
	}
	sort(result.begin(), result.end());
	for (int j = 0; j < result.size(); j++) {
		con.Printf("%d\n", result[j]);
	}
}

