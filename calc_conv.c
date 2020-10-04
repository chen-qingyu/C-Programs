#include <stdio.h>

#define COEF_LEN 6
#define DATA_LEN 12
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

void conv(int coef[], int data[], int out[], int coef_len, int data_len);

int main(void)
{
    int coef[COEF_LEN] = {1, 2, 3, 3, 2, 1};
    int data[DATA_LEN] = {1, 3, 5, 7, 9, 11, 13, 15, 12, 8, 4, 2};
    int out[COEF_LEN + DATA_LEN - 1] = {0};
    int i;

    conv(coef, data, out, COEF_LEN, DATA_LEN);

    for (i = 0; i < COEF_LEN + DATA_LEN - 1; i++)
    {
        printf("%d ", out[i]);
    }
    return 0;
}

void conv(int coef[], int data[], int out[], int coef_len, int data_len)
{
    int i, j;
    int k = coef_len + data_len - 1;

    for (i = 0; i < k; i++)
    {
        for (j = MAX(0, i + 1 - data_len); j <= MIN(i, coef_len - 1); j++)
        {
            out[i] += coef[j] * data[i - j];
        }
    }
}
