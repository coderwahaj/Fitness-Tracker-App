#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    std::string username;
    std::vector<int> postsIDs;  // Store post IDs for simplicity

    User(std::string name) : username(name) {}
    void postExperience(const std::string& content);
    void deleteExperience(int postID);
    void updateExperience(int postID, const std::string& newContent);
};

#endif