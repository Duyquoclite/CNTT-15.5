#include <stdio.h>

int a, b;

int main() {
  printf("Nhập phương trình bậc 1 (a, b): ");
  scanf("%d %d", &a, &b);
  if (!a || !b) {
    printf("vui lòng nhập đúng a, b là số");
    return 0;
  }
  if (a == 0 && b == 0) {
    printf("Phương trình vô số nghiệm");
  } else if (a == 0) {
    printf("Phương trình vô nghiệm");
  } else {
    printf("Phương trình có nghiệm %d", -b / a);
  }
}
