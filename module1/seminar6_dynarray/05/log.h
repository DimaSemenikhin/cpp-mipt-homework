#pragma once
#include <stdio.h>

#ifdef DEBUG
    #define LOG(message) printf("[DEBUG] %s: %d: %s\n", __FILE__, __LINE__, message)
#else
    #define LOG(message) do {} while (0)
#endif
