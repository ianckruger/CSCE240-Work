// Copyright 2024 Ian Kruger CSCE240

#include"SongRecording.h"
#include<iostream>
using std::ostream;
#include<string>
using std::string;

#ifndef _STREAMINGTRACK_H_
#define _STREAMINGTRACK_H_

namespace csce240_programming_assignment_5 {


class StreamingTrack : public SongRecording {
 // public methods
 public:
  // a basic default constructor
  explicit StreamingTrack(string title = "untitled", string primary = "unknown",
                          int track_length = 0, int num_of_artists = 0,
                          string primary_genre = "pop", int num_of_streams = 0);

  // deconstructor since we have pointers as data members
  ~StreamingTrack() {
    delete [] _genres;
  }

  // a copy constructor since we have pointers as data members
  StreamingTrack(const StreamingTrack& copy);
  explicit StreamingTrack(const SongRecording& to_stream,
                          string primary_genre = "pop", int streams = 0);

  // overwriting the assignment operator since we have
  // pointers as data members
  StreamingTrack& operator = (const StreamingTrack& right);

  // Accessor functions for the data members
  int GetStreams() const { return _streams; }
  int GetNumGenres() const { return _num_of_genres; }
  string GetGenre(int position = 1) const;

  // these functions require non negative inputs
  void SetStreams(int streams);
  void AddStreams(int streams);

  // do not change any of the data members if they already exists (for add)
  // or are not in the list (for remove)
  bool IsGenre(const string& genre) const;
  void AddGenre(const string& genre);
  void RemoveGenre(const string& genre);

 // private data members
 private:
  int _streams;
  string * _genres;
  int _num_of_genres;
};

}  // namespace csce240_programming_assignment_5
#endif
