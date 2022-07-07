#include <stdio.h>

int main()
{
    printf("cat /proc/%d/maps 查看内存分配\n", getpid());
    getchar();

    char* addr = malloc(128*1024*1024);
    printf("申请128MB字节的内存的起始地址:%x\n", addr);
    getchar();

    free(addr);
    printf("释放addr后，heap堆不会被释放\n");
    getchar();
    return 0;

}

