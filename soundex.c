#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void append(char *buffer, char c)
{
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (buffer[i] == '\0')
        {
            buffer[i] = c;
            return;
        }
    }
}

char *soundex_encoding(char *s)
{
    char MAP[] = {
        //A   B    C    D    E    F    G    H    I    J    K    L    M
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        //N   O    P    Q    R    S    T    U    V    W    X    Y    Z
        '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};

    char *str = malloc(sizeof(MAX_LEN * (sizeof(char))));
    strcpy(str, s);
    str = strupr(str);
    char buffer[MAX_LEN];
    for (int i = 0; i < MAX_LEN; i++)
    {
        buffer[i] = '\0';
    }
    char prev = '?', prevOutput = '?'; // 符号字符

    // 沿用首字符
    append(buffer, str[0]);
    for (int i = 1; i < strlen(str) && strlen(buffer) < 4; i++)
    {
        char c = str[i];
        // 判断字母是否为大写，且是否为符号字符
        if (c >= 'A' && c <= 'Z' && c != prev)
        {
            prev = c;
            char m = MAP[c - 'A'];
            // 去除重复的字母
            if (m != '0' && m != prevOutput)
            {
                append(buffer, m);
                prevOutput = m;
            }
        }
    }
    free(str);

    // 如果长度不够4就添加0
    for (int i = strlen(buffer); i < 4; i++)
    {
        append(buffer, '0');
    }

    char *result = malloc(sizeof(MAX_LEN * (sizeof(char))));
    strcpy(result, buffer);
    return result;
}

int main(void)
{
    char s[10] = "Marc";
    printf("%s\n", s);
    printf("%s\n", soundex_encoding(s));
    printf("%s\n\n", s);

    strcpy(s, "Taylor");
    printf("%s\n", s);
    printf("%s\n", soundex_encoding(s));
    printf("%s\n\n", s);
    return 0;
}
