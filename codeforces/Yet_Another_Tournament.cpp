#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
	int t;
	cin >> t;
 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nums;
	int n, a;
	int csum = 0;
	int b = 0, m;
	int** out;
	int x, y;
	int cn;
	int cm;
	int d;
	int* needed;
	priority_queue<int> tmp;
	while (t--) {
		cin >> n>>m;
		d = 0;
		needed = new int[n];
		nums = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
		tmp = priority_queue<int>();
		for (int i = 0; i < n; i++) {
			cin >> a;
			needed[i] = a;
			nums.push({ a, i });
		}
 
		while (nums.size()&&m >= nums.top().first) {
			d++;
			m -= nums.top().first;
			tmp.push(nums.top().first);
			needed[nums.top().second] = -1;
			nums.pop();
		}
 
		if ((d<n&&d>0&&needed[d] <= tmp.top() + m)) {
			cout << n - d << endl;
		} else{
			cout << n - (d-1) << endl;
		}
	}
	return 0;
}