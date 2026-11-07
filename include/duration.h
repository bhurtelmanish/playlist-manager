#ifndef DURATION_H
#define DURATION_H
#include <ostream>
/** @brief A nonnegative length of time. Invariant: m_total_seconds >= 0. */
class Duration {
public:
    /** @brief Make a duration and clamp a negative total to zero. @param minutes Number of minutes. @param seconds Extra seconds. */
    Duration(int minutes = 0, int seconds = 0);
    /** @brief Get the length in seconds. @return Total seconds. */
    int total_seconds() const;
    /** @brief Add two durations. @param other Duration to add. @return Combined duration. */
    Duration operator+(const Duration& other) const;
    /** @brief Compare durations. @param other Duration to compare. @return True if equal. */
    bool operator==(const Duration& other) const;
private:
    int m_total_seconds;
};
/** @brief Print a duration as m:ss. @param out Output stream. @param d Duration to print. @return Output stream. */
std::ostream& operator<<(std::ostream& out, const Duration& d);
#endif
