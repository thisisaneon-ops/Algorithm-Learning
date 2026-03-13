#include<iostream>
#include<vector>
using namespace std;
void Adjust(vector<int>& v) {
	int even = 0;
	int odd = 1;
	while (odd < v.size() && even < v.size()) {
		if (v[v.size() - 1] % 2 == 0) {
			swap(v[even], v[v.size() - 1]);
			even += 2;
		}
		else {
			swap(v[odd], v[v.size() - 1]);
			odd += 2;
		}
	}
}
void showArray(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
int main() {
	vector<int>v;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 10 + 1);
	}
	showArray(v);
	Adjust(v);
	showArray(v);
	return 0;
}
