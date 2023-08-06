#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int UPPER_BOUND; 
// Precompute: primeTable[i] == true: i is prime
// O(loglog(UPPER_BOUND))
void generate_primeTable( vector<bool> &primeTable ){ 
    primeTable[0] = primeTable[1] = false;
    for(int i = 2; i < UPPER_BOUND; ++i){
        for(int j = i * i; j <= UPPER_BOUND; j += i){
            primeTable[j] = false;
        }
    }
}

// return shorter or smaller string
// O(1)
string minstring( string s1, string s2){
    if(s1.length() != s2.length()){
        return s1.length() > s2.length() ? s2 : s1;
    }
    else{
        return s1 > s2 ? s2 : s1;
    }
}

// apply dynamic programming to solve the problem
// return the required string
// O(UPPER_BOUND) = O(n)
string shortestAnswerString(int n, vector<bool> &primeTable) {
    map <int, string> dp;
    string ans((UPPER_BOUND - n), '1');
    // is true if we can find a prime less than UPPER_BOUND
    bool flag = false;

    // initialization
    for( int i = 1 ; i <= n ; i++ ){
        string s(i, '1');    
        dp[n+i] = s;
    }
    dp[2*n+1] = "0";

    // calculation
    for(int i = 2*n+2; i <= UPPER_BOUND; ++i){
        // i is even
        if( i % 2 == 0 ) dp[i] = "1" + dp[i-1]; 
        // i is odd
        else dp[i] = minstring("0" + dp[(i-1)/2], "1" + dp[i-1]);
    }

    // find the answer string
    for(int i = n + 1; i < UPPER_BOUND; ++i){
        if(primeTable[i]){
            flag = true;
            // cout << i << ":" << " " << dp[i] << endl;
            ans = minstring(ans, dp[i]);
        }
    }
    if(!flag) ans = "-";
    return ans;
}


int main(){
    int n;  //input integer
    cin >> n;
    // UPPER_BOUND is related to n
    UPPER_BOUND = 5 * n; 

    vector<bool> primeTable(UPPER_BOUND + 1, true);
    generate_primeTable(primeTable);
    
    if(primeTable[n]) cout << "" << endl;
    else cout << shortestAnswerString(n, primeTable) << endl;

    return 0;
}
