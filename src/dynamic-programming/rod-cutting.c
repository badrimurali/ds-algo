#include <stdio.h>
#include <curses.h>
#include <limits.h>
void memoziedCutRod(int* array, int n);
int main() {
	int revenue[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	memoziedCutRod(revenue, 7);
	return 0;
}

void memoziedCutRod(int* array, int n) {
	int r[n+1], s[n+1];
	r[0] = 0;
	s[0] = 0;
	int j = 1, i = 1;
	for(j = 1; j <= n; j++) {
		int q = INT_MIN;
		for(i =1; i <= j; i++) {
			if(q < array[i] + r[j - i]) {
				q = array[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	while(n > 0) {
		printf("%d ", s[n]);
		n = n - s[n];
	}
}

