#include <iostream>
#include <string>
#include <random>
#include <map>
int main()
{
std::random_device rd;
std::uniform_int_distribution<int> guess (1, 100);
int x=guess(rd);
int y=0;

while(x!=y){
 std::cout<<"guess:";
std::cin>>y;
if(y>x) std::cout<<"too big!\n";
if(y<x) std::cout<<"too small!\n";

}
 std::cout<<"just right!\n";
return 0;
}
