#include <stdio.h>
int main()
{
    int num, dig1, dig2, count=1;
    scanf ("%d", &num);
    scanf ("%d", &dig1);
    for (int i=1; i < (num); i++)
    {
        scanf ("%d", &dig2);
        if (dig1 <= dig2)
        {
            count++;
        }
        dig1 = dig2;
    }
    if (count==num)
    {
        printf ("1");
    }
    else
    {
        printf ("0");
    }
    return 0;
}
