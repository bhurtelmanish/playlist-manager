# My class sketch

## Duration
- Private data: `int m_total_seconds`.
- Invariant: I keep the number of seconds at zero or above.
- Public functions: constructor, `total_seconds`, `operator+`, and `operator==`.
- I also use a separate `operator<<` to print the duration.

## Playlist
- Private data: `Track* m_tracks`, `int m_count`, `int m_capacity`.
- Invariants: I keep the capacity at least 1, the count between 0 and capacity, and every stored title nonempty. The pointer owns an array of exactly capacity tracks.
- Public functions: constructor, destructor, `add_track`, `size`, `total_length`, `find_track`.
- I disable copying so two playlists cannot delete the same array.
