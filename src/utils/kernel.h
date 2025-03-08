#pragma once

#include <inttypes.h>
#include <cstring>

#include <kernel/kernel.h>

#include <coreinit/memorymap.h>
#include <coreinit/cache.h>

void *kernel_memcpy(void *dst, void *src, int32_t size) {
    const int32_t kernel_buffer_size = 256;
    int8_t kernel_buffer[kernel_buffer_size];

    while (size > 0) {
        int32_t copy_size = size > kernel_buffer_size ? kernel_buffer_size : size;

        memcpy(kernel_buffer, src, copy_size);
        KernelCopyData(OSEffectiveToPhysical((uint32_t)dst), OSEffectiveToPhysical((uint32_t)kernel_buffer), copy_size);

        dst = (int8_t*)dst + copy_size;
        src = (int8_t*)src + copy_size;
        size -= copy_size;
    }

    return dst;
}

void *kernel_memcpy_flush(void *dst, void *src, int32_t size) {
    DCFlushRange(src, size);
    ICInvalidateRange(src, size);

    void *ptr = kernel_memcpy(dst, src, size);

    DCFlushRange(dst, size);
    ICInvalidateRange(dst, size);

    return ptr;
}

template<typename T>
void kernel_write_value(uint32_t dst, T src) {
    kernel_memcpy_flush((void*)dst, &src, sizeof(T));
}

template<typename T>
T kernel_read_value(void *src) {
    T buffer;
    kernel_memcpy_flush(&buffer, src, sizeof(T));

    return buffer;
}