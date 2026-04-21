#include <stdio.h>
#include <string.h>

#include "helper.h"

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    printf("%d\n", n);

    char lines[n][256];
    for (int i = 0; i < n; ++i) {
        fgets(lines[i], sizeof(lines[i]), stdin);
        // strcspn finds the index of the \n char in the current index
        lines[i][strcspn(lines[i], "\n")] = '\0';
        printf("%d: ", i+1);
        lexx(lines[i]);
    }

    return 0;
}

