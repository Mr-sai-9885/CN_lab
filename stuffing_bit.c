
//second logic




#include <stdio.h>
int main() {
    char in[100], out[200]; int i, j = 0, c = 0;
    printf("Binary: ");
    scanf("%s", in);
    for (i = 0; in[i]; i++)
    {
        out[j++] = in[i];
        if (in[i] == '1')
          c++;
        else c = 0;

        if (c == 5)
        {
            out[j++] = '0'; c = 0;
        }
    }
    out[j] = '\0';
    printf("Stuffed: %s\n", out);
}
