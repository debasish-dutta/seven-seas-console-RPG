#ifndef INTRO_H
#define INTRO_H

#include <string>


class IntroSequence
{
public:

    static void tutorial_msg(int stage);    // Displays an appropriate tutorial message for the player's current stage of the intro.

private:
    static void starter_equipment(const std::string &list_name);
};

#endif
