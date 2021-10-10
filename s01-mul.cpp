#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if(argc<3) return 0;

    auto const a=std::stoi(argv[1]);
    auto const b=std::stoi(argv[2]);
    std::cout<<(a*b)<<"\n";
    return 0;

}
