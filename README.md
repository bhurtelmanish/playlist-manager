# HW2 - Playlist Manager

I made a small playlist program in C++ for this assignment. I used three types: Duration, Track, and Playlist.

I used Duration to store time in seconds and make sure the total is not negative. I used Track to keep a song title and its duration together. I used Playlist to store tracks in a dynamically allocated array. I made sure it refuses empty titles and does not add more tracks than it can hold.

I also overloaded `+`, `==`, and `<<` for Duration. I used `+` when I calculated the total length of the playlist. I used `new[]` in the Playlist constructor and `delete[]` in the destructor.

## How I build and run it

```bash
cmake -S . -B build
cmake --build build
./build/hw2
ctest --test-dir build --output-on-failure
```

I put my GoogleTest tests in `tests/test_hw2.cpp`. I checked normal cases and edge cases, like negative durations, seconds over 59, an empty title, a full playlist, and a missing track.

I put my class sketch and the twelve flowcharts in the `docs` folder.
