#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

#define SUCCESS 1
#define FAIL 0

uint32_t read_int(char* filename){
    FILE *f = fopen(filename, "rb");
    if(f == NULL){
        printf("file error\n");
        exit(0);
    }

    uint32_t n;
    fread(&n, 4, 1, f);
    return ntohl(n);
}

int main(int argc, char** argv){
    if(argc != 3){
        printf("argv error\n");
        return 0;
    }

    uint32_t a = read_int(argv[1]);
    uint32_t b = read_int(argv[2]);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);
}