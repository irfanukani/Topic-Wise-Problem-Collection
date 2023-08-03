/*
 * Problem Link : https://atcoder.jp/contests/abc312/tasks/abc312_c
 * Topics : Binary Search , Implementation
 */

#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)



class Solution {
	private:
	bool check(vector<int> a , vector<int> b, long x) {
		int sellers = 0 , buyers = 0;
		for(auto i : a) {
			sellers += (x >= i);
		}
		for(auto i : b) {
			buyers += (x <= i);
		}
		
		return sellers >= buyers;
	}
	
	public:
	long invisibleHand(int n, int m, vector<int> a, vector<int> b) {
		long left = 0, right = 10000000000, answer = 0;
		while(left <= right) {
			long mid = (left + right) / 2;
			if(check(a , b , mid)) {
				answer = mid;
				right = mid - 1;
			}else {
				left = mid + 1;
			}
		}
		
		return answer;
	}
	
};


int main()
{
    fastio();
    
    int n , m;
    cin >> n >> m;
    
    vector<int> a(n , 0);
    vector<int> b(m , 0);
    
    for(auto &x : a) {
		cin>>x;
	}
	
	for(auto &x : b){
		cin>>x;
	}
	
	Solution solution;
	cout << solution.invisibleHand(n , m , a , b) << "\n";

    return 0;
}
