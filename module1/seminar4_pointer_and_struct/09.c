#include <stdio.h>
#include <string.h>

void used_chars(const char* str, char* used){
    int in_str[26] = {0};
    for (int i = 0; str[i] != '\0'; i++){

        if (str[i] >= 'a' && str[i] <= 'z'){
            in_str[str[i] - 'a'] = 1;
        }
        if (str[i] >= 'A' && str[i] <= 'Z'){
            in_str[str[i] - 'A'] = 1;
        }
    }
    int j = 0;
    for (int i = 0; i < 26; i++){
        if (in_str[i] == 1){
            used[j] = 'a' + i;
            j++;
        }

    }
    used[j] = '\0';
}

int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
}