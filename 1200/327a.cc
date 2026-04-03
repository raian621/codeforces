// https://codeforces.com/problemset/problem/327/A

#include <iostream>
#include <vector>

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<int> prefix(n + 1, 0); // count of 1s in range [0, i]

    for (int i = 0; i < n; i++) {
      std::cin >> prefix[i + 1];
      if (i > 0) {
        prefix[i + 1] += prefix[i];
      }
    }

    int originalOnesCount = prefix.back();
    int maxOnes = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int onesInRange = prefix[j + 1] - prefix[i];
        int zerosInRange = j - i + 1 - onesInRange;

        maxOnes =
            std::max(maxOnes, originalOnesCount + (zerosInRange - onesInRange));
      }
    }

    std::cout << maxOnes << '\n';
  }
}
