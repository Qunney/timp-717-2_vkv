#include <stdio.h>
int main()
{
    int num, dig, res=1;
    scanf ("%d", &num);
    for (int i=1; i <= num; i++)
    {
        scanf ("%d", &dig );
        res = res*dig;
    }
    printf ("%d", res);
    return 0;
}
