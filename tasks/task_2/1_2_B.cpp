#include <iostream>
#include <vector>

constexpr int cGroupSize = 5;
constexpr int cFirstMultiplier = 123;
constexpr int cSecondMultiplier = 45;
constexpr int cMod = 10004321;

void SortSmall(std::vector<int>& a, int l, int r) {
  for (int i = l + 1; i < r; ++i) {
    int x = a[i];
    int j = i - 1;
    while (j >= l && a[j] > x) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = x;
  }
}

void Swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int Pivot(std::vector<int>& a, int l, int r) {
  int cur = r;
  while (cur - l > cGroupSize) {
    int m = l;
    for (int i = l; i < cur; i += cGroupSize) {
      int end = i + cGroupSize;
      if (end > cur) {
        end = cur;
      }

      SortSmall(a, i, end);
      int med = (end + i) / 2;
      Swap(a[m], a[med]);
      ++m;
    }
    cur = m;
  }

  SortSmall(a, l, cur);
  return a[(cur + l) / 2];
}

int Select(std::vector<int>& a, int l, int r, int k) {
  while (r - l > cGroupSize) {
    int pivot = Pivot(a, l, r);
    int left = l;
    int i = l;
    int right = r;

    while (i < right) {
      if (a[i] < pivot) {
        Swap(a[i], a[left]);
        ++i;
        ++left;
      } else if (a[i] > pivot) {
        --right;
        Swap(a[i], a[right]);
      } else {
        ++i;
      }
    }

    if (k < left) {
      r = left;
    } else if (k >= right) {
      l = right;
    } else {
      return pivot;
    }
  }

  SortSmall(a, l, r);
  return a[k];
}

int main() {
  int n;
  int k;
  int x;
  int y;
  std::cin >> n >> k >> x >> y;

  std::vector<int> a(n);
  a[0] = x;
  if (n > 1) {
    a[1] = y;
  }
  for (int i = 2; i < n; ++i) {
    long long next = (static_cast<long long>(a[i - 1]) * cFirstMultiplier) +
                     (static_cast<long long>(a[i - 2]) * cSecondMultiplier);
    a[i] = static_cast<int>(next % cMod);
  }

  std::cout << Select(a, 0, n, k - 1) << '\n';
  return 0;
}
