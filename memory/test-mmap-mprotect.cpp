//
// Created by ziya on 2021/10/2.
//

/**
 * 测试多线程与信号
 *
 * @return
 */

#include "../include/common.h"
#include <sys/mman.h>
#include <signal.h>

 void sighandler(int sig) {
     if (SIGSEGV == sig) {
         INFO_PRINT("发生段异常\n");

         exit(-1);
     }
 }

int main() {
    signal(SIGSEGV, sighandler);

    // 申请一块可读可写可执行的内存
    void *temp = mmap(
            NULL,   // 映射区的开始地址，设置为NULL或0表示由系统决定
            4,       // 申请的内存大小按照内存页对齐，这里直接调用函数获取内存页大小
            PROT_READ | PROT_WRITE | PROT_EXEC, // 映射的内存区的权限：可读可写可执行
            MAP_ANONYMOUS | MAP_PRIVATE,    // 映射对象的类型
            -1,
            0
    );

    *(int*)temp = 0x11223344;

    INFO_PRINT("%X\n", *(int*)temp);

    // 修改内存属性为none，为了写触发段异常
    mprotect(temp, getpagesize(), PROT_NONE);

    // 引发段异常
    *(int*)temp = 10;

    INFO_PRINT("end\n");

    return 0;
}