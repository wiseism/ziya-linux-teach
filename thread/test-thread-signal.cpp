//
// Created by ziya on 2021/10/2.
//

/**
 * 测试多线程与信号
 *
 * @return
 */

#include "../include/common.h"
#include <signal.h>

 void* thread_fun(void* ) {
     int* p = 0;
     *p = 10;

     return reinterpret_cast<void *>(0x11);
 }

 void sighandler(int sig) {
     if (SIGSEGV == sig) {
         INFO_PRINT("发生段异常\n");

         // 看看不加这句的效果
//         exit(-1);
     }
 }

int main() {
    pthread_t tid;
    int* ret = 0;

    signal(SIGSEGV, sighandler);

    pthread_create(&tid, NULL, thread_fun, NULL);

    pthread_join(tid, reinterpret_cast<void **>(&ret));

    INFO_PRINT("子线程的返回值: %X\n", ret);

    return 0;
}