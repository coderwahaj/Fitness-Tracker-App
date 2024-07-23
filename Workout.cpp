#include "workout.h"
#include <fstream>

Workout::Workout() {}

Workout::Workout(const std::string& name, double cal)
    : workoutName(name), caloriesBurned(cal) {}

std::string Workout::getWorkoutName() const {
    return workoutName;
}
std::istream& operator>>(std::istream& is, Workout& workout) {
    is >> workout.workoutName >> workout.caloriesBurned;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Workout& workout) {
    os << workout.workoutName << " " << workout.caloriesBurned << "\n";
    return os;
}



double Workout::getCaloriesBurned() const {
    return caloriesBurned;
}

void Workout::setWorkoutName(const std::string& name) {
    workoutName = name;
}

void Workout::setCaloriesBurned(double cal) {
    caloriesBurned = cal;
}

void Workout::saveToFile(std::ofstream& file) {
    file << workoutName << " " << caloriesBurned << "\n";
}

void Workout::loadFromFile(std::ifstream& file) {
    file >> workoutName >> caloriesBurned;
}