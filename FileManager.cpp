#include <fstream>
#include <vector>
#include "User.h"

class FileManager {
public:
    static bool loadUsers(std::vector<User>& users, const std::string& filename) {
        std::ifstream file(filename);
        std::string username, password;
        while (file >> username >> password) {
            users.emplace_back(username, password);
        }
        file.close();
        return !users.empty();
    }

    static void saveUsers(const std::vector<User>& users, const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& user : users) {
            file << user.getUsername() << " " << user.getPassword() << std::endl;
        }
        file.close();
    }
};