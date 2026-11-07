#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include "track.h"
/** @brief Fixed-capacity playlist. Invariants: 0 <= m_count <= m_capacity; capacity >= 1; m_tracks owns an array of m_capacity tracks; stored titles are nonempty. */
class Playlist {
public:
    /** @brief Create an empty playlist. @param capacity Maximum number of tracks, at least one. */
    explicit Playlist(int capacity);
    /** @brief Release the owned array. */
    ~Playlist();
    /** @brief Append a valid track if space exists. @param track Track to add. @return True if added. */
    bool add_track(const Track& track);
    /** @brief Count stored tracks. @return Track count. */
    int size() const;
    /** @brief Sum all track lengths. @return Total duration. */
    Duration total_length() const;
    /** @brief Find the first exact title match. @param title Title to search. @return Pointer to matching track or nullptr. */
    const Track* find_track(const std::string& title) const;
    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;
private:
    Track* m_tracks;
    int m_count;
    int m_capacity;
};
#endif
