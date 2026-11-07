#include "duration.h"
#include <iomanip>
#include <limits>

Duration::Duration(int minutes, int seconds) : m_total_seconds(0) {
    long long total = static_cast<long long>(minutes) * 60 + seconds;
    if (total > 0) {
        if (total > std::numeric_limits<int>::max()) total = std::numeric_limits<int>::max();
        m_total_seconds = static_cast<int>(total);
    }
}
int Duration::total_seconds() const { return m_total_seconds; }
Duration Duration::operator+(const Duration& other) const {
    // Use the constructor to keep the result nonnegative and in range.
    long long total = static_cast<long long>(m_total_seconds) + other.m_total_seconds;
    if (total > std::numeric_limits<int>::max()) total = std::numeric_limits<int>::max();
    return Duration(0, static_cast<int>(total));
}
bool Duration::operator==(const Duration& other) const {
    return m_total_seconds == other.m_total_seconds;
}
std::ostream& operator<<(std::ostream& out, const Duration& d) {
    int total = d.total_seconds();
    char previous = out.fill('0');
    out << total / 60 << ':' << std::setw(2) << total % 60;
    out.fill(previous);
    return out;
}
