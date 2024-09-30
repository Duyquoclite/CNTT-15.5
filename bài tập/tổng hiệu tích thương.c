#include <stdio.h>

int a, b;
int main() {
  printf("Nhập (a, b): ");
  scanf("%d %d", &a, &b);
  if (!a || !b) {
    printf("vui lòng nhập đúng a, b là số");
    return 0;
  }
  printf("Tổng: %d\nHiệu: %d\nTích: %d\nThương: %.2f", a + b, a - b, a * b,
         (float)a / b);
}
