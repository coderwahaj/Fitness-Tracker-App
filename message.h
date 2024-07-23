#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
public:
    std::string sender;
    std::string receiver;
    std::string content;

    Message(std::string from, std::string to, std::string cont)
        : sender(from), receiver(to), content(cont) {}
};

#endif