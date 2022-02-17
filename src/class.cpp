#include <iostream>
#include <string>

class
Person {
private:
    std::string name {};
    int age {};

public:
    Person() = default;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    };

    ~Person() {
        std::cout << "destructor\n";
    }

    std::string& get_name() {
        return name;
    }
};

int
main() {
    Person p{ "lorem", 99 };

    std::cout << p.get_name() << std::endl;

    return 0;
}
