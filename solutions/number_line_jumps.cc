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

string Possible(const int x1, const int x2, const int v1, const int v2)
{
  if (v2 < v1)
    if ((x2 - x1) % (v1 - v2) == 0)
      return "YES";
  
  return "NO";
}

int main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif  

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1 = 0, x2 = 0, v1 = 0, v2 = 0;
    cin >> x1 >> v1 >> x2 >> v2;
    
    cout << Possible(x1, x2, v1, v2);
}

