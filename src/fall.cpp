#include<iostream>
int
main() {
    switch(2) {
        case 1:
            std::cout << '1' << std::endl;
            break;
        case 2:
            std::cout << '2' << std::endl;
            [[fallthrough]];
        case 3:
            std::cout << '3' << std::endl;
            break;
        default:
            std::cout << "def" << std::endl;
            break;
    }

    return 0;
}
