// Copyright 2024 Ian Kruger CSCE240

#include"SongRecording.h"
#include<iostream>
#include<string>

namespace csce240_programming_assignment_5 {
  // This is a constructor for the object Sound Recording,
  // taking parameter inputs of a string title, a string primary
  // artist, an int length of song, and an int number of artists
  // it then creates a new instance of the data member artists
  // for correct memory allocation and sets the first index as the
  // given primary artist.
  SongRecording::SongRecording(string title, string primaryArtist,
                               int length, int artnum) : _track_length(0),
                                _num_of_artist(1), _title("untitled") {
  // Allocate memory for artists array
  _artists = new string[_num_of_artist];

  // Set default artist if no primary artist is provided
  if (primaryArtist.length()< 1)
    primaryArtist = "unknown";
  _artists[0] = primaryArtist;

  // Setters
  SetNumArtists(artnum);
  SetTitle(title);
  SetTrackLength(length);
  }

  // this is a copy constructor that uses an instance of
  // another object to create a new object using the
  // information of the previous one
  SongRecording::SongRecording(const SongRecording& b) :
                               _track_length(b._track_length),
                               _num_of_artist(0),
                               _title(b._title),
                               _artists(nullptr) {
    SetNumArtists(b._num_of_artist);
    for ( int i = 0; i < _num_of_artist; ++i )
        _artists[i] = b._artists[i];
  }

  // this function takes the input string title
  // to set the title of the object as that string as
  // long as the string size is at least 1 character
  void SongRecording::SetTitle(string title) {
    if (title.size() > 0)
      _title = title;
  }

  // this function dynamically sets the number of
  // artist to the given parameter, ensuring to create
  // a new instance of a string pointer using the new
  // size and copying over the previous artists to the
  // new sized array
  void SongRecording::SetNumArtists(int num) {
    if ( num > 0 && num != _num_of_artist ) {
      if ( _artists != nullptr ) {
      string * copyartists = new string[num];
      for ( int i = 0; i < num-1; i++ )
        copyartists[i] = _artists[i];
      delete [] _artists;
      _artists = copyartists;
      } else {
        _artists = new string[num];
      }
      _num_of_artist = num;
    }
  }

  // this function takes the input int length to
  // set the objects song length as the int as long as
  // the int is non negative.
  void SongRecording::SetTrackLength(int length) {
      if ( length >= 0 )
        _track_length = length;
  }

  // this function overloads the assignment operator to allow
  // for the obejct to create instances of this object from other objects
  SongRecording& SongRecording::operator = (const SongRecording& right) {
    _title = right._title;
    SetNumArtists(right._num_of_artist);
    _track_length = right._track_length;
    for ( int i = 0; i < _num_of_artist; ++i )
    _artists[i] = right._artists[i];
    return *this;
  }

  // this function returns a string of an artists name
  // based on the parameter position of the artist within the array
  string SongRecording::GetArtist(int position) const {
    if ( position > _num_of_artist || position < 1 )
      return "out of bounds";
    return _artists[position-1];
  }

  // this function sets the string artist given in the parameter to
  // the position within the array also given in the parameter as
  // long as the position is at least 1 and at most the size of
  // the data member number of artists, and as long as the
  // name of the artists is at least 1 character
  void SongRecording::SetArtist(string name, int position)  {
    if ( position >= 1 && position <= _num_of_artist && name.size() >= 1)
      _artists[position-1] = name;
  }


}  // namespace csce240_programming_assignment_5
