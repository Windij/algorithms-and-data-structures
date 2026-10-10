#include <cmath>
#include <iostream>
#include <vector>

int main() {
  const int cPrecision = 10;
  const int cZero = 0;
  int num;
  std::cin >> num;
  std::vector<double> a(num);
  for (int i = 0; i < num; i++) {
    double next;
    std::cin >> next;
    a[i] = log(next);
  }
  int query;
  std::cin >> query;

  std::vector<double> summs(num + 1);
  summs[0] = cZero;
  for (int i = 0; i < num; i++) {
    summs[i + 1] = summs[i] + a[i];
  }
  std::cout << std::fixed;
  std::cout.precision(cPrecision);
  int l;
  int r;
  for (int i = 0; i < query; i++) {
    std::cin >> l >> r;
    std::cout << exp((summs[r + 1] - summs[l]) / (r - l + 1)) << '\n';
  }
  return 0;
}
