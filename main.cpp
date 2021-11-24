#include    <bits/stdc++.h>
#define     int             long long
#define     mod             (int)(1e9 + 7)
#define     ln              "\n"
#define     spc             " "

using namespace std;

inline int factorCeil(int a, int b);

inline int logPower(int x, int y);

inline int binaryToDecimal(string num);

inline void Sieve(int n);

string solve()
{

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);



#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        int maxm = INT_MIN;

        for(int i=1;i<=n;i++){
            if(v[i]>i)
            maxm = max(maxm,v[i]-i);
        }


        if(maxm==INT_MIN){
            cout<<0<<ln;
        }
        else{
            cout<<maxm<<ln;
        }
    }
    return 0;
}


inline void Sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

inline int binaryToDecimal(string num)
{
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}


inline int factorCeil(int a, int b)
{
    return (a + b - 1)/b;
}

inline int logPower(int x, int y)
{
    int res = 1;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x);

        y = y>>1; // y = y/2
        x = (x*x);
    }
    return res;
}