#include "Challenge.h"

Challenge::Challenge(int id, const std::string& name, const std::string& description)
    : id(id), name(name), description(description) {}

void Challenge::displayChallengeDetails() const {
    std::cout << "Challenge ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
}

void Challenge::joinChallenge(const std::string& username) {
    participants.push_back(username);
    progress.push_back(0);
    std::cout << username << " has joined the challenge!" << std::endl;
}

void Challenge::updateProgress(const std::string& username, int newProgress) {
    auto it = std::find(participants.begin(), participants.end(), username);
    if (it != participants.end()) {
        int index = std::distance(participants.begin(), it);
        progress[index] = newProgress;
        std::cout << username << "'s progress updated to " << newProgress << "%" << std::endl;
    }
    else {
        std::cerr << "Participant not found." << std::endl;
    }
}

void Challenge::updateLeaderboard() {
    std::vector<std::pair<std::string, int>> leaderboard;
    for (size_t i = 0; i < participants.size(); ++i) {
        leaderboard.emplace_back(participants[i], progress[i]);
    }
    std::sort(leaderboard.begin(), leaderboard.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });

    std::cout << "Leaderboard:\n";
    for (const auto& entry : leaderboard) {
        std::cout << entry.first << ": " << entry.second << " points\n";
    }
}

std::vector<Challenge> Challenge::loadChallengesFromFile(const std::string& filename) {
    std::vector<Challenge> challenges;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return challenges;
    }
    int id;
    std::string name, description;
    while (file >> id >> std::ws && std::getline(file, name) && std::getline(file, description)) {
        challenges.emplace_back(id, name, description);
    }
    file.close();
    return challenges;
}

void Challenge::saveChallengesToFile(const std::vector<Challenge>& challenges, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    for (const auto& challenge : challenges) {
        file << challenge.id << "\n" << challenge.name << "\n" << challenge.description << "\n";
    }
    file.close();
}
