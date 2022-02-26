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

void CountDrops(const vector<int> &apples, const vector<int> oranges, const int s, const int t, const int a, const int b)
{
  int apple_count = 0, orange_count = 0;
  for (auto &apple: apples)
    if (a + apple >= s && a + apple <= t)
      ++apple_count;

  for (auto &orange: oranges)
    if (b + orange <= t && b + orange >= s)
      ++orange_count;

  cout << apple_count << "\n" << orange_count;

}
int main()
{
#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int s = 0, t = 0, a = 0, b = 0, m = 0 , n = 0;
  cin >> s >> t;
  cin >> a >> b;
  cin >> m >> n;

  vector<int> apples;
  vector<int> oranges;

  for (auto i = 0; i < m; ++i)
  {
    int dist;
    cin >> dist;
    apples.push_back(dist);
  }

  for (auto i = 0; i < n; ++i)
  {
    int dist;
    cin >> dist;
    oranges.push_back(dist);
  }

  CountDrops(apples, oranges, s, t, a, b);

}

