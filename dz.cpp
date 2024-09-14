#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  int m, n;
  cout << "введите m ";
  cin >> m;
  cout << "введите n ";
  cin >> n;
  int a[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 21; 
    }
  }
  int sum = 0;
  int min = a[0][0];
  int max = a[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      sum += a[i][j];
      if (a[i][j] < min) {
        min = a[i][j];
      } 
      if (a[i][j] > max) {
        max = a[i][j];
      }
    }
  }
  cout << "сумма " << sum << "\n";
  cout << "среднее " << (double)sum / (m * n) << "\n";
  cout << "минимум " << min << "\n";
  cout << "максимум " << max << "\n";
  int b[m][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      b[i][j] = rand() % 21;
    }
  }
  int sum2 = 0;
  int sum3 = 0;
  for (int i = 0; i < m; i++) {
    sum2 += b[i][i];
    sum3 += b[i][m - i - 1];
  }
  cout << "сумма главной диагонали " << sum2 << "\n";
  cout << "сумма побочной диагонали " << sum3 << "\n";
  int c[m][n];
  int positive = 0;
  int negative = 0;
  int zero = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = rand() % 21 - 10;
      if (c[i][j] > 0) {
        positive++;
      } else if (c[i][j] < 0) {
        negative++;
      } else {
        zero++;
      }
    }
  }
  cout << "положительных " << positive << "\n";
  cout << "отрицательных " << negative << "\n";
  cout << "нулевых " << zero << "\n";
  int d[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = rand() % 21;
    }
  }
  for (int i = 0; i < m; i++) {
    int sum4 = 0;
    for (int j = 0; j < n; j++) {
      sum4 += d[i][j];
    }
    cout << "сумма строки " << i << " " << sum4 << "\n";
  }
  for (int j = 0; j < n; j++) {
    int sum5 = 0;
    for (int i = 0; i < m; i++) {
      sum5 += d[i][j];
    }
    cout << "сумма столбца " << j << " " << sum5 << "\n";
  }
  int e[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      e[i][j] = i * 10 + j; 
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << e[i][j] << " ";
    }
    cout << "\n";
  }
  int f[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      f[i][j] = rand() % 21; 
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0) {
        cout << f[i][j] << " ";
      }
    }
    cout << "\n";
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 != 0) {
        cout << f[i][j] << " ";
      }
    }
    cout << "\n";
  }
  int g[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = rand() % 201 - 100; 
    }
  }
  int min2 = g[0][0];
  int max2 = g[0][0];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] < min2) {
        min2 = g[i][j];
      }
      if (g[i][j] > max2) {
        max2 = g[i][j];
      }
    }
  }
  int sum6 = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] >= min2 && g[i][j] <= max2) {
        sum6 += g[i][j];
      }
    }
  }
  cout << "сумма " << sum6 << "\n";
  int h[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      h[i][j] = 0;
    }
  }
  int k = 1;
  int i = m / 2;
  int j = n / 2;
  h[i][j] = k;
  k++;
  while (k <= m * n) {
    for (int p = i - 1; p >= 0 && k <= m * n; p--) {
      h[p][j] = k;
      k++;
    }
    i--;
    for (int p = j + 1; p < n && k <= m * n; p++) {
      h[i][p] = k;
      k++;
    }
    j++;
    for (int p = i + 1; p < m && k <= m * n; p++) {
      h[p][j] = k;
      k++;
    }
    i++;
    for (int p = j - 1; p >= 0 && k <= m * n; p--) {
      h[i][p] = k;
      k++;
    }
    j--;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << h[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}