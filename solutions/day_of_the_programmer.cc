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

class Solution
{
  int year;
  int temp = 215;

  public:
  Solution(const int &year)
  {
    this->year = year;
  }

  void ComputeDate()
  {
    int feb_days = 0;
    if (year < 1918)
    {
      feb_days = !(year % 4) ? 29 : 28;
    }
    else if (year > 1918)
      feb_days = ((!(year % 4) && (year % 100)) || !(year % 400)) ? 29 : 28;
    
    else
      feb_days = 15;
    
    cout << to_string(256 - temp - feb_days) << ".09." << year;
  }
};

int main()
{
#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int year;
  cin >> year;
  Solution obj(year);
  obj.ComputeDate();  
}

