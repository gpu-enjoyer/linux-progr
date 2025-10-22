
#include <iostream>

#if defined(USE_GPU) && defined(USE_FLOAT)
    #define CODE_V 0
#elif defined(USE_GPU)
    #define CODE_V 1
#elif defined(USE_FLOAT)
    #define CODE_V 2
#else
    #define CODE_V 3
#endif

int main() {

    #if CODE_V == 0
        std::cout << "    GPU &     FLOAT\n";
    #elif CODE_V == 1
        std::cout << "    GPU & not FLOAT\n";
    #elif CODE_V == 2
        std::cout << "not GPU &     FLOAT\n";
    #elif CODE_V == 3
        std::cout << "not GPU & not FLOAT\n";
    #endif

    return 0;
}
