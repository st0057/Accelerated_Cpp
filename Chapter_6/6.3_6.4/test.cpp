#include <algorithm>
#include <vector>

using std::vector;

int main()
{
  vector<int> u(10, 1);
  vector<int> v(10);

  std::copy(u.begin(), u.end(), v.begin());

  return 0;
}