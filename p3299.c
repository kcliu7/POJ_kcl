#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a = 2;
    int b = 3;
    scanf("%d%d", &a, &b);
    printf("%d\n", a);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    return 0;
}