#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> dp(n, 1), pointer(primes.size());
    for (int i = 1; i < n; i++)
    {
        int cur = INT_MAX;
        for (int j = 0; j < primes.size(); j++) cur = min(cur, dp[pointer[j]] * primes[j]);
        dp[i] = cur;
        for (int j = 0; j < primes.size(); j++) if (cur == dp[pointer[j]] * primes[j]) ++pointer[j];
    }
    return dp.back();
}

int main(){
    int n, num, temp;
    vector<int> primes;
    cin>>n>>num;
    for(int i=0;i<num;i++){
        cin>>temp;
        primes.push_back(temp);
    }
    cout<<nthSuperUglyNumber(n,primes)<<endl;
    return 0;
}

//Fix
