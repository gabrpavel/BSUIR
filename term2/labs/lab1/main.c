#include "header.h"


int main(void) {

   int choose = menu();

    int size = 0;
    int flag = 1;

    Film *films = memory(sizeof(Film));

    while (choose != 6) {


        switch (choose) {
            case 1:
                if(!flag)
                    free_memory(films, size);
                flag = 0;
                size = get_size(size);
                films = memory(size);
                create_mas_struct(films, size);
                break;
            case 2:
                if(flag) {
                    printf("Create array!!!");
                    getchar();
                    system("cls");
                    break;
                }
                show_mas_struct(films, size);
                break;
            case 3:
            if (flag) {
                printf("Create array!!!");
                system("pause");
                system("cls");
                break;
            }
            films = delete_struct(films, size);
            if (films == NULL) {
                flag = 1;
            }
            else {
                size--;
            }
            break;
            case 4:
                if(flag) {
                    printf("Create array!!!");
                    getchar();
                    system("cls");
                    break;
                }
                sort_mas_struct(films, size);
                break;
            case 5:
                flag = 0;
                size++;
                films = realloc(films, size*sizeof(Film));
                create_film(&films[size-1], size-1);
                system("cls");
                break;
            default:
                break;
        }
        choose = menu();
        if (choose == 6) free_memory(films, size);
    }

   
    return 0;
}
