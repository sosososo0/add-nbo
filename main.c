#include <stdio.h> // for printf
#include <stdint.h> //for uint_32
#include <netinet/in.h> //for ntohl

int main(int argc, char* argv[]) {
    // 파일을 2개 입력하지 않았을 경우 에러 발생 
    if (argc != 3) {
        printf("There must be 2 file inputs.\n");
        return 1;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    // 파일이 없을 경우 에러 발생 
    if (file1 == NULL || file2 == NULL) {
        printf("file open error\n");
        return 1;
    }

    uint32_t num1;
    uint32_t num2;

    // 4byte보다 작은 경우 에러
    if ((fread(&num1, 1, 4, file1) != 4) || (fread(&num2, 1, 4, file2) != 4)) {
        printf("file size must be 4 bytes.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    fclose(file1);
    fclose(file2);

    // 네트워크 바이트 순서를 호스트 바이트 순서로 변환
    uint32_t host_num1 = ntohl(num1);
    uint32_t host_num2 = ntohl(num2);
    uint32_t plus_num1_num2 = host_num1 + host_num2;

    // 출력 
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", 
        host_num1, host_num1, 
        host_num2, host_num2,
        plus_num1_num2,plus_num1_num2);
    
    return 0;
}
