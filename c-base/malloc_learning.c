//
// Author liyazhou
// Date 2018/7/9 22:03.
//

/*
  动态分配内存
    void *malloc(size_t size)
    void free(void *pointer)

    void *calloc(size_t num_elements, size_t element_size)
    void *realloc(void *ptr, size_t new_size)


 */
#include <stdio.h>
#include <stdlib.h>

// #define MALLOC(num, type) (type*)alloc( (num) * sizeof(type))


void test_malloc() {
    int *pi;
    pi = malloc(100);
    if (NULL == pi) {
        printf("Out of memory. \n");
        exit(1);
    } else {
        printf("malloc success. \n");
    }

    printf("------------\n");

    int *int_arr;
    int_arr = malloc(10 * sizeof(int));
    if (NULL == int_arr) {
        printf("malloc fail. \n");
        exit(1);
    } else {
        printf("malloc success. \n");
    }

    int *start_pointer = int_arr;
    for (int i = 0; i < 10; i ++) {
        // *(int_arr++)= i;
        *int_arr = i;
        int_arr ++;
    }
    for (int j = 0; j < 10; j ++) {
        printf("%d, ", start_pointer[j]);
    }
    printf("\n");


    printf("释放动态分配的内存空间. \n");
    free(start_pointer);
    free(int_arr);

}


void
test_MALLOC(){
    int *int_arr;
    // int_arr = MOLLOC(10, int);
}

int main(){

    test_malloc();
}




