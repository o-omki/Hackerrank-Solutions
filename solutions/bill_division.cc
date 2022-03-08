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

void BonAppetit(const vector<int> &prices, const int n, const int k, const int b)
{
  int charge = 0;
  for (int i = 0; i < n; ++i)
  {
    if (i == k)
      continue;
    
    charge += prices[i];
  }

  charge /= 2;

  if (b > charge)
  {
    cout << b - charge;
  }
  else
  {
    cout << "Bon Appetit";
  }
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

  vector<int> prices;
  for (auto i = 0; i < n; ++i)
  {
    int value;
    cin >> value;
    prices.push_back(value);
  }
  
  int b = 0;
  cin >> b;

  BonAppetit(prices, n, k, b);
}

