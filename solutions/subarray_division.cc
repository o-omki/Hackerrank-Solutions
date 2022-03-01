#include <bits/stdc++.h>
using namespace std;

void fast_scan(int &number)
{
  bool negative = false;
  int c;
  number = 0;

  c = getchar_unlocked();
  if (c == '-')
  {
    negative = true;
    c = getchar_unlocked();
  }
  
  for (; (c > 47 && c < 58); c = getchar_unlocked())
    number = number*10 + c - 48;

  if (negative)
    number *= -1;
}

int GetWays(vector<int> squares, const int days, const int month)
{
  int total_squares = squares.size();

  if (total_squares < month)
    return 0;

  int count = 0;
  int sum = 0;
  for (auto i = 0; i < month; ++i)
    sum += squares[i];
  
  if (sum == days)
    ++count;
  
  for (auto i = month; i < total_squares; ++i)
  {
    sum += squares[i] - squares[i - month] ;
    if (sum == days)
      ++count;
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

    int num_squares = 0;
    int day = 0, month = 0;
    fast_scan(num_squares);

    vector<int> squares(num_squares);

    for (auto i = 0; i < num_squares; ++i)
    {
      int value;
      fast_scan(value);
      squares[i] = value;
    }

    fast_scan(day);
    fast_scan(month);

    cout << GetWays(squares, day, month);
}