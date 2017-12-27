#include<stdio.h>
#include <curses.h>

int main() {
    int a[] = {6, 8, 1, 4, 5, 3, 7, 2};
    int i = 0, j=0, v=0;
    for(i = 1; i <= (int)(sizeof(a) / sizeof(a[0])) - 1; i++) {
        v = a[i];
        j = i;
        while(a[j - 1] > v && j >= 1) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }

    int l = 0;
    printf("final sorted list is ");
    for(int l = 0; l < (int)(sizeof(a) / sizeof(a[0])); l++) {
        printf("%d ", a[l]);
    }
    return 0;
}