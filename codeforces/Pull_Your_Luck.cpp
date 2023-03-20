#include <iostream>

using namespace std;

int min(int a, int b){
    return ((a<b)?a:b);
}

void answ(){
    int n, x, p;
    cin>>n>>x>>p;

    p = min(p, 2*n);

    long long k = x;
    bool possible = false;
    for(int i = 1; i<=p&&!possible; i++){
        k+=i;
        if(k%n==0) possible = true;
    }

    cout<<((possible)?"YES":"NO")<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        answ();
    }

    return 0;
}