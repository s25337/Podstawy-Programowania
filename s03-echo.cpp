#include <iostream>
#include <string>
#include <string.h>

bool czyN, czyR, czyL;

auto main(int argc, char* argv[]) -> int
{
//std::cout<<":"<<argc<<"\n";
char n[]="-n";
char r[]="-r";
char l[]="-l";

    for(int i=0; i<4; i++){
if(strcmp(argv[i],n)==0) czyN=1;
if(strcmp(argv[i],r)==0) czyR=1;
if(strcmp(argv[i],l)==0) czyL=1;
} 

for(int i=1; i<argc; i++){
if(czyR==1) std::cout<<argv[argc-i];
else std::cout<<argv[i];
if (czyL==0) std::cout<<" ";
if(czyL==1 && i!=argc-1) std::cout<<"\n";
if(czyN==0 && i==argc-1) std::cout<<"\n";
}
    return 0;
}
