#include <iostream>
#include <cstring>

using namespace std;

int dp[252][1001];

int input[1000002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n=1 , max =0;
  while(cin >> input[n]) n++;
  

  memset(dp, 0, sizeof(dp));

  dp[1][1] = 1;
  dp[2][1] = 3;

  int to_up = 0;

  for(int i =3 ; i<=250; i++){
    for(int j =1;j<=1000; j ++){
      dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i-2][j]*2;
      to_up = dp[i][j] /10;
      dp[i][j+1] += to_up;
      dp[i][j] = dp[i][j] % 10;
    }
    
  }

  int check =0;

  for(int i =1; i<=n; i++){
    check = 0;
    if(input[i] == 0) cout << 0;
    else{
      for(int j =1000; j>0; j--){
        if(dp[input[i]][j] == 0 && check == 0){
          continue;
        }
        else{
          check =1;
          cout << dp[input[i]][j];
        }
      }
    }
    
    
    cout <<endl;
  }
  return 0;
}