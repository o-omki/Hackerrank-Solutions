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

int MigratoryBirds(const vector<int> &birds, const int n)
{
  map<int, int> freq;
  for (auto i: birds)
    ++freq[i];

  auto highest = max_element(freq.begin(), freq.end(), [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
                            return a.second < b.second;});
  
  return highest->first;
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
  fast_scan(n);

  vector<int> birds;
  for (auto i = 0; i < n; ++i)
  {
    int value;
    fast_scan(value);
    birds.push_back(value);
  }
  cout << MigratoryBirds(birds, n);
}
