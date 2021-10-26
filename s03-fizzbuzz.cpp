#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    auto const a=std::stoi(argv[1]);
    
    for(int i=1; i<=a; i++){
		std::cout<<i<<" ";
    if (i%3==0) std::cout<<"Fizz";
    if (i%5==0) std::cout<<"Buzz";
    std::cout<<"\n";
}

}
