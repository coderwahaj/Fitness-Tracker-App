#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

bool User::verifyPassword(const std::string& inputPassword) const {
    return inputPassword == password;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

void User::postExperience(const std::string& content, const std::string& filePath) {
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }
    outFile << "Username: " << username << "\n";
    outFile << "Content: " << content << "\n\n";
    std::cout << "Experience posted successfully!\n";
    outFile.close();
}

void User::deleteExperience(int postID, const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.find("Post ID: " + std::to_string(postID)) == std::string::npos) {
            lines.push_back(line);
        }
    }
    inFile.close();

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }
    outFile.close();

    auto it = std::find(postsIDs.begin(), postsIDs.end(), postID);
    if (it != postsIDs.end()) {
        postsIDs.erase(it);
        std::cout << "Experience deleted successfully!\n";
    }
    else {
        std::cout << "Experience not found!\n";
    }
}

void User::updateExperience(int postID, const std::string& newContent, const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.find("Post ID: " + std::to_string(postID)) != std::string::npos) {
            line = "Post ID: " + std::to_string(postID) + ", Username: " + username + ", Content: " + newContent;
        }
        lines.push_back(line);
    }
    inFile.close();

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }
    outFile.close();

    std::cout << "Experience updated successfully!\n";
}

void User::sendMessage(const std::string& sender, const std::string& receiver, const std::string& message, const std::string& filePath) {
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }
    outFile << "From: " << sender << "\n";
    outFile << "To: " << receiver << "\n";
    outFile << "Message: " << message << "\n\n";
    std::cout << "Message sent successfully!\n";
    outFile.close();
}

void User::manageGroups(const std::string& groupName, const std::string& member, const std::string& filePath) {
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }
    outFile << "Group: " << groupName << "\n";
    outFile << "Member: " << member << "\n\n";
    std::cout << "Member added to the group successfully!\n";
    outFile.close();
}
