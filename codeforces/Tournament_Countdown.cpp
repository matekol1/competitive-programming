#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
set<int> sq;
 
int getPow(int a) {
	if (a == 0) return 1;
	if (a == 1) return 2;
	int tmp = getPow(a / 2);
	tmp *= tmp;
	if (a % 2) tmp *= 2;
	return tmp;
}
 
int whichIsBigger(int a, int b) {
	int out = 0;
	cout << "? " << a << " " << b<<endl;
	cout.flush();
	cin >> out;
	if (out == 1) return a;
	if (out == 2) return b;
 
	return -1;
}
 
int winners(int s, int e) {
	if (s == e) return s;
 
	int difference = (e - s + 1) / 4;
	int tmp1 = winners(s, s + difference - 1);
	int tmp2 = winners(s + difference, s + difference * 2 - 1);
	int tmp3 = winners(s + difference * 2, s + difference * 3 - 1);
	int tmp4 = winners(s + difference * 3, s + difference * 4 - 1);
 
	int b = whichIsBigger(tmp1, tmp3);
 
	if (b == tmp1) {
		b = whichIsBigger(tmp1, tmp4);
		return b;
	}
	else if (b == tmp3) {
		b = whichIsBigger(tmp2, tmp3);
		return b;
	}
	b = whichIsBigger(tmp2, tmp4);
	return b;
 
}
 
int main() {
	int t;
	cin >> t;
 
	//int* tab = new int[100000]{0};
	int n;
 
	for (int ik = 0; ik < t; ik++) {
		cin >> n;
		if (n % 2) {
			n --;
			int a = winners(1, getPow(n));
			int b = winners(getPow(n)+1, getPow(n+1));
 
			int c = whichIsBigger(a, b);
			cout << "! " << c << endl;
		}
		else {
			int best = winners(1, getPow(n));
			cout << "! " << best;
		}
		cout << endl;
		cout.flush();
	}
	return 0;
}