#ifndef REGULARUSER_H
#define REGULARUSER_H

#include "User.h"

class RegularUser : public User {
public:
    RegularUser();
    RegularUser(const std::string& username, const std::string& password);
};

#endif // REGULARUSER_H
