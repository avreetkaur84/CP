// Question Link - https://codeforces.com/problemset/problem/1899/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;

    if(n%3==0)  cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }
}