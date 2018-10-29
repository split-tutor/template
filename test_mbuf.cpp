// tset_mbuf.cpp - test generic buffer implementations

#include <iostream>
#include <string>

#include "mbuf.h"

using StringTuple = Tuple<std::string, std::string>;

int main()
{
    Buf<float> fbuf = Buf<float>();

    for (int i = 0; i < Buf<float>::DEFAULT_CAP; i++) {
        fbuf[i] = (float) i;
    }

    std::cout << "fbuf: " << fbuf << '\n';

    auto phoneNumbers = Buf<Tuple<std::string, std::string>>(4);
    phoneNumbers[0] = StringTuple("amy", "111-222-3333");
    phoneNumbers[1] = StringTuple("carl", "carl@example.com");
    phoneNumbers[2] = StringTuple("julia", "julia@example.com");
    phoneNumbers[3] = StringTuple("amy", "111-222-3333");
    
    std::cout << "phone book:\n" <<phoneNumbers << '\n';

    auto emails = Buf<Tuple<std::string, std::string>>(4);
    emails[0] = StringTuple("amy", "111-222-3333");
    emails[1] = StringTuple("james", "222-333-4444");
    emails[2] = StringTuple("amy", "333-444-5555"); 
    emails[3] = StringTuple("carl", "444-555-6666");

    std::cout << "e-mail book:\n" << emails << '\n';
}