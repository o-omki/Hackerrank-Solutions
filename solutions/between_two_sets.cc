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
    number = number * 10 + c - 48;

  if (negative)
    number *= -1;
}

int ValidIntegers(const set<int, greater<int>> &arr1, const set<int, greater<int>> &arr2)
{
  size_t count = 0;

  auto min = *(arr1.cbegin());
  auto max = *(arr2.cbegin());

  for (auto val = min; val <= max; ++val)
  {
    bool flag1 = true, flag2 = true;

    for (auto x: arr1)
      if (val % x != 0)
      {
        flag1 = false;
        break;
      }
    
    if (flag1)
    {
      for (auto x: arr2)
        if (x % val != 0)
        {
          flag2 = false;
          break;
        }
      
      if (flag2)
        ++count;
    }
  }

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

  int n = 0, m = 0;
  cin >> n >> m;

  set<int, greater<int>> arr1, arr2;

  for (auto i = 0; i < n; ++i)
  {
    int value;
    cin >> value;
    arr1.insert(value);
  }

  for (auto i = 0; i < m; ++i)
  {
    int value;
    cin >> value;
    arr2.insert(value);
  }

  cout << ValidIntegers(arr1, arr2);
}
