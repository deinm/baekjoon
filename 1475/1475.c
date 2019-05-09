#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>(b)?(a):(b)

int ans, tmp, cnt[10];
char str[10];

int main() {
    scanf("%s", str);
    
    for (int i = 0; i < strlen(str); i++) cnt[str[i] - '0']++;
    for (int i = 0; i <= 9; i++) if (i != 6 && i != 9) ans = max(ans, cnt[i]);
    
    ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);
    
    printf("%d", ans);

    return 0;
}