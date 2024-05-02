// Copyright 2024 Ian Kruger CSCE240

#include"StreamingTrack.h"
#include"SongRecording.h"
#include<iostream>
using std::ostream;

namespace csce240_programming_assignment_5 {

  // create a basic constructor with default arguments and
  // parameters for the class title, primary artists, length
  // and number of artists for the super constructor, then
  // class specific parameters number of genres and streams
  // Creates a new array for genres using given # of genres
  // and sets the first index as the given primary genre
  StreamingTrack::StreamingTrack(string title, string primary,
                          int track_length, int num_of_artists,
                          string primary_genre, int num_of_streams) :
                          _num_of_genres(1), _streams(num_of_streams),
                          SongRecording(title, primary, track_length,
                          num_of_artists) {
    _genres = new string[_num_of_genres];
    _genres[0] = primary_genre;
  }

  // this is a constructor that takes an instance of another
  // object of the inherited class as well as additional
  // parameteres specific to this class. it follows the same
  // genre creation method.
  StreamingTrack::StreamingTrack(const SongRecording& to_stream,
                                 string primary_genre,
                                 int streams) : _num_of_genres(1),
                                 SongRecording(to_stream),
                                 _streams(streams) {
    _genres = new string[_num_of_genres];
    _genres[0] = primary_genre;
  }

  // this is a copy constructor that takes a completed object
  // of streaming track and creates a new instance of an object
  // using the previous information. It loops through the allocated
  // memory for the genres to prevent leaks.
  StreamingTrack::StreamingTrack(const StreamingTrack& copy) :
                                 _num_of_genres(copy._num_of_genres),
                                 _streams(copy._streams),
                                 SongRecording(copy) {
    _genres = new string[_num_of_genres];
    for ( int i = 0; i < _num_of_genres; ++i )
      _genres[i] = copy._genres[i];
  }

  // this overwrites the assingment operator to allow assignment
  // of instances of this object by copying over the information
  // and dynamically allocating memory for genre through a
  // delete deconstructor
  StreamingTrack& StreamingTrack::operator = (const StreamingTrack& right) {
    _num_of_genres = right._num_of_genres;
    _streams = right._streams;
    SongRecording::operator =(right);
    delete [] _genres;
    _genres = new string[_num_of_genres];
    for ( int i = 0; i < _num_of_genres; ++i )
      _genres[i] = right._genres[i];
    return *this;
  }

  // this function takes an input int streams as
  // the amount of streams for the rack to be set as long
  // as it is non negative
  void StreamingTrack::SetStreams(int streams) {
    if (streams >= 0)
    _streams = streams;
  }

  // this function takes an input int streams and
  // adds it to the objects total streams data member
  // as long as the parameter is non negative
  void StreamingTrack::AddStreams(int streams) {
    if (streams >= 0)
      _streams += streams;
  }

// This function should have a default argument of 1. It
// returns the name of the specified genre if the integer argument is
// between 1 and the number of genres, inclusive. If the integer argument
// is out of range, the function should return the string “out of bounds”
  string StreamingTrack::GetGenre(int position) const {
    if ( position >= 1 && position <= _num_of_genres)
      return _genres[position-1];
    return "out of bounds";
  }

// Returns true if the string argument is one of the
// StreamingTrack’s genres, and false otherwise
  bool StreamingTrack::IsGenre(const string& genre) const {
    for (int i = 0; i < _num_of_genres; i++) {
      if (_genres[i] == genre)
        return true;
    }
    return false;
  }

// Adds the string argument to the StreamingTrack’s
// genres (updating the pointer data member and the number of genres data
// member) if the argument is not already in the list of genres. If the
// argument is already one of the track’s genres, the data members should
// remain unchanged
  void StreamingTrack::AddGenre(const string& genre) {
    if (!IsGenre(genre)) {
      string * temp = new string[_num_of_genres+1];
      for (int i = 0; i < _num_of_genres; i++)
        temp[i] = _genres[i];
      temp[_num_of_genres] = genre;
      delete [] _genres;
      _genres = temp;
      _num_of_genres++;
    }
  }

// Removes the string argument from the
// StreamingTrack’s genres (updating the pointer data member and the number
// of genres data member) if the argument is in the list of genres. If the
// argument is not one of the track’s genres, the data members should
// remain unchanged
  void StreamingTrack::RemoveGenre(const string& genre) {
    if (IsGenre(genre)) {
      string * temp = new string[_num_of_genres-1];
      int j = 0;  // Index for the temporary array
      for (int i = 0; i < _num_of_genres; i++) {
        if (_genres[i] != genre) {
          temp[j++] = _genres[i];
        }
      }
      delete [] _genres;
      _genres = temp;
      _num_of_genres--;
    }
  }

}  // namespace csce240_programming_assignment_5
