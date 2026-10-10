#include <cstdint>
#include <iostream>
#include <vector>

constexpr int cBits = 8;
constexpr int cBytes = 8;
constexpr int cBase = 1 << cBits;
constexpr std::uint64_t cMask = cBase - 1;

int Byte(std::uint64_t x, int b) {
  return static_cast<int>((x >> (cBits * b)) & cMask);
}

void Sort(std::vector<std::uint64_t>& a) {
  int n = static_cast<int>(a.size());

  for (int b = 0; b < cBytes; ++b) {
    std::vector<std::vector<std::uint64_t>> v(cBase);
    for (int i = 0; i < n; ++i) {
      int d = Byte(a[i], b);
      v[d].push_back(a[i]);
    }

    int j = 0;
    for (int d = 0; d < cBase; ++d) {
      int m = static_cast<int>(v[d].size());
      for (int i = 0; i < m; ++i) {
        a[j] = v[d][i];
        ++j;
      }
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::uint64_t> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  Sort(a);

  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
