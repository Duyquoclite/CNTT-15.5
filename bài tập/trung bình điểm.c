#include <stdio.h>

float a, b, c;

int main() {
  printf("Nhập điểm toán: ");
  scanf("%f", &a);
  printf("Nhập điểm lý: ");
  scanf("%f", &b);
  printf("Nhập điểm hóa: ");
  scanf("%f", &c);
  if (a > 10 || a < 0 || b > 10 && b < 0 || c > 10 || c < 0)
    return printf("Nhập đúng số điểm");
  printf("\nĐiểm trung bình: %.2f", (float) (a + b + c) / 3);
}
