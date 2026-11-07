#ifndef TRACK_H
#define TRACK_H
#include <string>
#include "duration.h"
/** @brief A song title and its length. */
struct Track {
    std::string title;
    Duration length;
};
#endif
