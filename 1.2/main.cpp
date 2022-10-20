#include <iostream>
#include <string>
#include <sstream>

using namespace std;




int main(){

string buf1("1c0111001f010100061a024b53535009181c");
string buf2("686974207468652062756c6c277320657965");

auto it1=buf1.begin();
auto it2{buf2.begin()};
stringstream ss;

while(it1 < buf1.end()){
int fir = stoi(string(it1,it1+2),nullptr,16);
int sec = stoi(string(it2,it2+2),nullptr,16);
ss<<std::hex<<(fir^sec);
it1+=2; it2+=2;
;
}
cout<<ss.str();
    return 0;
}