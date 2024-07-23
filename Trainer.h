//#ifndef TRAINER_H
//#define TRAINER_H
//
//#include "User.h"
//
//class Trainer : public User {
//public:
//    Trainer();
//    Trainer(const std::string& username, const std::string& password);
//};
//
//#endif // TRAINER_H
#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>

class Trainer {
private:
    std::string name;
    std::vector<std::string> experiences;
    std::vector<std::string> successStories;
    std::vector<std::pair<std::string, double>> pricingDetails; // pair of training type and price

public:
    Trainer(const std::string& name);
    Trainer(const std::string& username, const std::string& password);
    void addExperience(const std::string& experience);
    void addSuccessStory(const std::string& story);
    void addPricingDetail(const std::string& trainingType, double price);
    void displayInformation() const;
    void editInformation();
};

#endif