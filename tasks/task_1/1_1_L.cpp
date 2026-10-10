#include <iostream>
#include <string>
#include <vector>

bool Check(const std::string& s, const std::string& t,
           const std::vector<int>& del, int q) {
  int j = 0;
  int len_t = static_cast<int>(t.size());
  int len_s = static_cast<int>(s.size());
  for (int i = 0; i < len_s; ++i) {
    if (del[i] > q && s[i] == t[j]) {
      ++j;
      if (j == len_t) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  std::string s;
  std::string t;
  std::cin >> s >> t;

  int n = static_cast<int>(s.size());
  std::vector<int> del(n);
  for (int i = 1; i <= n; ++i) {
    int pos;
    std::cin >> pos;
    del[pos - 1] = i;
  }

  int l = 0;
  int r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Check(s, t, del, mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  std::cout << l - 1 << '\n';
  return 0;
}
