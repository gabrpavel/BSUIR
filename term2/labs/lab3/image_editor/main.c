#include "header.h"


int main(int argc, char* argv[]) {

    if(argc != 2) {

        printf("Error: enter the file name\n");
        exit(1);
    }

    int choose = menu();

    while (choose != EXIT) {

        if(choose == NEGATIVE) negative(argv[1]);
        else if(choose == BLACK_AND_WHITE) black_and_white(argv[1]);
        else if(choose == MEDIAN_FILTER) median_filter(argv[1]);
        else if(choose == GAMMA_CORRECTION) gamma_correction(argv[1]);

        choose = menu();

    }

    return 0;
}