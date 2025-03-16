
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
		Console() {
			this->writer = &cout;
		}
		void Printf(const char* format, ...) {
			va_list args;
			va_start(args, format);
			vfprintf(this->writer, format, args);
			va_end(args);
		}
		void Println(const string& s) {
			*this->writer << s << endl;
		}
		void Close() {
			this->Flush();
		}
		void Flush() {
			this->writer->flush();
		}
	private:
		ostream* writer;
};

void PrintList(const vector<int>& list) {
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
	map<int, int> m;
	vector<string> lines = ReadLongLines(4);
	vector<string> a = split(lines[1], " ");
	for (int i = 0; i < a.size(); i++) {
		int n = stoi(a[i]);
		m[n] = 1;
	}

	vector<int> result;
	vector<string> b = split(lines[3], " ");
	for (int i = 0; i < b.size(); i++) {
		int n = stoi(b[i]);
		if (m.find(n) != m.end()) {
			m.erase(n);
		} else {
			m[n] = 1;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		result.push_back(it->first);
	}
	sort(result.begin(), result.end());
	for (int j = 0; j < result.size(); j++) {
		con.Printf("%d\n", result[j]);
	}
	return 0;
}