#include <iostream>
#include <vector>
#include <Windows.h>
#include <cassert>

enum Tasks
{
    A = 1,
    B,
    C
};

class Junior
{
private:
    int id = -1;
    int task = -1;
    class Middle* middle = nullptr;
    int middle_owner = -1;
public:
    Junior(class Middle* inMiddle, int id, int inTask, int inMiddleID)
    {
        this->middle = inMiddle;
        this->id = id;
        this->task = inTask;
        this->middle_owner = inMiddleID;
        std::cout << "      Junior hired with id " << this->id << " has task: ";
        if(Tasks::A == this->task)
            std::cout << "A" << " from " << this->middle_owner << " Middle" << std::endl;
        if(Tasks::B == this->task)
            std::cout << "B" << " from " << this->middle_owner << " Middle" << std::endl;
        if(Tasks::C == this->task)
            std::cout << "C" << " from " << this->middle_owner << " Middle" << std::endl;
    }

    int getCurrentTask()
    {
        return this->task;
    }
};

class Middle
{
private:
    int number_of_juniors = 0;
    Junior** junior_list = nullptr;
    std::vector<int> tasks = {};
    class Senior* senior = nullptr;
    int id = -1;
public:
    Middle(class Senior* inSenior, int id, std::vector<int> inTasks)
    {
        this->senior = inSenior;
        this->id = id;
        this->tasks = inTasks;
        std::cout << "  Middle hired with id " << id << std::endl;
        std::cout << "  TASKS for Middle: ";
        for(int i = 0; i < this->tasks.size(); i++)
        {
            if(Tasks::A == this->tasks[i])
                std::cout << "A" << " ";
            if(Tasks::B == this->tasks[i])
                std::cout << "B" << " ";
            if(Tasks::C == this->tasks[i])
                std::cout << "C" << " ";
        }
        std::cout << std::endl;
        hireJuniors();
    }

    void hireJuniors()
    {
        //generate amount of juniors
        std::srand(time(nullptr));
        Sleep(1001);
        this->number_of_juniors = (1 + (rand())%5);
        this->junior_list = new Junior*[this->number_of_juniors];

        for(int i = 0; i < this->number_of_juniors; i++)
        {
            junior_list[i] = new Junior(this, i, this->tasks[i], this->id);
        }
    }

    void tasksLeft()
    {
        std::vector<int> tmp_jun_tasks;
        for(int i = 0; i < this->number_of_juniors; i++)
        {
            tmp_jun_tasks.push_back(this->junior_list[i]->getCurrentTask());
        }
        std::cout << std::endl;
        std::cout << "MIDDLE with ID " << this->id << " HAS:" << std::endl;
        std::cout << "TASKS IN WORK: ";
        for(int i = 0; i < tmp_jun_tasks.size(); i++)
        {
            if(Tasks::A == this->tasks[i])
                std::cout << "A" << " ";
            if(Tasks::B == this->tasks[i])
                std::cout << "B" << " ";
            if(Tasks::C == this->tasks[i])
                std::cout << "C" << " ";
        }
        std::cout << std::endl;
        std::cout << "TASKS LEFT: ";
        for(int i = tmp_jun_tasks.size(); i < this->tasks.size(); i++)
        {
            if(Tasks::A == this->tasks[i])
                std::cout << "A" << " ";
            if(Tasks::B == this->tasks[i])
                std::cout << "B" << " ";
            if(Tasks::C == this->tasks[i])
                std::cout << "C" << " ";
        }
        std::cout << std::endl;
    }

};

class Senior
{
private:
    int number_of_middles = 0;
    std::vector<int> tasks = {};
    Middle** middle_list = nullptr;
public:
    Senior()
    {
        std::cout << "Senior generaring tasks. Please wait..." << std::endl;
        std::vector<int> tmp;

        //generate amount of middles
        std::srand(time(nullptr));
        Sleep(1001);
        this->number_of_middles = (1 + (rand())%5);

        //generate tasks
        for(int i = 0; i < this->number_of_middles*5; i++)
        {
            std::srand(time(nullptr));
            Sleep(1001);
            int rand_number = (1 + (rand())%3);
            tmp.push_back(rand_number);
        }
        //print tasks Senior has
        this->tasks = tmp;
        for(int i = 0; i < this->tasks.size(); i++)
        {
            if(Tasks::A == this->tasks[i])
                std::cout << "A" << " ";
            if(Tasks::B == this->tasks[i])
                std::cout << "B" << " ";
            if(Tasks::C == this->tasks[i])
                std::cout << "C" << " ";
        }
        std::cout << std::endl;
        //create middles
        hireMiddles();
    }

    void hireMiddles()
    {
        this->middle_list = new Middle*[this->number_of_middles];

        for(int i = 0, middle_id = 0 , j = 0; i < this->number_of_middles; i++)
        {
            std::vector<int> tmp;
            for(; j < this->tasks.size(); j++)
            {
                tmp.push_back(this->tasks[j]);
                if (tmp.size() == 5)
                {
                    middle_list[middle_id] = new Middle(this, middle_id, tmp);;
                    tmp.clear();
                    middle_id++;
                }
            }
        }
    }

    void getReportFromMiddle(int index)
    {
        assert(index >= 0 && index < this->number_of_middles);
        middle_list[index]->tasksLeft();
    }

    int getAmountOfMiddles()
    {
        return this->number_of_middles;
    }
};

int main()
{
    Senior* senior = new Senior();
    for(int i = 0; i < senior->getAmountOfMiddles(); i++)
    {
        senior->getReportFromMiddle(i);
    }
    delete senior;
    return 0;
}

