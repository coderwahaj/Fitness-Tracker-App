#ifndef MENU_H
#define MENU_H

#include "Trainer.h"

class Menu {
public:
    static void mainMenu(Trainer& trainer);
    static void editMenu(Trainer& trainer);
    static void trainingMenu();
    static void paymentMenu();
};

#endif