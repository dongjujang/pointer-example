#include <stdio.h>
#include <stdlib.h>

void sum_minus(int* x, int* y, int** result, int** result2) {
    *result = (int*)malloc(sizeof(int));
    **result = *x + *y;
    //함수에서 선언시 *는 레퍼런스, 변수에서 활용시 *는 디레퍼런스
    //함수 내 동적할당시 더블포인터 활용    모든건 메모리
    int minus = *x - *y;
    if (minus > 0) {
        *result2 = (int*)malloc(sizeof(int));
        **result2 = minus;
    }
}

int main(int argc, const char * argv[]) {
    int x = 5;
    int y = 10;
    int* result = NULL;
    int* result2 = NULL;
    
    sum_minus(&x, &y, &result, &result2);
    
    if (result) free(result);
    if (result2) free(result2);//특정 상황에서 동적할당을 함으로 매번 free해줄 필요는 없다.
    
    return 0;
}
