#ifndef PRETTYPRINT_H
#define PRETTYPRINT_H

#include <vector>
#include <iostream>

template<typename T>
void pretty_print_vector(const std::vector<T>& vec) {
    std::cout << "{  ";
    for (const T& val : vec) {
        std::cout << val << "  ";
    }
    std::cout << "}" << std::endl;;
}

template<typename T>
void pretty_print_vector(const std::vector<std::vector<T>>& vec) {
    std::cout << "{" << std::endl;
    for (const std::vector<T>& inside_vec : vec) {
        std::cout << "  ";
        pretty_print_vector(inside_vec);
    }
    std::cout << "}" << std::endl;
}


#endif //PRETTYPRINT_H
