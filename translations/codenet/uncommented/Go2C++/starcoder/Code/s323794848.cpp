#include <bits/stdc++.h>
using namespace std;

struct deque {
	deque() : front(), back() {}
	deque(deque const &d) : front(d.front), back(d.back) {}
	deque &operator=(deque const &d) {
		front = d.front;
		back = d.back;
		return *this;
	}
	deque(deque &&d) : front(move(d.front)), back(move(d.back)) {}
	deque &operator=(deque &&d) {
		front = move(d.front);
		back = move(d.back);
		return *this;
	}
	deque(string const &s) : front(), back() {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(string &&s) : front(), back() {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque const &d, string const &s) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque const &d, string &&s) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque &&d, string const &s) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque &&d, string &&s) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque const &d, deque const &s) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque const &d, deque &&s) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque &&d, deque const &s) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque &&d, deque &&s) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
	}
	deque(deque const &d, deque const &s, string const &t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque const &s, string &&t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque &&s, string const &t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque &&s, string &&t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque const &s, string const &t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque const &s, string &&t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque &&s, string const &t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque &&s, string &&t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque const &s, deque const &t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque const &s, deque &&t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque &&s, deque const &t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque &&s, deque &&t) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque const &s, deque const &t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque const &s, deque &&t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque &&s, deque const &t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque &&d, deque &&s, deque &&t) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
	}
	deque(deque const &d, deque const &s, deque const &t, string const &u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque const &s, deque const &t, string &&u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque const &s, deque &&t, string const &u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque const &s, deque &&t, string &&u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque &&s, deque const &t, string const &u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque &&s, deque const &t, string &&u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque &&s, deque &&t, string const &u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque &&s, deque &&t, string &&u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque const &s, deque const &t, string const &u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque const &s, deque const &t, string &&u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque const &s, deque &&t, string const &u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque const &s, deque &&t, string &&u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque &&s, deque const &t, string const &u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque &&s, deque const &t, string &&u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque &&s, deque &&t, string const &u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque &&d, deque &&s, deque &&t, string &&u) : front(move(d.front)), back(move(d.back)) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushBack(t[i]);
		}
		for (int i = 0; i < u.size(); i++) {
			pushBack(u[i]);
		}
	}
	deque(deque const &d, deque const &s, deque const &t, deque const &u) : front(d.front), back(d.back) {
		for (int i = 0; i < s.size(); i++) {
			pushBack(s[i]);
		}
		for (int i = 0; i < t.size(); i++) {
			pushB