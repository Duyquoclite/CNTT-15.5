/*
Dương Thanh Tú:
Viết cấu trúc Node, hàm tạo node, hàm tạo danh sách liên kết vòng (10.1)
Viết hàm in danh sách, menu chính và main
Hoàng Văn Hải:
Viết hàm kiểm tra số nguyên tố và in vị trí (10.2)
Viết hàm xóa phần tử vị trí 5 nếu là 0 (10.3)
Viết hàm xóa tất cả số âm (10.4)
Ngô Hữu Chinh:
Viết hàm sắp xếp danh sách tăng dần (10.5)
Viết hàm sắp xếp số âm giảm dần trước, số dương tăng dần sau (10.6)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* taoNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void taoDanhSach() {
    int n, x;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    
    head = NULL;
    Node* last = NULL;
    
    for(int i = 1; i <= n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &x);
        Node* p = taoNode(x);
        
        if(head == NULL) {
            head = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }
    
    if(last != NULL) {
        last->next = head;
    }
    printf("Tao danh sach thanh cong!\n");
}

void inDanhSach() {
    if(head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* p = head;
    printf("Danh sach: ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p != head);
    printf("\n");
}

int laSoNguyenTo(int n) {
    if(n < 2) return 0;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void kiemTraSoNguyenTo() {
    if(head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    Node* p = head;
    int viTri = 1;
    int co = 0;
    
    do {
        if(laSoNguyenTo(p->data)) {
            printf("So nguyen to %d o vi tri %d\n", p->data, viTri);
            co = 1;
        }
        p = p->next;
        viTri++;
    } while(p != head);
    
    if(!co) printf("Khong co so nguyen to nao trong danh sach.\n");
}

void xoaViTri5NeuLa0() {
    if(head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    Node* p = head;
    Node* truoc = NULL;
    int viTri = 1;
    
    do {
        if(viTri == 5) break;
        truoc = p;
        p = p->next;
        viTri++;
    } while(p != head && viTri <= 5);
    
    if(viTri != 5) {
        printf("Danh sach khong du 5 phan tu.\n");
        return;
    }
    
    if(p->data != 0) {
        printf("Phan tu o vi tri 5 khong phai la 0.\n");
        return;
    }
    
    if(p == head && p->next == head) {
        free(p);
        head = NULL;
    } else if(p == head) {
        Node* last = head;
        while(last->next != head) last = last->next;
        last->next = head->next;
        head = head->next;
        free(p);
    } else {
        truoc->next = p->next;
        free(p);
    }
    printf("Da xoa phan tu 0 o vi tri 5.\n");
}

void xoaTatCaSoAm() {
    if(head == NULL) return;
    
    Node* p = head;
    Node* truoc = NULL;
    Node* temp;
    
    Node* last = head;
    while(last->next != head) last = last->next;
    
    int daXoa = 0;
    
    do {
        if(p->data < 0) {
            temp = p;
            if(p == head) {
                if(head->next == head) {
                    free(head);
                    head = NULL;
                    return;
                }
                last->next = head->next;
                head = head->next;
                p = head;
            } else {
                truoc->next = p->next;
                p = p->next;
            }
            free(temp);
            daXoa = 1;
        } else {
            truoc = p;
            p = p->next;
        }
    } while(p != head && head != NULL);
    
    if(daXoa) printf("Da xoa tat ca so am.\n");
    else printf("Khong co so am nao de xoa.\n");
}

void sapXepTangDan() {
    if(head == NULL || head->next == head) return;
    
    int swapped;
    Node* p;
    Node* last = NULL;
    
    do {
        swapped = 0;
        p = head;
        
        do {
            if(p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        } while(p->next != head && p->next != last);
        
        last = p;
        
    } while(swapped);
    
    printf("Da sap xep tang dan.\n");
}

void sapXepAmGiamDuongTang() {
    if(head == NULL) return;
    
    Node* p = head;
    Node* dsAm = NULL;
    Node* lastAm = NULL;
    Node* dsDuong = NULL;
    Node* lastDuong = NULL;
    
    do {
        Node* temp = p;
        p = p->next;
        
        if(temp->data < 0) {
            temp->next = NULL;
            if(dsAm == NULL) {
                dsAm = temp;
                lastAm = temp;
            } else {
                lastAm->next = temp;
                lastAm = temp;
            }
        } else {
            temp->next = NULL;
            if(dsDuong == NULL) {
                dsDuong = temp;
                lastDuong = temp;
            } else {
                lastDuong->next = temp;
                lastDuong = temp;
            }
        }
    } while(p != head);
    
    if(dsAm != NULL && dsAm->next != NULL) {
        int swapped;
        Node* ptr;
        do {
            swapped = 0;
            ptr = dsAm;
            while(ptr->next != NULL) {
                if(ptr->data < ptr->next->data) {
                    int t = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = t;
                    swapped = 1;
                }
                ptr = ptr->next;
            }
        } while(swapped);
    }
    
    if(dsDuong != NULL && dsDuong->next != NULL) {
        int swapped;
        Node* ptr;
        do {
            swapped = 0;
            ptr = dsDuong;
            while(ptr->next != NULL) {
                if(ptr->data > ptr->next->data) {
                    int t = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = t;
                    swapped = 1;
                }
                ptr = ptr->next;
            }
        } while(swapped);
    }
    
    if(dsAm == NULL) {
        head = dsDuong;
    } else {
        head = dsAm;
        lastAm->next = dsDuong;
    }
    
    if(head != NULL) {
        if(dsDuong == NULL) {
            lastAm->next = head;
        } else {
            lastDuong->next = head;
        }
    }
    
    printf("Da sap xep: so am giam dan truoc, so duong tang dan sau.\n");
}

void menu() {
    int chon;
    do {
        system("cls");
        printf("\n=== DANH SACH LIEN KET VONG - QUAN LY SO NGUYEN ===\n");
        printf("1. Tao danh sach\n");
        printf("2. Kiem tra so nguyen to va vi tri\n");
        printf("3. Xoa phan tu o vi tri 5 neu la 0\n");
        printf("4. Xoa tat ca so am\n");
        printf("5. Sap xep tang dan\n");
        printf("6. Sap xep: am giam dan truoc, duong tang dan sau\n");
        printf("7. In danh sach\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        
        switch(chon) {
            case 1: taoDanhSach(); break;
            case 2: kiemTraSoNguyenTo(); break;
            case 3: xoaViTri5NeuLa0(); break;
            case 4: xoaTatCaSoAm(); break;
            case 5: sapXepTangDan(); break;
            case 6: sapXepAmGiamDuongTang(); break;
            case 7: inDanhSach(); break;
            case 0: printf("Tam biet!\n"); break;
            default: printf("Chuc nang khong hop le!\n");
        }
        if(chon != 0) {
            printf("\nNhan phim bat ky de tiep tuc...");
            getch();
        }
    } while(chon != 0);
}

int main() {
    menu();
    return 0;
}
