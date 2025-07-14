// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st; 
    vector<int> res(n);
    
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()) res[i]=-1;
        else res[i]=st.top();

        st.push(arr[i]);
    }

    return res;
}