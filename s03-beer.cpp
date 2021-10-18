#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    auto const a=std::stoi(argv[1]);
    
    for(int i=a; i>0; i--){
    std::cout<<i<<" bottles of beer on the wall, "<<i<<" bottles of beer.\n";
    std::cout<<"Take one down, pass it around, "<<i-1<<" bottles of beer on the wall..\n";

}


    std::cout<<"No more bottles of beer on the wall, no more bottles of beer.\n";
    std::cout<<"Go to the store and buy some more, "<<a<<" bottles of beer on the wall....\n";
}



