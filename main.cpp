#include <iostream>
#include <vector>

class Branch {

    Branch *parent = nullptr;

    std::vector<Branch*> mid_branch = {nullptr, nullptr};

    std::vector<Branch*> big_branch = {mid_branch[0], mid_branch[1], nullptr};


    std::string elfName = "None";

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
