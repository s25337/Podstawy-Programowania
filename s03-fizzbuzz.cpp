#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    auto const a=std::stoi(argv[1]);
    if (a%3==0) std::cout<<"Fizz";
    if (a%5==0) std::cout<<"Buzz";
    std::cout<<"\n";

}
