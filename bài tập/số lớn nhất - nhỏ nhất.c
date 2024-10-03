#include <stdio.h>

float a, b;

int main() {
  printf("Nhập a: ");
  scanf("%f", &a);
  printf("Nhập b: ");
  scanf("%f", &b);
  if (!a || !b)
    return printf("Phải là một con số");
  float x = a > b ? a : b;
  printf("Số lớn nhất là %.1f\nSố nhỏ nhất là %.1f", x, x == a ? b : a);
}
