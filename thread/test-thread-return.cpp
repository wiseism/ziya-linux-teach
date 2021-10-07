////
//// Created by ziya on 2021/10/2.
////
//
///**
// * 测试如何获取线程返回值，两种方式
// * @return
// */
//
//#include "../include/common.h"
//
// void* thread_fun(void* ) {
//     pthread_exit(reinterpret_cast<void *>(0x22));
//
//     return reinterpret_cast<void *>(0x11);
// }
//
//int main() {
//    pthread_t tid;
//    int* ret = 0;
//
//    pthread_create(&tid, NULL, thread_fun, NULL);
//
//    pthread_join(tid, reinterpret_cast<void **>(&ret));
//
//    INFO_PRINT("子线程的返回值: %X\n", ret);
//
//    return 0;
//}