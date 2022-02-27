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

vector<int> BreakingRecords(const vector<int> &scores, const int num_scores)
{
  vector<int> records(2);

  int low = scores[0], high = scores[0];
  for (auto score : scores)
  {
    if (score < low)
    {
      low = score;
      ++records[1];
    }

    if (score > high)
    {
      high = score;
      ++records[0];

    }
  }

  return records;
}

int main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<int> scores;
    for (auto i = 0; i <= n; ++i)
    {
      int value;
      cin >> value;
      scores.push_back(value);
    }

  vector<int> records = BreakingRecords(scores, n);

  for (auto record: records)
  {
    cout << record << " ";
  }
}

