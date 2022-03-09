#include <bits/stdc++.h>
using namespace std;

void fast_scan(int &number)
{
  bool negative = false;
  int c;
  number = 0;

  c = getchar();
  if (c == '-')
  {
    negative = true;
    c = getchar();
  }
  
  for (; (c > 47 && c < 58); c = getchar())
    number = number*10 + c - 48;

  if (negative)
    number *= -1;
}

int SockMerchant(const vector<int> &socks, const int n)
{
  map<int, int> pairs;
  int count = 0;

  for (auto sock : socks)
    ++pairs[sock];
  
  for_each (pairs.begin(), pairs.end(), [&count] (const pair<int, int> &sock) {
      count += sock.second / 2;
  });

  return count; 
}
int main()
{
#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0;
  cin >> n;
  vector<int> socks;

  for (int i = 0; i < n; ++i)
  {
    int value;
    cin >> value;
    socks.push_back(value);
  }

  cout << SockMerchant(socks, n);

}
