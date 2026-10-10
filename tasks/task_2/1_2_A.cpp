#include <iostream>
#include <vector>

void Merge(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& tmp,
           int l, int m, int r) {
  int i = l;
  int j = m;

  for (int k = l; k < r; ++k) {
    if (j == r || (i < m && a[i][0] <= a[j][0])) {
      tmp[k] = a[i];
      ++i;
    } else {
      tmp[k] = a[j];
      ++j;
    }
  }

  for (int k = l; k < r; ++k) {
    a[k] = tmp[k];
  }
}

void MergeSort(std::vector<std::vector<int>>& a,
               std::vector<std::vector<int>>& tmp, int l, int r) {
  if (r - l <= 1) {
    return;
  }

  int m = (r + l) / 2;
  MergeSort(a, tmp, l, m);
  MergeSort(a, tmp, m, r);
  Merge(a, tmp, l, m, r);
}

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<std::vector<int>> a(n, std::vector<int>(2));
  for (std::vector<int>& seg : a) {
    std::cin >> seg[0] >> seg[1];
  }

  std::vector<std::vector<int>> tmp = a;
  MergeSort(a, tmp, 0, n);

  std::vector<std::vector<int>> ans;
  int m = 0;
  for (std::vector<int>& seg : a) {
    if (m == 0 || seg[0] > ans[m - 1][1]) {
      ans.push_back(seg);
      ++m;
    } else if (seg[1] > ans[m - 1][1]) {
      ans[m - 1][1] = seg[1];
    }
  }

  std::cout << ans.size() << '\n';
  for (const std::vector<int>& seg : ans) {
    std::cout << seg[0] << ' ' << seg[1] << '\n';
  }
}
