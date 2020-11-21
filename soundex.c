#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void append(char *buffer, char c)
{
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (buffer[i] == '-')
        {
            buffer[i] = c;
            return;
        }
    }
}

int strlen_c(char *buffer)
{
    int c = MAX_LEN;
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (buffer[i] == '-')
        {
            c--;
        }
    }
    return c;
}

char *soundex(char *s)
{
    static char MAP[] = {
        //A   B    C    D    E    F    G    H    I    J    K    L    M
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        //N   O    P    Q    R    S    T    U    V    W    X    Y    Z
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};

    char *str = malloc(sizeof(MAX_LEN * (sizeof(char))));
    strcpy(str, s);
    str = strupr(str);
    char c;
    char buffer[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++)
    {
        buffer[i] = '-';
    }
    char prev = '?', prevOutput = '?'; //符号字符

    for (int i = 0; i < strlen(str) && strlen_c(buffer) < 4; i++)
    {
        c = str[i];
        //判断字母是否为大写，且是否为符号字符
        if (c >= 'A' && c <= 'Z' && c != prev)
        {
            prev = c;
            //沿用首字符，依次进行排序，不是首字符的按照 Soundex 码
            if (i == 0)
            {
                append(buffer, c);
            }
            else
            {
                char m = MAP[c - 'A'];
                //去除重复的英文字母
                if (m != '0' && m != prevOutput)
                {
                    append(buffer, m);
                    prevOutput = m;
                }
            }
        }
    }

    //如果长度不够4就添加0
    for (int i = strlen_c(buffer); i < 4; i++)
    {
        append(buffer, '0');
    }
    free(str);
    char *encodedStr = malloc(sizeof(MAX_LEN * (sizeof(char))));
    encodedStr[0] = buffer[0];
    encodedStr[1] = buffer[1];
    encodedStr[2] = buffer[2];
    encodedStr[3] = buffer[3];
    encodedStr[4] = '\0';
    return encodedStr;
}

int main(void)
{
    char s[10] = "Marc";
    printf("%s\n", s);
    printf("%s\n", soundex(s));
    printf("%s\n\n", s);

    strcpy(s, "Taylor");
    printf("%s\n", s);
    printf("%s\n", soundex(s));
    printf("%s\n\n", s);
    return 0;
}
