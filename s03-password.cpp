#include <iostream>
#include <string>
auto main(int argc, char* argv[]) -> int
{
	auto password=std::string{};
	while(true){
	std::cout<<"password: ";
	std::getline(std::cin, password);
	if(password==argv[1]){
	std::cout<<"ok!"<<"\n";
	break;
	}
	}
    return 0;
}
