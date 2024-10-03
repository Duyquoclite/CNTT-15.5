#include <stdio.h>

float a;

int main() {
  printf("Nhập bán kính: ");
  scanf("%f", &a);
  if (!a)
    return printf("Phải là một con số");
  printf("Diện tích hình tròn là %.2f\nChu vi hình tròn là: %.2f", a * a * 3.14, a * 2 * 3.14);
}
