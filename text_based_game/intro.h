#ifndef WORLD_INTRO_H
#define WORLD_INTRO_H

#include <string>


class IntroSequence
{
public:
    enum { INTRO_STAGE_BEGIN = 1, INTRO_STAGE_CRASH, INTRO_STAGE_CRASH_B, INTRO_STAGE_LOCKED_DOOR, INTRO_STAGE_FIND_KEY, INTRO_STAGE_GO_SOUTH, INTRO_STAGE_PASSAGE_BLOCKED, INTRO_STAGE_PASSAGE_BLOCKED_B, INTRO_STAGE_KILL_CRATE, INTRO_STAGE_SPECIAL_ABILITY, INTRO_STAGE_HEADLONG_STRIKE, INTRO_STAGE_CRATE_DESTROYED, INTRO_STAGE_COMPLETE };

    static constexpr uint32_t   PRISON_TRAIN =          2955471033; // The room ID for the intro prison train, post-crash.
    static constexpr uint32_t   PRISON_TRAIN_2 =        3245252364; // The room ID for the second train carriage, post-crash.
    static constexpr uint32_t   PRISON_TRAIN_INTRO =    2063573798; // The room ID for the intro prison train, pre-crash.

    static void new_game();     // Sets up the scripted intro sequence
    static void train_crash();  // Triggers the train crash scene.
    static void tutorial_msg(int stage);    // Displays an appropriate tutorial message for the player's current stage of the intro.

private:
    static void starter_equipment(const std::string &list_name);    // Assigns the player starter equipment from a list.
};

#endif  // GREAVE_WORLD_INTRO_H