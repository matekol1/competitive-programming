#include <iostream>

using namespace std;

void answ() {
    int n, k;
    cin >> n >> k;

    long long out = 0;

    long long* halvesSum = new long long[n + 1] {0};
    long long* prefixSum = new long long[n + 1] {0};
    int* nums = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        prefixSum[i + 1] = prefixSum[i] + nums[i] - k;
    }

    long long tmp;
    for (int i = n - 1; i >= 0; i--) {
        tmp = 0;
        for (int j = i; j < n && j <= i + 30; j++) {
            nums[j] /= 2;
            tmp += nums[j];
        }
        halvesSum[i] = tmp;
    }
    long long max = 0;
    for (int i = 0; i <= n; i++) {
        tmp = prefixSum[i];
        if (i != n) tmp += halvesSum[i];
        if (tmp > max) max = tmp;
    }
    cout << max << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        answ();
    }

    return 0;
}