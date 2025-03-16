#include <bits/stdc++.h>

using namespace std;

//=====I/O=====

// Declare scanner and writer for input and output
std::istream& operator>>(std::istream& is, vector<int>& v) {
	for (int& x : v) is >> x;
	return is;
}

std::ostream& operator<<(std::ostream& os, const vector<int>& v) {
	for (int x : v) os << x << " ";
	return os << endl;
}

std::istream& operator>>(std::istream& is, vector<long long>& v) {
	for (long long& x : v) is >> x;
	return is;
}

std::ostream& operator<<(std::ostream& os, const vector<long long>& v) {
	for (long long x : v) os << x << " ";
	return os << endl;
}

std::istream& operator>>(std::istream& is, vector<string>& v) {
	for (string& x : v) is >> x;
	return is;
}

std::ostream& operator<<(std::ostream& os, const vector<string>& v) {
	for (string x : v) os << x << " ";
	return os << endl;
}

std::istream& operator>>(std::istream& is, vector<char>& v) {
	for (char& x : v) is >> x;
	return is;
}

std::ostream& operator<<(std::ostream& os, const vector<char>& v) {
	for (char x : v) os << x << " ";
	return os << endl;
}

std::istream& operator>>(std::istream& is, vector<bool>& v) {
	for (bool& x : v) is >> x;
	return is;
}

std::ostream& operator<<(std::ostream& os, const vector<bool>& v) {
	for (bool x : v) os << x << " ";
	return os << endl;
}

std::istream& operator>>(std::istream& is, pair<int, int>& p) {
	is >> p.first >> p.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const pair<int, int>& p) {
	os << p.first << " " << p.second;
	return os;
}

std::istream& operator>>(std::istream& is, pair<long long, long long>& p) {
	is >> p.first >> p.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const pair<long long, long long>& p) {
	os << p.first << " " << p.second;
	return os;
}

std::istream& operator>>(std::istream& is, pair<string, string>& p) {
	is >> p.first >> p.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const pair<string, string>& p) {
	os << p.first << " " << p.second;
	return os;
}

std::istream& operator>>(std::istream& is, pair<char, char>& p) {
	is >> p.first >> p.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const pair<char, char>& p) {
	os << p.first << " " << p.second;
	return os;
}

std::istream& operator>>(std::istream& is, pair<bool, bool>& p) {
	is >> p.first >> p.second;
	return is;
}

std::ostream& operator<<(std::ostream& os, const pair<bool, bool>& p) {
	os << p.first << " " << p.second;
	return os;
}

std::istream& operator>>(std::istream& is, tuple<int, int, int>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<int, int, int>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<long long, long long, long long>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<long long, long long, long long>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<string, string, string>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<string, string, string>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<char, char, char>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<char, char, char>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<bool, bool, bool>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<bool, bool, bool>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<int, int, int, int>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<int, int, int, int>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<long long, long long, long long, long long>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<long long, long long, long long, long long>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<string, string, string, string>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<string, string, string, string>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<char, char, char, char>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<char, char, char, char>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<bool, bool, bool, bool>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<bool, bool, bool, bool>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<int, int, int, int, int>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<int, int, int, int, int>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<long long, long long, long long, long long, long long>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<long long, long long, long long, long long, long long>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<string, string, string, string, string>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<string, string, string, string, string>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<char, char, char, char, char>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<char, char, char, char, char>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<bool, bool, bool, bool, bool>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<bool, bool, bool, bool, bool>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<int, int, int, int, int, int>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<int, int, int, int, int, int>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<long long, long long, long long, long long, long long, long long>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<long long, long long, long long, long long, long long, long long>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<string, string, string, string, string, string>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<string, string, string, string, string, string>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<char, char, char, char, char, char>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<char, char, char, char, char, char>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<bool, bool, bool, bool, bool, bool>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<bool, bool, bool, bool, bool, bool>& t) {
	os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << " " << get<4>(t) << " " << get<5>(t);
	return os;
}

std::istream& operator>>(std::istream& is, tuple<int, int, int, int, int, int, int>& t) {
	is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t) >> get<6>(t);
	return is;
}

std::ostream& operator<<(std::ostream& os, const tuple<int, int, int, int, int, int,