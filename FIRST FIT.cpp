#include <stdio.h>

void firstFit(int b[], int m, int p[], int n) {
    int a[n];
    for (int i = 0; i < n; i++) a[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                a[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("Proc\tPSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        if (a[i] != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i], a[i] + 1);
        else
            printf("%d\t%d\tNot Allocated\n", i + 1, p[i]);
    }
}

int main() {
    int b[] = {100, 500, 200, 300, 600};
    int p[] = {212, 417, 112, 426};
    int m = sizeof(b) / sizeof(b[0]);
    int n = sizeof(p) / sizeof(p[0]);

    firstFit(b, m, p, n);

    return 0;
}

