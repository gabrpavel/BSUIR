#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma pack(push, 1)
typedef enum {

    NEGATIVE = 1,
    BLACK_AND_WHITE,
    MEDIAN_FILTER,
    GAMMA_CORRECTION,
    EXIT

}MENU;

typedef struct {

    unsigned short signature;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;

}BITMAP;

typedef struct {

    unsigned int size; // sizeof BITMAP_INFO_HEADER
    int width;
    int height;
    unsigned short planes; // num of planes
    unsigned short bits_per_pixels;
    unsigned int compression;
    unsigned int image_size;
    int X_pixels_per_meter;
    int Y_pixels_per_meter;
    unsigned int colors_uses;
    unsigned int colors_important;

}BITMAP_INFO_HEADER;

typedef struct {

    unsigned char red;
    unsigned char green;
    unsigned char blue;

}RGB;
#pragma pack(pop)

int menu();

RGB get_pixel(RGB* data, int width, int height, int x, int y);
int compare_RGB(const void* first, const void* second);

void negative(char* input_file);
void black_and_white(char* input_file);
void median_filter(char* input_file);
void gamma_correction(char* input_file);

