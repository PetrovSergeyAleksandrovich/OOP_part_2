#include <iostream>
#include <Windows.h>

class Elf
{
private:
    int name = -1;
    class BigBranch* big_branch = nullptr;
public:

    Elf(class BigBranch* inBigBranch)
    {
        std::srand(time(0));
        int rand_number = (1 + rand()%1000000);
        Sleep(1001);
        this->big_branch = inBigBranch;
        this->name = rand_number;
    }

    int getName()
    {
        return this->name;
    }
};

class MidBranch
{
private:
    Elf* elf = nullptr;
    class BigBranch* big_branch = nullptr;
public:
    MidBranch(class BigBranch* inBigBranch)
    {
        this->big_branch = inBigBranch;
        std::cout << "      Mid Branch Created with Elf id ";
        elf = new Elf(this->big_branch);
        std::cout <<elf->getName() << std::endl;
    }

    int getElf()
    {
        return elf->getName();
    }

};

class BigBranch
{
private:
    int number_of_mid_branches = 2;
    MidBranch** mid_branches = nullptr;
public:
    BigBranch()
    {
        std::cout << "  Big Branch Created " << std::endl;

        std::srand(time(0));
        int rand_number = (2 + rand()%2);

        this->number_of_mid_branches = rand_number;

        mid_branches = new MidBranch*[rand_number];
        for(int i = 0; i < rand_number; i++)
        {
            mid_branches[i] = new MidBranch(this);
        }
    }

    MidBranch* getMidBranch(int index)
    {
        if(index < 0) return nullptr;
        if(index >= this->number_of_mid_branches) return nullptr;
        return mid_branches[index];
    }

    int getNumberOfMidBranches()
    {
        return number_of_mid_branches;
    }

};

class Tree
{
private:
    int number_of_big_branches = 3;
    BigBranch** big_branches = nullptr;
public:
    Tree()
    {
        std::cout << "\nTree Created " << std::endl;
        std::srand(time(0));
        Sleep(1001);
        int rand_number = (3 + rand()%3);

        this->number_of_big_branches = rand_number;

        big_branches = new BigBranch*[rand_number];
        for(int i = 0; i < rand_number; i++)
        {
            big_branches[i] = new BigBranch;
        }
    }

    BigBranch* getBigBranch(int index)
    {
        if(index < 0) return nullptr;
        if(index >= this->number_of_big_branches) return nullptr;
        return big_branches[index];
    }

    int getNumberOfBigBranches()
    {
        return number_of_big_branches;
    }

};

int main()
{
    int user_input = 0;
    BigBranch* found = nullptr;
    const int trees_amount = 5;
    Tree* trees = new Tree[trees_amount];
    Elf zarok = nullptr;

    std::cout << "\nType Elf's number at forest to search: " ;
    std::cin >> user_input;

    for(int i = 0; i < trees_amount; i++)
    {
        for(int j = 0; j < (trees+i)->getNumberOfBigBranches(); j++)
        {
            for(int k = 0; k < (trees+i)->getBigBranch(j)->getNumberOfMidBranches(); k++)
            {
                int Elf_number = (trees+i)->getBigBranch(j)->getMidBranch(k)->getElf();

                if(Elf_number == user_input)
                {
                    found = (trees+i)->getBigBranch(j);
                    std::cout << "Elf exists with neigbours: ";
                    for(int n = 0; k < (trees+i)->getBigBranch(j)->getNumberOfMidBranches(); n++)
                    {
                       std::cout << (trees+i)->getBigBranch(j)->getMidBranch(n)->getElf() << " ";
                    }
                    break;
                }
            }
            if(found != nullptr) break;
        }
        if(found != nullptr) break;

    }

    delete[] trees;
    return 0;
}
