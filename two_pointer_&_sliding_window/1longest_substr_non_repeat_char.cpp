// Question Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
    Revising on 10 July, 2025
    1. I tried t solve this question again, and got the idea of using the map on first instinct, as we can store the idx number and char in map. 
    2. But, I overcomplicated things after this step, as I started to go deeper into techniques, nstead of staying focused on main problem. So, I need to first explore my intution deeply then recognise the mistakes and then go for correcting them.
    3. I have little patience for revision, like solving the questions that I have already one, and this is bad, I cna see.

    4. Now, I checked my Approach1 and Approach2 which I have done earlier, and I can't seem to comprehend why I used set, necause using map was definetely much much efficient. So, my thinking has evolved somewhat.
*/

// Finally submitted after 7 submissions (crying face)
class Approach3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0, j=i, maxx=0, n=s.length();

        if(s.length()==0)   return 0;

        while(i<n && j<n) {
            if(mp.find(s[j])!=mp.end()) {
                // present
                if(i<mp[s[j]]+1) {
                    i=mp[s[j]]+1;
                }
            } 

            mp[s[j]]=j;
            maxx=max(j-i+1, maxx);
            j++;
            cout<<i<<"  "<<j<<"  "<<maxx<<endl;
        }

        return maxx;
    }
};


class Approach1 {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st; int maxx=0, n=s.length();

        if(s.length()==0)   return 0;

        for(int i=0; i<n; i++) {
            st={};
            for(int j=i; j<n; j++) {
                if(st.find(s[j])!=st.end()) {
                    maxx = max(j-i, maxx);
                    break;
                } 
                st.insert(s[j]);
            }
        }

        return maxx;
    }
};

// I think number of operations in approach1 and approach 2 are going to be same
class Approach2 {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st; int maxx=0, n=s.length(), i=0, j=0;

        if(s.length()==0)   return 0;

        while(i<n) {
            if(j>=n) {
                i++; j=i;
            }
            else if(st.find(s[j])!=st.end()) {
                i++; j=i; st={}; 
            } else {
                st.insert(s[j]);
                j++;
            } 
            maxx = max(j-i, maxx);
            cout<<i<<"  "<<j<<"  "<<maxx<<endl;
        }

        return maxx;
    }
};
