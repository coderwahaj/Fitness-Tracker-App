#include "nutrition.h"
#include <fstream>

Nutrition::Nutrition() {}

Nutrition::Nutrition(const std::string& food, double cal, double prot, double carb, double fat)
    : foodName(food), calories(cal), protein(prot), carbohydrates(carb), fat(fat) {}

std::string Nutrition::getFoodName() const {
    return foodName;
}
std::istream& operator>>(std::istream& is, Nutrition& nutrition) {
    is >> nutrition.foodName >> nutrition.calories >> nutrition.protein >> nutrition.carbohydrates >> nutrition.fat;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Nutrition& nutrition) {
    os << nutrition.foodName << " " << nutrition.calories << " " << nutrition.protein << " " << nutrition.carbohydrates << " " << nutrition.fat << "\n";
    return os;
}


double Nutrition::getCalories() const {
    return calories;
}

double Nutrition::getProtein() const {
    return protein;
}

double Nutrition::getCarbohydrates() const {
    return carbohydrates;
}

double Nutrition::getFat() const {
    return fat;
}

void Nutrition::setFoodName(const std::string& food) {
    foodName = food;
}

void Nutrition::setCalories(double cal) {
    calories = cal;
}

void Nutrition::setProtein(double prot) {
    protein = prot;
}

void Nutrition::setCarbohydrates(double carb) {
    carbohydrates = carb;
}

void Nutrition::setFat(double fat) {
    fat = fat;
}

void Nutrition::saveToFile(std::ofstream& file) {
    file << foodName << " " << calories << " " << protein << " " << carbohydrates << " " << fat << "\n";
}

void Nutrition::loadFromFile(std::ifstream& file) {
    file >> foodName >> calories >> protein >> carbohydrates >> fat;
}