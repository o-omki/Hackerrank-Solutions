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

int CountPairs(vector<int> &arr, const int n, const int k)
{
  vector<int> freq(k);

  int count = 0;
  for (auto i: arr)
    ++freq[i % k];

  count += freq[0] * (freq[0] - 1) / 2;

  for (auto i = 1; i <= k / 2 && i != k - i; ++i)
    count += freq[i] * freq[k - 1];
  
  if (k % 2 == 0)
    count += (freq[k / 2] * (freq[k / 2] - 1)) / 2;
  
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

  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> arr;
  for (auto i = 0; i < n; ++i)
  {
    int value;
    fast_scan(value);   
    arr.push_back(value);
  }
  cout << CountPairs(arr, n, k);
}

