#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    std::string username;
    std::string password;
    std::vector<int> postsIDs;  // Store post IDs for simplicity

public:
    User() = default;
    User(const std::string& username, const std::string& password);
    ~User() = default;

    bool verifyPassword(const std::string& inputPassword) const;
    //std::string getUsername() const;
    std::string getPassword() const;
    void setPassword(const std::string& newPassword);

    std::string getUsername() const;
    void postExperience(const std::string& content, const std::string& filePath);
    void deleteExperience(int postID, const std::string& filePath);
    void updateExperience(int postID, const std::string& newContent, const std::string& filePath);
    void sendMessage(const std::string& sender, const std::string& receiver, const std::string& message, const std::string& filePath);
    void manageGroups(const std::string& groupName, const std::string& member, const std::string& filePath);
};

#endif // USER_H