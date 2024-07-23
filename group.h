#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

class Group {
public:
    std::string groupName;
    std::vector<std::string> members;  // Usernames of members

    Group(std::string name) : groupName(name) {}

    void addMember(const std::string& username) {
        members.push_back(username);
    }

    // More functionalities like sendGroupMessage, etc., can be added
};

#endif