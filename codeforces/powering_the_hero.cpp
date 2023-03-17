#include <iostream>
#include <queue>

using namespace std;

void answ(){
    int n;
    cin>>n;

    priority_queue<int> powers;
    long long out = 0;
    int a;
    while(n--){
        cin>>a;
        if(a)
            powers.push(a);
        else if(powers.size()){
            out+=powers.top();
            powers.pop();
        }
    }

    cout<<out<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        answ();
    }

    return 0;
}