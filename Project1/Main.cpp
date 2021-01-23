#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <forward_list>
#include <deque>

//Exercise 9.18
void GetAndPrintDEQUE()
{
    /*Exercise 9.18: Write a program to read a sequence of strings from the
        standard input into a deque.Use iterators to write a loop to print the
        elements in the deque.*/

    std::deque<std::string> deq1;
    std::string s;
    std::cout << "Please enter strings:   ";
    std::getline(std::cin, s);
    std::istringstream iss(s);
    while (iss >> s)
        deq1.insert(deq1.end(), s);
    for (auto it : deq1)
    {
        std::cout << it << std::endl;
    }
}
//Exercise 9.19
void GetAndPrintLIST()
{
    /* Exercise 9.19: Rewrite the program from the previous exercise to use a
            list.List the changes you needed to make.*/
    std::list<std::string> lis1;
    std::string s;
    std::cout << "Please enter strings:   ";
    std::getline(std::cin, s);
    std::istringstream iss(s);
    while (iss >> s)
        lis1.insert(lis1.end(), s);
    for (auto it : lis1)
    {
        std::cout << it << std::endl;
    }
}
//Exercise 9.20
void CopyElementsFromListToTwoDeques()
{
    /*Exercise 9.20: Write a program to copy elements from a list<int> into
        two deques.The even - valued elements should go into one deque and the
        odd ones into the other*/
    std::list<int> li = { 1,1,1,3,5,4,4,4,5,6,7 };
    std::deque<int> de1, de2;
     
    auto lit = li.cbegin();
   
    for (; lit != li.cend() ; ++lit)
        if ((*lit%2)==0) {
            de1.push_back(*lit);
        }
        else {
            de2.push_back(*lit);
        }
    std::cout << "List: " << std::endl;
    for (auto it : li)
    {
        std::cout << it << std::endl;
    }
    std::cout << "Deque1: " << std::endl;
    for (auto it : de1)
    {
        std::cout << it << std::endl;
    }
    std::cout << "Deque2: " << std::endl;
    for (auto it : de2)
    {
        std::cout << it << std::endl;
    }
}
//Exercise 9.26
void PrintVector(std::vector<int>& vect)
{
    for (auto &it : vect)
    {
        std::cout << it << "  ";
    }
}
void PrintList(std::list<int>& liss)
{
    for (auto& it : liss)
    {
        std::cout << it << "  ";
    }
}
void Exercise926()
{
    /*Exercise 9.26: Using the following definition of ia, copy ia into a vector
        and into a list.Use the single - iterator form of erase to remove the
        elements with odd values from your list and the even values from your
        vector.*/
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> vec;
    std::list<int> lis;
    for (auto it : ia)
    {
        vec.push_back(it);
        lis.push_back(it);
    }
    std::cout << "Old list: " << std::endl;
    PrintList(lis);
    std::cout << std::endl;
    std::cout << "Old vector: " << std::endl;
    PrintVector(vec);
    std::cout << std::endl;
    auto lit = lis.begin();
    while (lit != lis.end())
        if (*lit % 2) // if the element is odd
            lit = lis.erase(lit); // erase this element
        else
            ++lit;
    auto vit = vec.begin();
    while (vit != vec.end())
        if ((*vit % 2)==0) // if the element is odd
            vit = vec.erase(vit); // erase this element
        else
            ++vit;
    std::cout << "New list: " << std::endl;
    PrintList(lis);
    std::cout << std::endl;
    std::cout << "New vector: " << std::endl;
    PrintVector(vec);
    std::cout << std::endl;
}

int main() {
    
    
    return 0;
}