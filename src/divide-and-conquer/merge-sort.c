#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
void mergesort(int* a, int l, int r);
void merge(int* a, int l, int mid, int r);

int main() {

    int a[] = {6, 8, 1, 4, 5, 3, 7, 2};
    mergesort(a, 0, 7);
    int i =0;
    for(i =0; i< (int)(sizeof(a) / sizeof(a[0])); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mergesort(int* a, int l, int r) {
    int mid;
    if(r > l) {
        mid = (r + l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }

}

void merge(int* a, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* left = (int *) malloc(n1 * sizeof(int));
    int* right = (int *) malloc(n2 * sizeof(int));

    while(i <= mid) {
        left[k] = a[i];
        i++;
        k++;
    }
    i =0;
    k =0;
    while( j<= r) {
        right[k] = a[j];
        j++;
        k++;
    }
    j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = left[i];
        k++;
        i++;
    }
    while(j < n2) {
        a[k] = right[j];
        k++;
        j++;
    }
}