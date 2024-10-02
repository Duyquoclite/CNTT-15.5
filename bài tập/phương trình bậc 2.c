#include <math.h>
#include <stdio.h>

int a, b, c;

int main() {
  printf("Nhập a: ");
  scanf("%d", &a);
  printf("Nhập b: ");
  scanf("%d", &b);
  printf("Nhập c: ");
  scanf("%d", &c);
  if ((!a || !b || !c) && a!=0 && a!= 0 && a!= 0) {
    printf("vui lòng nhập đúng a, b là số");
    return 0;
  }
  if (a == 0) {
    if(b == 0) {
      if(c == 0) printf("Phương trình có vô số nghiệm");
      else printf("Phương trình không có nghiệm");
    }
  }
  int delta = b * b - 4 * a * c;
  double sqrt(double x);
  if (delta > 0)
    printf("Phương trình có 2 nghiệm phân biệt %.2f %.2f",
           (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
  if (delta == 0)
    printf("Phương trình có nghiệm kép %.2f", (float)-b / (2 * a));
  if (delta < 0)
    printf("Phương trình vô nghiệm");
}
