#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class Challenge {
private:
    int id;
    std::string name;
    std::string description;
    std::vector<std::string> participants;
    std::vector<int> progress; // Progress of participants

public:
    Challenge(int id, const std::string& name, const std::string& description);

    void displayChallengeDetails() const;
    void joinChallenge(const std::string& username);
    void updateProgress(const std::string& username, int progress);
    void updateLeaderboard();

    static std::vector<Challenge> loadChallengesFromFile(const std::string& filename);
    static void saveChallengesToFile(const std::vector<Challenge>& challenges, const std::string& filename);
};

#endif // CHALLENGE_H
