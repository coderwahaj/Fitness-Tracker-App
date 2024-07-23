#include <iostream>
#include <vector>
#include<string>
#include <limits>
#include <cstdlib> 
#include "User.h"
#include "nutrition.h"
#include "FileManager.cpp" 
#include "Workout.h"
#include "Post.h"
#include "Message.h"
#include "Group.h"
#include "Challenge.h"
using namespace std;
void clearScreen() {
#if defined _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMainMenu() {
    std::cout << "Welcome to FitConnect!\n";
    std::cout << "Select your role:\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Trainer\n";
    std::cout << "3. Regular User\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void displayMenu() {
    std::cout << "1. Sign Up\n";
    std::cout << "2. Login\n";
    std::cout << "3. Reset Password\n";
    std::cout << "4. Forgot Password\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}

std::string determineFilePath(int userType) {
    switch (userType) {
    case 1: return "admin.txt";
    case 2: return "trainer.txt";
    case 3: return "users.txt";
    default: return "users.txt"; // Default to regular user for safety
    }
}
void displayUserMenu() {
    std::cout << "USER MENU\n"; // Print "USER MENU" at the top
    std::cout << "1. Nutrition Tracking\n";
    std::cout << "2. Workout Tracking\n";
    std::cout << "3. Social Interaction\n";
    std::cout << "4. Progress Analysis\n";
    std::cout << "5. Challenges and Competitions\n";
    std::cout << "6. Location-Based Features\n";
    std::cout << "7. Back to Main Menu\n"; // Updated option number
    std::cout << "Enter your choice: ";
}

void SocialMenu() {
    std::cout << "\n---- Social Interaction Social Menu ----\n";
    std::cout << "1. Post Experience\n";
    std::cout << "2. Delete Experience\n";
    std::cout << "3. Update Experience\n";
    std::cout << "4. Send Message\n";
    std::cout << "5. Manage Groups\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

void addNutrition() {
    std::ofstream outFile("nutrition_data.txt", std::ios::app); // Open file in append mode
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }

    std::string foodName;
    double calories, protein, carbohydrates, fat;

    std::cout << "Enter food name: ";
    std::cin >> foodName;
    std::cout << "Enter calories: ";
    std::cin >> calories;
    std::cout << "Enter protein: ";
    std::cin >> protein;
    std::cout << "Enter carbohydrates: ";
    std::cin >> carbohydrates;
    std::cout << "Enter fat: ";
    std::cin >> fat;

    Nutrition newNutrition(foodName, calories, protein, carbohydrates, fat);
    newNutrition.saveToFile(outFile);

    std::cout << "Nutrition information added successfully!\n";

    outFile.close();
}



void deleteNutrition() {
    std::ifstream inFile("nutrition_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Error: Unable to create temporary file!\n";
        return;
    }

    std::string foodNameToDelete;
    std::cout << "Enter the name of the food to delete: ";
    std::cin >> foodNameToDelete;

    bool found = false;
    Nutrition nutrition;

    while (inFile >> nutrition) {
        if (nutrition.getFoodName() == foodNameToDelete) {
            found = true;
            std::cout << "Nutrition information for " << foodNameToDelete << " deleted.\n";
        }
        else {
            tempFile << nutrition;
        }
    }

    if (!found) {
        std::cout << "Nutrition information for " << foodNameToDelete << " not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove("nutrition_data.txt");
    rename("temp.txt", "nutrition_data.txt");
}


void updateNutrition() {
    std::ifstream inFile("nutrition_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Error: Unable to create temporary file!\n";
        inFile.close();
        return;
    }

    std::string foodNameToUpdate;
    std::cout << "Enter the name of the food to update: ";
    std::cin >> foodNameToUpdate;

    Nutrition nutrition;
    bool found = false;

    while (inFile >> nutrition) {
        if (nutrition.getFoodName() == foodNameToUpdate) {
            found = true;
            std::cout << "Enter new information for " << foodNameToUpdate << ":\n";
            std::cout << "1. Change food name\n";
            std::cout << "2. Change calories\n";
            std::cout << "3. Change protein\n";
            std::cout << "4. Change carbohydrates\n";
            std::cout << "5. Change fat\n";
            std::cout << "6. Finish updating\n";
            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::string newName;
                std::cout << "Enter new food name: ";
                std::cin >> newName;
                nutrition.setFoodName(newName);
                break;
            }
            case 2: {
                double newCalories;
                std::cout << "Enter new calories: ";
                std::cin >> newCalories;
                nutrition.setCalories(newCalories);
                break;
            }
            case 3: {
                double newProtein;
                std::cout << "Enter new protein: ";
                std::cin >> newProtein;
                nutrition.setProtein(newProtein);
                break;
            }
            case 4: {
                double newCarbohydrates;
                std::cout << "Enter new carbohydrates: ";
                std::cin >> newCarbohydrates;
                nutrition.setCarbohydrates(newCarbohydrates);
                break;
            }
            case 5: {
                double newFat;
                std::cout << "Enter new fat: ";
                std::cin >> newFat;
                nutrition.setFat(newFat);
                break;
            }
            case 6:
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
            tempFile << nutrition; // Write the updated nutrition object to the temporary file
            std::cout << "Nutrition information updated successfully!\n";
        }
        else {
            tempFile << nutrition; // Write the unchanged nutrition object to the temporary file
        }
    }

    if (!found) {
        std::cout << "Nutrition information for " << foodNameToUpdate << " not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove("nutrition_data.txt");
    rename("temp.txt", "nutrition_data.txt");
}
void addWorkout() {
    std::ofstream outFile("workout_data.txt", std::ios::app); // Open file in append mode
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!\n";
        return;
    }

    std::string workoutName;
    double caloriesBurned;

    std::cout << "Enter workout name: ";
    std::cin >> workoutName;
    std::cout << "Enter calories burned: ";
    std::cin >> caloriesBurned;

    Workout newWorkout(workoutName, caloriesBurned);
    newWorkout.saveToFile(outFile);

    std::cout << "Workout information added successfully!\n";

    outFile.close();
}


void deleteWorkout() {
    std::ifstream inFile("workout_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Error: Unable to create temporary file!\n";
        return;
    }

    std::string workoutNameToDelete;
    std::cout << "Enter the name of the workout to delete: ";
    std::cin >> workoutNameToDelete;

    bool found = false;
    Workout workout;

    while (inFile >> workout) {
        if (workout.getWorkoutName() == workoutNameToDelete) {
            found = true;
            std::cout << "Workout information for " << workoutNameToDelete << " deleted.\n";
        }
        else {
            tempFile << workout;
        }
    }

    if (!found) {
        std::cout << "Workout information for " << workoutNameToDelete << " not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove("workout_data.txt");
    rename("temp.txt", "workout_data.txt");
}


void updateWorkout() {
    std::ifstream inFile("workout_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Error: Unable to create temporary file!\n";
        inFile.close();
        return;
    }

    std::string workoutNameToUpdate;
    std::cout << "Enter the name of the workout to update: ";
    std::cin >> workoutNameToUpdate;

    Workout workout;
    bool found = false;

    while (inFile >> workout) {
        if (workout.getWorkoutName() == workoutNameToUpdate) {
            found = true;
            std::cout << "Enter new information for " << workoutNameToUpdate << ":\n";
            std::cout << "1. Change workout name\n";
            std::cout << "2. Change calories burned\n";
            std::cout << "3. Finish updating\n";
            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::string newName;
                std::cout << "Enter new workout name: ";
                std::cin >> newName;
                workout.setWorkoutName(newName);
                break;
            }
            case 2: {
                double newCalories;
                std::cout << "Enter new calories burned: ";
                std::cin >> newCalories;
                workout.setCaloriesBurned(newCalories);
                break;
            }
            case 3:
                break;
            default:
                std::cout << "Invalid choice!\n";
            }
            tempFile << workout; // Write the updated workout object to the temporary file
            std::cout << "Workout information updated successfully!\n";
        }
        else {
            tempFile << workout; // Write the unchanged workout object to the temporary file
        }
    }

    if (!found) {
        std::cout << "Workout information for " << workoutNameToUpdate << " not found.\n";
    }

    inFile.close();
    tempFile.close();

    remove("workout_data.txt");
    rename("temp.txt", "workout_data.txt");
}



void calorieConsumption() {
    std::ifstream inFile("workout_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    double totalCalories = 0.0;
    Workout workout;

    while (inFile >> workout) {
        totalCalories += workout.getCaloriesBurned();
    }

    std::cout << "Total calorie consumption for all workouts: " << totalCalories << " calories\n";

    inFile.close();
}


void recommendation() {
    std::ifstream inFile("workout_data.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading!\n";
        return;
    }

    double totalCalories = 0.0;
    Workout workout;

    while (inFile >> workout) {
        totalCalories += workout.getCaloriesBurned();
    }

    inFile.close();

    if (totalCalories < 1500)
    {
        std::cout << "Recommendation: You have burned fewer calories than recommended for a healthy lifestyle.\n";
    }
    else if (totalCalories < 2500)
    {
        std::cout << "Recommendation: You have burned a good amount of calories. Keep it up!\n";
    }
    else
    {
        std::cout << "Recommendation: You have burned a lot of calories. Make sure to replenish your energy.\n";
    }
}

class Activity {
protected:
    string name;
    double caloriesBurned;
public:
    Activity(string n, double c) : name(n), caloriesBurned(c) {}
    void display();
    string getName() const { return name; }
    double getCaloriesBurned() const { return caloriesBurned; }
};

class LocationBasedActivity {
protected:
    string locationName;
    vector<Activity*> activities;
public:
    LocationBasedActivity(string loc) : locationName(loc) {}
    void addActivity(Activity* activity) {
        activities.push_back(activity);
    }
    void displayActivities() const {
        cout << "Available activities at " << locationName << ":\n";
        for (size_t i = 0; i < activities.size(); ++i) {
            cout << i + 1 << ". " << activities[i]->getName() << endl;
        }
    }
    Activity* selectActivity(int choice) const {
        if (choice >= 1 && choice <= activities.size()) {
            return activities[choice - 1];
        }
        else {
            return nullptr;
        }
    }
    string getLocationName() const { return locationName; }
};

class Park : public LocationBasedActivity {
public:
    Park() : LocationBasedActivity("Park") {
        addActivity(new Activity("Jogging", 5.0));
        addActivity(new Activity("Cycling", 8.0));
        addActivity(new Activity("Swimming", 10.0));
    }
};

class Gym : public LocationBasedActivity {
public:
    Gym() : LocationBasedActivity("Gym") {
        addActivity(new Activity("Weightlifting", 6.0));
        addActivity(new Activity("Treadmill", 7.0));
        addActivity(new Activity("Elliptical", 9.0));
    }
};

class Office : public LocationBasedActivity {
public:
    Office() : LocationBasedActivity("Office") {
        addActivity(new Activity("Desk Exercises", 3.0));
    }
};

class Home : public LocationBasedActivity {
public:
    Home() : LocationBasedActivity("Home") {
        addActivity(new Activity("Yoga", 4.0));
        addActivity(new Activity("Pilates", 5.0));
    }
};

class FitnessApp {
private:
    vector<LocationBasedActivity*> locations;
public:
    FitnessApp() {
        locations.push_back(new Park());
        locations.push_back(new Gym());
        locations.push_back(new Office());
        locations.push_back(new Home());
    }
    ~FitnessApp() {
        for (LocationBasedActivity* loc : locations) {
            delete loc;
        }
    }
    void displayLocations() const {
        cout << "Select a location:\n";
        for (size_t i = 0; i < locations.size(); ++i) {
            cout << i + 1 << ". " << locations[i]->getLocationName() << endl;
        }
    }
    LocationBasedActivity* selectLocation(int choice) const {
        if (choice >= 1 && choice <= locations.size()) {
            return locations[choice - 1];
        }
        else {
            return nullptr;
        }
    }
};

void saveData(const string& location, const string& activity, double caloriesBurned) {
    ofstream file("fitness_data.txt", ios::app);
    if (file.is_open()) {
        file << "Location: " << location << ", Activity: " << activity << ", Calories Burned: " << caloriesBurned << endl;
        file.close();
        cout << "Data saved successfully.\n";
    }
    else {
        cout << "Error: Unable to save data.\n";
    }
}

int main()
{

    while (true)
    {

        clearScreen();
        displayMainMenu();

        int userType;
        std::cin >> userType;
        if (userType == 4) break; // Exit option
        std::string filePath = determineFilePath(userType);
        std::vector<User> users;
        FileManager::loadUsers(users, filePath);

        while (true) {
            char B;
        B:
            clearScreen();
            displayMenu();
            int choice;
            std::cin >> choice;

            if (choice == 5) break; // Back to Main Menu

            std::string username, password, newPassword;
            switch (choice) {
            case 1: // Sign Up
                std::cout << "Enter username: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                users.emplace_back(username, password);
                FileManager::saveUsers(users, filePath);
                std::cout << "User signed up successfully!\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            case 2: { // Login
                std::cout << "Enter username: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input buffer
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                bool loginSuccess = false;
                for (auto& user : users) {
                    if (user.getUsername() == username && user.verifyPassword(password)) {
                        loginSuccess = true;
                        std::cout << "Login successful!\n";
                        std::cout << "Press Enter to continue...\n";
                        std::cin.get(); // Wait for user to press Enter
                        break;
                    }
                }

                if (!loginSuccess) {
                    std::cout << "Invalid username or password.\n";
                    std::cout << "Press Enter to continue...\n";
                    std::cin.get(); // Wait for user to press Enter
                    continue; // Go back to the main menu loop
                }
                char A;
            A:
                clearScreen(); // Clear the screen before displaying USER MENU
                displayUserMenu();

                int userChoice;
                std::cin >> userChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input buffer again after numeric input
                std::cin.get();
                clearScreen();
                switch (userChoice) {
                case 1: {
                    // Code to proceed with nutrition tracking module
                    int nutritionChoice;
                    do {
                        std::cout << "Nutrition Tracking Menu\n";
                        std::cout << "1. Add Nutrition\n";
                        std::cout << "2. Delete Nutrition\n";
                        std::cout << "3. Update Nutrition\n";
                        std::cout << "4. Back to User Menu\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> nutritionChoice;

                        switch (nutritionChoice) {
                        case 1:
                            addNutrition();
                            break;
                        case 2:
                            deleteNutrition();
                            break;
                        case 3:
                            updateNutrition();
                            break;
                        case 4:
                            std::cout << "Returning to  Nutrition Tracking Menu...\n";
                            std::cin.get();
                            goto A;// Wait for user to press Enter
                            break;
                        default:
                            std::cout << "Invalid choice!\n";
                            std::cin.get(); // Wait for user to press Enter
                        }
                    } while (nutritionChoice != 4);
                    break;
                }
                case 2: {
                    // Code to proceed with workout tracking module
                    int workoutChoice;
                    clearScreen();
                    do {
                        std::cout << "Workout Tracking Menu\n";
                        std::cout << "1. Add Workout\n";
                        std::cout << "2. Delete Workout\n";
                        std::cout << "3. Update Workout\n";
                        std::cout << "4. Calorie Consumption for each Workout\n";
                        std::cout << "5. Recommendation to Users\n";
                        std::cout << "6. Back to User Menu\n";
                        std::cout << "Enter your choice: ";
                        std::cin >> workoutChoice;

                        switch (workoutChoice) {
                        case 1:
                            addWorkout();
                            break;
                        case 2:
                            deleteWorkout();
                            break;
                        case 3:
                            updateWorkout();
                            break;
                        case 4:
                            calorieConsumption();
                            break;
                        case 5:
                            recommendation();
                            break;
                        case 6:
                            std::cout << "Returning to User menu...\n";
                            goto A;
                            break;
                        default:
                            std::cout << "Invalid choice!\n";
                        }
                    } while (workoutChoice != 6);
                    break;
                }
                case 3:
                {
                    std::vector<User> users;
                    std::vector<Group> groups;
                    int choice;
                    string username, content, groupName;
                    int postID;
                    std::string sender, receiver, message;
                    do {
                        SocialMenu();
                        cin >> choice;
                        switch (choice) {
                        case 1: // Post Experience
                            std::cout << "Enter username: ";
                            std::cin >> username;
                            std::cout << "Enter content: ";
                            std::cin.ignore(); // clear the newline character from the input buffer
                            std::getline(std::cin, content);
                            for (auto& user : users) {
                                if (user.getUsername() == username) {
                                    user.postExperience(content, "experiences.txt");
                                    std::cout << "Experience posted!\n";
                                }
                            }
                            break;
                        case 2: // Delete Experience
                            std::cout << "Enter username: ";
                            std::cin >> username;
                            std::cout << "Enter post ID to delete: ";
                            std::cin >> postID;
                            for (auto& user : users) {
                                if (user.getUsername() == username) {
                                    user.deleteExperience(postID, "experiences.txt");
                                    std::cout << "Experience deleted!\n";
                                }
                            }
                            break;
                        case 3: // Update Experience
                            std::cout << "Enter username: ";
                            std::cin >> username;
                            std::cout << "Enter post ID to update: ";
                            std::cin >> postID;
                            std::cout << "Enter new content: ";
                            std::cin.ignore();
                            std::getline(std::cin, content);
                            for (auto& user : users) {
                                if (user.getUsername() == username) {
                                    user.updateExperience(postID, content, "experiences.txt");
                                    std::cout << "Experience updated!\n";
                                }
                            }
                            break;
                        case 4: // Send Message
                            std::cout << "Enter sender username: ";
                            std::cin >> sender;
                            std::cout << "Enter receiver username: ";
                            std::cin >> receiver;
                            std::cout << "Enter message: ";
                            std::cin.ignore();
                            std::getline(std::cin, message);
                            for (auto& user : users) {
                                if (user.getUsername() == sender) {
                                    user.sendMessage(sender, receiver, message, "messages.txt");
                                    std::cout << "Message sent!\n";
                                }
                            }
                            break;
                        case 5: // Manage Groups
                            std::cout << "Enter group name to add a member: ";
                            std::cin >> groupName;
                            std::cout << "Enter username to add to group: ";
                            std::cin >> username;
                            for (auto& user : users) {
                                if (user.getUsername() == username) {
                                    user.manageGroups(groupName, username, "groups.txt");
                                    std::cout << username << " added to " << groupName << "\n";
                                }
                            }
                            break;
                        case 6: // Exit
                            std::cout << "Exiting application.\n";
                            break;
                        default:
                            std::cout << "Invalid option, please try again.\n";
                            break;
                        }
                    } while (choice != 6);
                }
                case 5:
                {
                    std::vector<Challenge> challenges = Challenge::loadChallengesFromFile("challenges.txt");
                    int choice;
                    do {
                        std::cout << "\nChallenges Menu:\n"
                            << "1. View Available Challenges\n"
                            << "2. Join a Challenge\n"
                            << "3. Update Challenge Progress\n"
                            << "4. View Challenge Leaderboard\n"
                            << "5. Back to User Menu\n"
                            << "Enter your choice: ";
                        std::cin >> choice;

                        switch (choice) {
                        case 1:
                            for (const auto& challenge : challenges) {
                                challenge.displayChallengeDetails();
                            }
                            break;
                        case 2: {
                            int joinId;
                            std::cout << "Enter the ID of the challenge you want to join: ";
                            std::cin >> joinId;
                            if (joinId >= 1 && joinId <= static_cast<int>(challenges.size())) {
                                std::string username;
                                std::cout << "Enter your username: ";
                                std::cin >> username;
                                challenges[joinId - 1].joinChallenge(username);
                            }
                            else {
                                std::cout << "Invalid challenge ID!\n";
                            }
                            break;
                        }
                        case 3: {
                            int progressId;
                            std::cout << "Enter the ID of the challenge to update progress: ";
                            std::cin >> progressId;
                            if (progressId >= 1 && progressId <= static_cast<int>(challenges.size())) {
                                std::string username;
                                int progress;
                                std::cout << "Enter your username: ";
                                std::cin >> username;
                                std::cout << "Enter your progress: ";
                                std::cin >> progress;
                                challenges[progressId - 1].updateProgress(username, progress);
                            }
                            else {
                                std::cout << "Invalid challenge ID!\n";
                            }
                            break;
                        }
                        case 4: {
                            int leaderboardId;
                            std::cout << "Enter the ID of the challenge to view leaderboard: ";
                            std::cin >> leaderboardId;
                            if (leaderboardId >= 1 && leaderboardId <= static_cast<int>(challenges.size())) {
                                challenges[leaderboardId - 1].updateLeaderboard();
                            }
                            else {
                                std::cout << "Invalid challenge ID!\n";
                            }
                            break;
                        }
                        case 5:
                            std::cout << "Exiting...\n";
                            goto A;
                            break;
                        default:
                            std::cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                        }
                    } while (choice != 5);

                    Challenge::saveChallengesToFile(challenges, "challenges.txt");
                    return 0;
                }
                case 6:
                {
                    FitnessApp app;
                    int locationChoice, activityChoice;
                    double caloriesBurned;
                    char C;
                C:
                    cin.get();
                    clearScreen();
                    app.displayLocations();
                    cout << "5. Back to User Menu\n";
                    cout << "Enter your choice: ";
                    cin >> locationChoice;
                    if (locationChoice == 5)
                    {
                        goto  A;
                    }
                    LocationBasedActivity* selectedLocation = app.selectLocation(locationChoice);
                    if (selectedLocation) {
                        selectedLocation->displayActivities();
                        cout << "Enter the activity you performed: ";
                        cin >> activityChoice;

                        Activity* selectedActivity = selectedLocation->selectActivity(activityChoice);
                        if (selectedActivity) {
                            cout << "Enter calories burned: ";
                            cin >> caloriesBurned;

                            saveData(selectedLocation->getLocationName(), selectedActivity->getName(), caloriesBurned);
                            cin.get();
                            goto C;
                        }
                        else {
                            cout << "Invalid activity choice.\n";
                        }
                    }
                    else {
                        cout << "Invalid location choice.\n";
                    }
                }
                case 7:
                {
                    std::cout << "Returning to Main menu...\n";
                    goto B;
                    break;
                }
                default:
                    std::cout << "Invalid choice!\n";
                    std::cin.get(); // Wait for user to press Enter
                }
                break;
            }
            case 3: { // Reset Password
                std::cout << "Enter username: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, username);
                std::cout << "Enter old password: ";
                std::getline(std::cin, password);
                for (auto& user : users) {
                    if (user.getUsername() == username && user.verifyPassword(password)) {
                        std::cout << "Enter new password: ";
                        std::getline(std::cin, newPassword);
                        user.setPassword(newPassword);
                        FileManager::saveUsers(users, filePath);
                        std::cout << "Password reset successful!\n";
                        std::cout << "Press Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();
                        break;
                    }
                }
                std::cout << "Invalid username or password.\n";
                break;
            }
            case 4: { // Forgot Password
                std::cout << "Enter username: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, username);
                bool found = false;
                for (auto& user : users) {
                    if (user.getUsername() == username) {
                        std::cout << "Your current password is: " << user.getPassword() << ". Please change it upon login.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "User not found.\n";
                }
                std::cout << "Press Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            }
            }
        }
    }
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;

}