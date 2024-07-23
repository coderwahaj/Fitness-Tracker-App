#pragma once
#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>

class Workout {
private:
    std::string workoutName;
    double caloriesBurned;

public:
    Workout(); // Constructor
    Workout(const std::string& name, double cal); // Parameterized constructor
    friend std::istream& operator>>(std::istream& is, Workout& workout);
    friend std::ostream& operator<<(std::ostream& os, const Workout& workout);
    // Getter methods
    std::string getWorkoutName() const;
    double getCaloriesBurned() const;

    // Setter methods
    void setWorkoutName(const std::string& name);
    void setCaloriesBurned(double cal);

    // File handling methods
    void saveToFile(std::ofstream& file);
    void loadFromFile(std::ifstream& file);
};

#endif
