#include "example/add.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cassert>
#include <string>
#include <string_view>

void print(int num);
int sub(int a, int b);
void callback();
void print_string(const std::string& str);

template <typename T> T
t_add(T a, T b);

int
main() {
    // std::cout << operations::add(1, 3) << std::endl;

    // =======

    // it's necessary to perform a fix bit range of differents architectures
    // (need to include `cstdint`)
    // std::int32_t x = 2147483646 + 1; // wrap-around value like unsigned int value

    // =======

    // std::size_t == 4 bytes (32 bits arch)
    // std::size_t == 8 bytes (64 bits arch)
    std::cout << sizeof(std::size_t) << std::endl;

    // =======
    
    std::cout << 5.9736e8 << std::endl;

    // =======
    std::cout << std::boolalpha << false << std::endl;

    // =======

    print(static_cast<int>(5.4));

    // =======

    // `std::int8_t` / `std::uint8_t` has the behavior of chars
    std::int8_t a { 65 }; // 65 == 'A' on ascii table
    std::cout << a << std::endl;

    // =======

    // happens an padding when `std::cout` read a string with 'SPACE', to fix
    // this it's necessary the usage of `std::getline()`
    std::string t1 {};
    std::string t2 {};

    std::cout << "t1: ";
    // std::cin >> t1;
    // std::getline(std::cin >> std::ws, t1);

    std::cout << "t2: ";
    // std::cin >> t2;
    // std::getline(std::cin >> std::ws, t2);

    std::cout << "t1: " << t1 << "\nt2: " << t2 << std::endl;

    // =======

    std::string t3 {};

    std::cout << "t3: ";
    // std::cin >> t3;

    // tutor: need to perform a static cast to suprise compiler error
    int size = /*static_cast<int>*/t3.length(); // no error found

    std::cout << size << std::endl;

    // =======

    // the literal constant type of '4.1' is double, some compilers can warn the
    // type literal because of the usage of float. e.g:
    //
    // 4.1 == double literal
    // 4.1f == float literal

#ifdef COMPILE_WARNS
    constexpr float y { 4.1 }; // keyword `constexpr` resolve the const in compilation time
#endif

    float b {};

    // std::cin >> b;

    const float c = b; // can't be `constexpr` because this is resolved on run-time

    std::cout << c << std::endl;

    // =======

    std::bitset<4> d { 0b0011 };
    std::bitset<4> e { 0b1000 };

    std::cout << d << std::endl;

    std::cout << (d << 2) << std::endl; // 1100
    std::cout << (d >> 1) << std::endl; // 0001

    std::cout << ~d << std::endl; // flip the bits NOT bitwise

    std::cout << (d | e) << std::endl; // aval to 1 if one of the bits is 1 OR bitwise
    // 0011
    // 1000
    // ----
    // 1011

    std::cout << (d & std::bitset<4> { 0b0001 }) << std::endl; // aval to 1 if all bits is 1 AND bitwise
    // 0011
    // 1001
    // ----
    // 0001

    std::cout << (d ^ e) << std::endl; // eval to 1 if only one bit is 1 XOR
    // 0011
    // 1000
    // ---
    // 1011

    // =======

    // linker error because of the usage of `static` keyword that define the
    // variable only in the declared file, it's necessary to import the file to
    // works

    // std::cout << sub(3, 1) << std::endl;

    // ======= THIS TOPIC IS RARELY USED

    // need to be included `cstdlib` to use `std::exit()` & `std::atexit()`

    std::atexit(callback); // callback function to be executed when `std::exit()` is called

    // std::exit(0);
    
    // OBS: for multi-thread programs it's necessary to use:
    // `std::quick_exit()` == `std::exit()`
    // `std::at_quick_exit()` == `std::atexit()`
    
    // `std::abort()` implicitly used on zero division error
    
    // `std::terminate()` implicitly used on raised exceptions

    // =======

    // assert(0 > 1 && "zero is not grater than one"); // evaluated on run time
    // static_assert(0 > 1, "zero is not greater than one"); // evaluted on compilation time

    // =======
    
    // type alias 
    using name = std::string;

    name lorem { "ipsum" };

    std::cout << lorem << std::endl;

    // =======

    using namespace std::literals;

    auto f { "foo"s }; // std::string deduction

    // error on string view literal usage
    // auto g { "foo"sv }; // std::string_view deduction
    
    // obs: type deduction not works for function parameters

    std::cout << f << std::endl;

    // =======

    std::cout << t_add<int>(1, 2) << std::endl;

    // =======
    
    int h { 1 };

    // '<type>&' it's a reference to a lvalue (values that have identity)
    int& ref { h };

    std::cout << ref << std::endl;

    // =======

    std::string str { "lorem ipsum" };

    print_string(str);

    // =======
    
    int i { 2 };

    int& j { i };

    std::cout << *(&j) << std::endl;

    // =======

    int z {};

    std::cout << &z << std::endl;

    std::cout << sizeof(std::string) << std::endl;
    // always will be 8, a pointer just maintain a memory address that in this
    // case it's represented by 8 bytes
    std::cout << sizeof(double*) << std::endl; 

    // =======

    // scoped enumerator best practice to avoid name conflicts 
    enum class Pet {
        cat,
        dog,
        bird
    };

    std::cout << static_cast<int>(Pet::cat) << std::endl;

    // =======

    std::cout << "=======" << std::endl;

    // default values (need to be the first arg)
    // '=' inside the capture `[]` capture all values referenced inside the
    // lambda by value
    // '&' inside the capture `[]` capture all values referenced inside the
    // lambda by reference
    auto lambda = [/* (=|&), */ lorem](/* args */) /* mutable */ -> void {
        // can access `lorem` inside the lambda
        std::cout << "lambda call" << std::endl;
    };

    lambda();

    // std::ref() permits to pass a lambda with a 'shared scope', e.g:
    // a lambda scoped variable is the same for copies of this lambda (new
    // assignment)
    //
    // auto lambda = []() { int a { 0 }; a++; };
    //
    // auto assign { lambda };
    //
    // assign call `assign()` will reuse the value left from a lambda call
    // `lambda()` on `a` and vice versa

    return EXIT_SUCCESS;
}

void
print(int num) {
    std::cout << num << std::endl;
}

void
callback() {
    // can't receive args and can't return anything
}

template <typename T> T
t_add(T a, T b) {
    return a + b;
};

// '<type>&' makes possible to receive an object by reference disabling
// unnecesssary copy of the higher costs objects
void
print_string(const /* const to disable impure function behavior */ std::string& str) {
    std::cout << str << std::endl;
}
