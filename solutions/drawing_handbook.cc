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

int PageCount(const int n, const int p)
{
  if (p <= n - p)
  {
    return p / 2;
  }
  else
  {
    return (n / 2) - p / 2;
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

  int p = 0, n = 0;
  cin >> n >> p;
  cout << PageCount(n, p);

}

