#include <iostream>
#include "playlist.h"
int main() {
    Playlist playlist(4);
    const Track tracks[] = {
        {"Midnight Drive", Duration(3, 42)},
        {"Neon Rain", Duration(4, 5)},
        {"Static", Duration(2, 58)},
        {"Low Tide", Duration(5, 11)},
        {"Overflow", Duration(3, 30)}
    };
    for (const Track& track : tracks) {
        if (playlist.add_track(track))
            std::cout << "Added   " << track.title << " (" << track.length << ")\n";
        else
            std::cout << "Refused " << track.title << " (playlist full)\n";
    }
    std::cout << "Tracks: " << playlist.size() << "\n";
    std::cout << "Total length: " << playlist.total_length() << "\n";
    const Track* found = playlist.find_track("Static");
    if (found) std::cout << "Found \"Static\" at " << found->length << "\n";
    if (!playlist.find_track("Missing")) std::cout << "\"Missing\" is not in the playlist.\n";
}
