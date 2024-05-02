// Copyright 2024 Ian Kruger CSCE240

#ifndef _SONGRECORDING_H_
#define _SONGRECORDING_H_

#include<iostream>
#include<string>
using std::ostream;
using std::string;


namespace csce240_programming_assignment_5 {

class SongRecording {
 // private data members
 private:
  string _title;
  string * _artists;
  int _num_of_artist;
  int _track_length;

 // public methods
 public:
  // a default constructor for the object
  explicit SongRecording(string title = "untitled",
                         string primaryArtist = "unknown", int length = 0,
                         int artnum = 1);
  // we have pointers as data members so we need overload,
  // copy constructor, and destructor
  SongRecording& operator = (const SongRecording& song);

  // since we have pointer data members we need a copy constructor
  SongRecording(const SongRecording& copy);

  // deconstructor for pointers
  ~SongRecording() {
    delete [] _artists;
  }

  // accessor and mutator methods combined with
  // additional functionality for specific pointer allocations
  string GetTitle() const { return _title; }
  // has parameter int of the artists number in terms of order of artist
  string GetArtist(int position = 1) const;
  int GetTrackLength() const { return _track_length; }
  int GetNumArtists() const { return _num_of_artist; }
  void SetTitle(string title);
  void SetArtist(string name, int position = 1);
  // should be non negative
  void SetNumArtists(int num);
  // should be non negative
  void SetTrackLength(int length);
};
}  // namespace csce240_programming_assignment_5
#endif
