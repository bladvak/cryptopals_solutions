#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

const char* hexToBin(char c);

static const std::string base64 =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

static short padd = 0;

int main(){

std::string hex_string("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");

std::stringstream sstr;

for(auto &c : hex_string){
    sstr << hexToBin(c);
}


//add padding if needed
if( (sstr.str().size()%3) == 1)
   {sstr << "0000"; padd = 1; }
else if ((sstr.str().size()%3) == 2)
    {sstr << "00"; padd = 2; }

string bin_str = sstr.str();
stringstream encoded;

auto beg = bin_str.begin();
while(beg < bin_str.end()) {

    encoded << base64[ std::stoi(string(beg,beg+6),nullptr,2) ];
    beg +=6;
}
if (padd == 1)
    encoded << "==";
else if (padd==2)
    encoded << "=";

std::cout<<encoded.str();

return 0;
}

const char* hexToBin(char c) {
    switch(tolower(c)){
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
    }
}
