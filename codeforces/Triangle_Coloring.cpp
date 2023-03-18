#include <iostream>

using namespace std;

const int mod = 998244353;

int binomialCoefficients(int n, int k) {
    int* pf = new int[n+1]{0};

    int tmp = 0;
    for(int i = k+1; i<=n; i++){
        tmp = i;
        for(int j = 2; j*j<=i; j++){
            while(tmp!=1&&tmp%j==0){
                pf[j]++;
                tmp/=j;
            }
        }
        if(tmp>1) pf[tmp]++;
    }

    for(int i = 1; i<=n-k; i++){
        tmp = i;
        for(int j = 2; j*j<=i; j++){
            while(tmp!=1&&tmp%j==0){
                pf[j]--;
                tmp/=j;
            }
        }
        if(tmp>1) pf[tmp]--;
    }

    long long out = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<pf[i]; j++){
            out*=i;
            out%=mod;
        }
    }

    return (int)out;
}

int main(){
    int n;

    cin>>n;
    int a, b, c, v1, v2, v3, tmp = 1;
    long long val = 1;
    for(int i = 0; i<n; i+=3){
        tmp = 1;
        cin>>a>>b>>c;

        v1 = a+b;
        v2 = a+c;
        v3 = b+c;

        if(v1<v2){
            swap(v1, v2);        
        }if(v1<v3){
            swap(v1, v3);
        }

        if(v2==v1) tmp++;
        if(v3==v1) tmp++;

        val*=tmp;
        val%=mod;
    }

    val*=binomialCoefficients(n/3,n/6);
    val%=mod;

    cout<<val;

    return 0;
}