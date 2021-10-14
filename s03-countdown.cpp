#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    argc++;
    auto const a=std::stoi(argv[1]);
    for(int i=a+1; i--; i<0) std::cout<<i<<"...\n";
    return 0;

}
