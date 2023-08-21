
#include <stdio.h>


void code(char *str);
void de_code(char *str);



int main() {

   char str[100];
   int c;
   int index =0;
   int a=0;

   scanf("%d",&a);
    getchar();
    switch (a) {
        case 1:
            while((c = getchar())!='\n'){

                str[index++] = c;

            }
            str[index] = '\0';
            for(int i =1; str[i]!= '\0'; i++ ){
                if((str[i] == ' ' && str[i-1]!= ' ' && str[i+1] !=' ' )){
                    code(str);

                }else{
                    return 1;
                }
            }
            break;
        case 2 :
            while((c = getchar())!='\n'){

                str[index++] = c;

            }
            str[index] = '\0';
            for(int i =2; str[i]!= '\0'; i++ ){
                if((str[i] == ' ' && str[i-1]!= ' ' && str[i+1] !=' ' )){
                    de_code(str);

                }else{
                    return 1;
                }
            }
            break;
    }
    return 0;
}



void code(char *str){

    for(int i=0;str[i] !='\0';i++){
        if(str[i]== ' '){
            continue;
        }
        printf("%x ",str[i]);
    }

}

void de_code(char *str) {
    int num = 0;
    int is_first_digit = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue; // Пропускаем пробелы
        }

        // Преобразуем шестнадцатеричный символ в число
        int digit = str[i] - '0';
        if (digit >= 0 && digit <= 9) {
            num = num * 16 + digit;
        } else if (digit >= 17 && digit <= 22) {
            num = num * 16 + (digit - 7);
        } else {
            printf("n/a ");
            num = 0;
            is_first_digit = 1;
            continue;
        }

        if (is_first_digit) {
            is_first_digit = 0;
        } else {
            printf("%c ", (char) num);
            num = 0;
            is_first_digit = 1;
        }
    }
}