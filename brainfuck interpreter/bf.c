/************************************************************
 * File Name: bf.c
 * Author: Chobits
 * Date: 2021.04.25
 * Description: Brainfuck interpreter implementation in C
 * Version: 1.1.0
 * History:
 *   1. Date: 2021.04.25
 *      Version: 1.0.0 -> 1.1.0
 *      Modification: Added single line comment function.
***********************************************************/

#include <stdio.h>

#define TAPE_SIZE 1024

void bf(FILE *fp);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: parameter number mismatch.\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "bf <src_file> # Interpret the brainfuck source code.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: failed to open file \"%s\".\n", argv[1]);
        return 2;
    }

    bf(fp);

    fclose(fp);

    return 0;
}

void bf(FILE *fp)
{
    int bracket_cnt;                     // count brackets
    signed char command;                 // current command character, signed because EOF
    unsigned char data[TAPE_SIZE] = {0}; // memory data
    unsigned char *dp;                   // memory data pointer

    // Move dp to middle of the data tape
    dp = &data[TAPE_SIZE / 2];

    signed char c;
    while ((command = getc(fp)) != EOF)
    {
        switch (command)
        {
            /* Move data pointer to next address */
            case '>':
                ++dp;
                break;

            /* Move data pointer to previous address */
            case '<':
                --dp;
                break;

            /* Increase value at current data cell by one */
            case '+':
                ++*dp;
                break;

            /* Decrease value at current data cell by one */
            case '-':
                --*dp;
                break;

            /* Output character at current data cell */
            case '.':
                putc(*dp, stdout);
                break;

            /* Accept one character from user and advance to next one */
            case ',':
                *dp = getc(stdin);
                break;

            /* When the value at current data cell is 0,
            advance to next matching ] */
            case '[':
                if (!*dp)
                {
                    for (bracket_cnt = 1; bracket_cnt; fseek(fp, 1, SEEK_CUR))
                    {
                        c = getc(fp);
                        fseek(fp, -1, SEEK_CUR);
                        if (c == '[')
                        {
                            bracket_cnt++;
                        }
                        else if (c == ']')
                        {
                            bracket_cnt--;
                        }
                    }
                }
                break;

            /* Moves the command pointer back to matching
            opening [ if the value of current data cell is not 0 */
            case ']':
                if (*dp)
                {
                    // Move command pointer just before ]
                    fseek(fp, -2, SEEK_CUR);
                    for (bracket_cnt = 1; bracket_cnt; fseek(fp, -1, SEEK_CUR))
                    {
                        c = getc(fp);
                        fseek(fp, -1, SEEK_CUR);
                        if (c == ']')
                        {
                            bracket_cnt++;
                        }
                        else if (c == '[')
                        {
                            bracket_cnt--;
                        }
                    }
                    // Advance pointer after loop to match with opening [
                    fseek(fp, 1, SEEK_CUR);
                }
                break;

            /* Single-line comment */
            case ';':
                while ((c = getc(fp)) != '\n' && c != EOF)
                {
                }
                break;

            /* Ignore other characters */
            default:
                break;
        }
    }
}
