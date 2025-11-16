#include <stdio.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

char arr[100][100];
int n = 0;

void menu();
void nhapMang();
void inMang();
void themPT();
void suaPT();
void xoaPT();

int main() {
    int choice;

    do {
        menu();
        printf(CYAN ">> Nhap lua chon: " RESET);
        scanf("%d", &choice);
        getchar();

        if (choice != 1 && choice != 0 && n == 0) {
            printf(RED "\nBan phai chon 1 de nhap du lieu truoc!\n\n" RESET);
            continue;
        }

        switch (choice) {
            case 1: nhapMang(); break;
            case 2: inMang(); break;
            case 3: themPT(); break;
            case 4: suaPT(); break;
            case 5: xoaPT(); break;
            case 0: printf(GREEN "\nThoat chuong trinh.\n" RESET); break;
            default: printf(RED "\nLua chon khong hop le!\n" RESET);
        }

    } while (choice != 0);

    return 0;
}

void menu() {
    printf(YELLOW "+----------------------------------------------+\n" RESET);
    printf(YELLOW "|        CHUONG TRINH QUAN LY MANG CHUOI       |\n" RESET);
    printf(YELLOW "+----------------------------------------------+\n" RESET);
    printf(YELLOW "| 1. Nhap mang                                 |\n" RESET);
    printf(YELLOW "| 2. In mang                                   |\n" RESET);
    printf(YELLOW "| 3. Them phan tu                              |\n" RESET);
    printf(YELLOW "| 4. Sua phan tu                               |\n" RESET);
    printf(YELLOW "| 5. Xoa phan tu                               |\n" RESET);
    printf(YELLOW "| 0. Thoat                                     |\n" RESET);
    printf(YELLOW "+----------------------------------------------+\n" RESET);
}

void nhapMang() {
    printf(GREEN "\n==> NHAP MANG\n" RESET);
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu [%d]: ", i);
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }

    printf(GREEN "==> Da nhap xong!\n\n" RESET);
}

void inMang() {
    printf(GREEN "\n==> IN MANG\n" RESET);
    for (int i = 0; i < n; i++) {
        printf("[%d] %s\n", i, arr[i]);
    }
    printf("\n");
}

void themPT() {
    int pos;
    char value[100];

    printf(GREEN "\n==> THEM PHAN TU\n" RESET);
    printf("Nhap vi tri: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 0 || pos > n) {
        printf(RED "Vi tri khong hop le!\n" RESET);
        return;
    }

    printf("Nhap gia tri: ");
    fgets(value, 100, stdin);
    value[strcspn(value, "\n")] = '\0';

    for (int i = n; i > pos; i--) {
        strcpy(arr[i], arr[i - 1]);
    }
    strcpy(arr[pos], value);
    n++;

    printf(GREEN "==> Da them thanh cong!\n\n" RESET);
}

void suaPT() {
    int pos;
    printf(GREEN "\n==> SUA PHAN TU\n" RESET);
    printf("Nhap vi tri can sua: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 0 || pos >= n) {
        printf(RED "Vi tri khong hop le!\n" RESET);
        return;
    }

    printf("Nhap gia tri moi: ");
    fgets(arr[pos], 100, stdin);
    arr[pos][strcspn(arr[pos], "\n")] = '\0';

    printf(GREEN "==> Da sua thanh cong!\n\n" RESET);
}

void xoaPT() {
    int pos;
    printf(GREEN "\n==> XOA PHAN TU\n" RESET);
    printf("Nhap vi tri xoa: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf(RED "Vi tri khong hop le!\n" RESET);
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }
    n--;

    printf(GREEN "==> Da xoa thanh cong!\n\n" RESET);
}
