//
// Created by rongfan on 2022/5/6.
//

#include <iostream>
#include <vector>

void func_1() {
    constexpr size_t buffer_count = 10001;
    std::vector<size_t> buffer(buffer_count);
    // initialize buffer values
    for (size_t i = 0; i < buffer_count; ++i) {
        buffer[i] = i;
    }
    // to find the max value in buffer
    size_t max_value = buffer[0];
    for (size_t i = 0; i < buffer_count; ++i) {
        max_value = (max_value > buffer[i]) ? max_value : buffer[i];
    }
    std::cout << max_value << std::endl;
}

void func_2() {
    constexpr size_t buffer_count = 10001;
    std::vector<size_t> buffer(buffer_count);
    for (size_t i = 0; i < buffer_count; ++i) {
        buffer[i] = i;
    }
    // to find the max value in buffer
    size_t max_value = buffer[0];
    for (size_t i = 0; i + 4 < buffer_count; i +=4) {
        max_value = (max_value > buffer[i]) ? max_value : buffer[i];
        max_value = (max_value > buffer[i + 1]) ? max_value : buffer[i + 1];
        max_value = (max_value > buffer[i + 2]) ? max_value : buffer[i + 2];
        max_value = (max_value > buffer[i + 3]) ? max_value : buffer[i + 3];
    }
    /*
     * for id of 10001
     * buffer_count / 4 *  4 == buffer_count
     */
    for (size_t i = buffer_count / 4 * 4; i < buffer_count; ++i) {
        max_value = (max_value > buffer[i]) ? max_value : buffer[i];
    }
    std::cout << max_value << std::endl;
}

void func_3() {
    constexpr size_t buffer_count = 10001;
    std::vector<size_t> buffer(buffer_count);
    for (size_t i = 0; i < buffer_count; ++i) {
        buffer[i] = i;
    }
    // to find the max value in buffer
    auto ptr = buffer.begin();
    size_t max_value = *ptr;
    for (size_t i = 0; i + 4 < buffer_count; i +=4) {
        max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
        max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
        max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
        max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
    }

    switch (buffer_count % 4) {
        case 3: max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr; [[fallthrough]];
        case 2: max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr; [[fallthrough]];
        case 1: max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
        /* if used at last [[fallthrough]];
         * warning: attribute ‘fallthrough’ not preceding a case label or default label
         */
    }
    std::cout << max_value << std::endl;
}

void duff_device() {
    constexpr size_t buffer_count = 10001;
    std::vector<size_t> buffer(buffer_count);
    for (size_t i = 0; i < buffer_count; ++i) {
        buffer[i] = i;
    }
    auto ptr = buffer.begin();
    size_t max_value = *ptr;

    size_t i = 0;
    switch (buffer_count % 4) {
        for ( ; i < (buffer_count - 1 + 4) / 4; ++i) {
            case 0:
                max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
                [[fallthrough]];
            case 3:
                max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
                [[fallthrough]];
            case 2:
                max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
                [[fallthrough]];
            case 1:
                max_value = (max_value > *ptr) ? max_value : *ptr; ++ptr;
        }
    }
    std::cout << max_value << std::endl;
}



int main(void) {
//   func_2();
//   func_3();
    duff_device();
    return 0;
}
