#include <stdio.h>

int a;

int main() {
  printf("Nhập năm sinh: ");
  scanf("%d", &a);
  if(!a) printf("Vui lòng nhập đúng năm sinh");
  else {
    int tuoi = 2024 - a;
    printf("Tuổi của bạn là: %d", tuoi);
  }
}
