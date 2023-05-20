#include "header.h"

int menu() {

    int choose;
    printf("Choose the conversion type: \n\n");
    printf("1. Negative\n");
    printf("2. Black and white\n");
    printf("3. Median filter\n");
    printf("4. Gamma correction\n");
    printf("5. Exit\n");
    printf("\nYour answer: ");

    while (scanf_s("%d", &choose) != 1 || choose < 1 || choose > 5 || getchar() != '\n')
    {
        printf("Error! Try again...\n");
        rewind(stdin);
    }
    system("cls");

    return choose;

}


void negative(char* input_file) {

    BITMAP header;
    BITMAP_INFO_HEADER info;
    RGB pixel;

    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: \"%s\" not found\n", input_file);
        exit(1);
    }
    fread(&header, sizeof(header), 1, input);

    FILE* output = fopen("negative.bmp", "wb");
    if (output == NULL) {
        printf("Error creating output file\n");
        fclose(input);
        exit(1);
    }


    //checking the file format
    if (header.signature != 0x4D42) {

        printf("Invalid \"%s\" format\n", input_file);
        fclose(input);
        fclose(output);
        exit(1);

    }

    fread(&info, sizeof(info), 1, input);
    fwrite(&header, sizeof(header), 1, output);
    fwrite(&info, sizeof(info), 1, output);

    for (int y = 0; y < info.height; y++) {

        for (int x = 0; x < info.width; x++) {

            fread(&pixel, sizeof(pixel), 1, input);

            pixel.red = 255 - pixel.red;
            pixel.green = 255 - pixel.green;
            pixel.blue = 255 - pixel.blue;

            fwrite(&pixel, sizeof(pixel), 1, output);

        }

    }

    fclose(input);
    fclose(output);

    printf("Conversion complete!\n");
    system("pause");
    system("cls");

}

void black_and_white(char* input_file) {

    BITMAP header;
    BITMAP_INFO_HEADER info;
    RGB pixel;

    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: \"%s\" not found\n", input_file);
        exit(1);
    }
    fread(&header, sizeof(header), 1, input);

    FILE* output = fopen("black_and_white.bmp", "wb");
    if (output == NULL) {
        printf("Error creating output file\n");
        fclose(input);
        exit(1);
    }

    //checking the file format
    if (header.signature != 0x4D42) {

        printf("Invalid \"%s\" format\n", input_file);
        fclose(input);
        fclose(output);
        exit(1);

    }

    fread(&info, sizeof(info), 1, input);
    fwrite(&header, sizeof(header), 1, output);
    fwrite(&info, sizeof(info), 1, output);

    for (int y = 0; y < info.height; y++) {

        for (int x = 0; x < info.width; x++) {

            fread(&pixel, sizeof(pixel), 1, input);


            unsigned char gray = (unsigned char)(pixel.red * 0.2989 + pixel.green * 0.5870 + pixel.blue * 0.1140);
            

            pixel.red = gray;
            pixel.green = gray;
            pixel.blue = gray;

            fwrite(&pixel, sizeof(pixel), 1, output);

        }

    }

    fclose(input);
    fclose(output);

    printf("Conversion complete!\n");
    system("pause");
    system("cls");
}

// function to get the pixel value at the specified coordinates
RGB get_pixel(RGB* data, int width, int height, int x, int y) {

    if (x >= 0 && x < width && y >= 0 && y < height) return data[y * width + x];

    else {

        RGB null_pixel = { 0,0,0 };
        return null_pixel;

    }

}

// function for sorting the array of RGB values by brightness (from dark to light)
int compare_RGB(const void* first, const void* second) {
    const RGB* first_RGB = (const RGB*)first;
    const RGB* second_RGB = (const RGB*)second;

    int brightness_first = (int)first_RGB->red + (int)first_RGB->green + (int)first_RGB->blue;
    int brightness_second = (int)second_RGB->red + (int)second_RGB->green + (int)second_RGB->blue;

    return brightness_first - brightness_second;
}


void median_filter(char* input_file) {

    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: \"%s\" not found\n", input_file);
        exit(1);
    }

    BITMAP header;
    BITMAP_INFO_HEADER info;

    fread(&header, sizeof(header), 1, input);
    fread(&info, sizeof(info), 1, input);

    RGB* image_data = (RGB*)malloc(info.width * info.height * sizeof(RGB));
    fread(image_data, sizeof(RGB), info.height * info.width, input);
    fclose(input);

    RGB* output_image_data = (RGB*)malloc(info.width * info.height * sizeof(RGB));

    int kernel_size = 0;
    printf("Input kernel size of the median filter (odd number)\n");
    while (scanf_s("%d", &kernel_size) != 1 || kernel_size < 1 || kernel_size > 21 || getchar() != '\n')
    {
        printf("Error! Try again...\n");
        rewind(stdin);
    }
    system("cls");
    int offset = kernel_size / 2;

    RGB* kernel = malloc(kernel_size * kernel_size * sizeof(RGB));

    for (int y = 0; y < info.height; ++y) {

        for (int x = 0; x < info.width; ++x) {

            int index = 0;

            for (int ky = -offset; ky <= offset; ++ky) {

                for (int kx = -offset; kx <= offset; ++kx) {

                    RGB pixel = get_pixel(image_data, info.width, info.height, x + kx, y + ky);
                    kernel[index] = pixel;
                    index++;

                }

            }

            qsort(kernel, kernel_size * kernel_size, sizeof(RGB), compare_RGB);
            RGB median_pixel = kernel[kernel_size * kernel_size / 2];
            output_image_data[y * info.width + x] = median_pixel;

        }

    }

    free(kernel);


    FILE* output = fopen("median_filter.bmp", "wb");
    if (output == NULL) {

        printf("Error: can't create file %s\n", "median_filter.bmp");
        free(image_data);
        free(output_image_data);
        exit(1);

    }

    //checking the file format
    if (header.signature != 0x4D42) {

        printf("Invalid \"%s\" format\n", input_file);
        fclose(output);
        free(image_data);
        free(output_image_data);
        exit(1);

    }

    fwrite(&header, sizeof(header), 1, output);
    fwrite(&info, sizeof(info), 1, output);
    fwrite(output_image_data, sizeof(RGB), info.width * info.height, output);

    fclose(output);

    free(image_data);
    free(output_image_data);

    printf("Conversion complete!\n");
    system("pause");
    system("cls");

}

void gamma_correction(char* input_file) {
    BITMAP header;
    BITMAP_INFO_HEADER info;

    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: \"%s\" not found\n", input_file);
        exit(1);
    }
    fread(&header, sizeof(header), 1, input);

    FILE* output = fopen("gamma_correction.bmp", "wb");
    if (output == NULL) {
        printf("Error creating output file\n");
        fclose(input);
        exit(1);
    }

    // checking the file format
    if (header.signature != 0x4D42) {
        printf("Invalid \"%s\" format\n", input_file);
        fclose(input);
        fclose(output);
        exit(1);
    }

    fread(&info, sizeof(info), 1, input);
    fwrite(&header, sizeof(header), 1, output);
    fwrite(&info, sizeof(info), 1, output);

    float gamma;
    printf("Input gamma correction value: ");
    while (scanf("%f", &gamma) != 1 || getchar() != '\n') {
        printf("Error! Try again...\n");
        rewind(stdin);
    }
    system("cls");

    int padding = (4 - (info.width * 3) % 4) % 4;
    int pixel_size = 3;

    unsigned char* row = malloc((info.width * pixel_size + padding) * sizeof(unsigned char));

    for (int y = 0; y < info.height; ++y) {
        fread(row, info.width * pixel_size, 1, input);

        for (int x = 0; x < info.width; ++x) {
            unsigned char red = row[x * pixel_size];
            unsigned char green = row[x * pixel_size + 1];
            unsigned char blue = row[x * pixel_size];

            double new_red = pow(red / 255.0, gamma) * 255.0;
            double new_green = pow(green / 255.0, gamma) * 255.0;
            double new_blue = pow(blue / 255.0, gamma) * 255.0;

            row[x * pixel_size] = (unsigned char)new_blue;
            row[x * pixel_size + 1] = (unsigned char)new_green;
            row[x * pixel_size + 2] = (unsigned char)new_red;
        }

        fwrite(row, info.width * pixel_size, 1, output);
        fwrite(&row[info.width * pixel_size], padding, 1, output);
    }

    free(row);

    fclose(input);
    fclose(output);

    printf("Conversion complete!\n");
    system("pause");
    system("cls");
}
