#include <math.h>
#include <stdio.h>

int main(void)
{
    double a, b, c, delta, x1, x2, m, n, i, j;
    printf("������һԪ���η��̵�����ϵ����\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (fabs(a) <= 1e-6)
    {
        printf("�������ϵ��a����Ϊ�㣡\n");
    }
    else
    {
        delta = b * b - 4 * a * c;
        m = -b / (2 * a);
        n = sqrt(fabs(delta)) / (2 * fabs(a));
        i = m + n;
        j = m - n;

        if (delta < 0)
        {
            printf("������������ͬ�ĸ�������\n");
            printf("%.2lf + %.2lfi\n%.2lf - %.2lfi\n", m, n, m, n);
        }
        else
        {
            if (i == j)
            {
                printf("������������ͬ��ʵ������\n");
                printf("%.2lf\n%.2lf\n", i, i);
            }
            else
            {
                x1 = (i > j) ? i : j;
                x2 = (i > j) ? j : i;
                printf("������������ͬ��ʵ������\n");
                printf("%.2lf\n%.2lf\n", x1, x2);
            }
        }
        return 0;
    }
}
