#include "qrng.hpp"
#include <stdio.h>

QRNG::QRNG() {
    if (graal_create_isolate(NULL, NULL, &thread) != 0) {
        fprintf(stderr, "graal_create_isolate error\n");
    }
    qrng_connect(thread);
}

QRNG::~QRNG() {
    if (graal_detach_thread(thread) != 0) {
        fprintf(stderr, "graal_detach_thread error\n");
    }
}

void QRNG::fetch_bytes(byte arr[], int cnt) {
    return;
    // char* s = qrng_get_main_executable(thread);
    // qrng_free_result(thread, s);

    // s = qrng_get_random_bytes(thread, arr, cnt);
    // if (s!=NULL) 
    //     printf("error: [%s]\n", s);
    
    // qrng_free_result(thread, s);
}