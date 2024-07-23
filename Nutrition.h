#pragma once
#ifndef NUTRITION_H
#define NUTRITION_H

#include <string>

class Nutrition {
private:
    std::string foodName;
    double calories;
    double protein;
    double carbohydrates;
    double fat;

public:
    Nutrition(); // Constructor
    Nutrition(const std::string& food, double cal, double prot, double carb, double fat); // Parameterized constructor
    friend std::istream& operator>>(std::istream& is, Nutrition& nutrition);
    friend std::ostream& operator<<(std::ostream& os, const Nutrition& nutrition);

    // Getter methods
    std::string getFoodName() const;
    double getCalories() const;
    double getProtein() const;
    double getCarbohydrates() const;
    double getFat() const;

    // Setter methods
    void setFoodName(const std::string& food);
    void setCalories(double cal);
    void setProtein(double prot);
    void setCarbohydrates(double carb);
    void setFat(double fat);

    // File handling methods
    void saveToFile(std::ofstream& file);
    void loadFromFile(std::ifstream& file);
};

#endif
