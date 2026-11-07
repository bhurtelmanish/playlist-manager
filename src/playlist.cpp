#include "playlist.h"
Playlist::Playlist(int capacity)
    : m_tracks(nullptr), m_count(0), m_capacity(capacity < 1 ? 1 : capacity) {
    m_tracks = new Track[m_capacity];
}
Playlist::~Playlist() { delete[] m_tracks; }
bool Playlist::add_track(const Track& track) {
    if (m_count == m_capacity || track.title.empty()) return false;
    m_tracks[m_count] = track;
    ++m_count;
    return true;
}
int Playlist::size() const { return m_count; }
Duration Playlist::total_length() const {
    Duration total;
    for (int i = 0; i < m_count; ++i) total = total + m_tracks[i].length;
    return total;
}
const Track* Playlist::find_track(const std::string& title) const {
    for (int i = 0; i < m_count; ++i) {
        if (m_tracks[i].title == title) return &m_tracks[i];
    }
    return nullptr;
}
