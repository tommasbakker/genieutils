/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef GENIE_SLPFILE_H
#define GENIE_SLPFILE_H

#include <istream>
#include <vector>

#include "genie/file/IFile.h"
#include "genie/util/Logger.h"
#include "PalFile.h"

namespace genie
{

class SlpFrame;

class SlpFile : public IFile
{

public:
  //----------------------------------------------------------------------------
  /// Constructor
  //
  SlpFile();
  
  //----------------------------------------------------------------------------
  /// Destructor
  //
  virtual ~SlpFile();
  
  //----------------------------------------------------------------------------
  void unload(void);
  
  //----------------------------------------------------------------------------
  bool isLoaded(void) const;
  
  //----------------------------------------------------------------------------
  /// Return number of frames stored in the file. Available after load.
  ///
  /// @return number of frames
  //
  uint32_t getFrameCount();
  
  //----------------------------------------------------------------------------
  /// Returns the internal slp id.
  ///
  /// @return id
  //
  int32_t getId();
  
  //----------------------------------------------------------------------------
  /// Returns the slp frame at given frame index.
  ///
  /// @param frame frame index
  /// @return SlpFrame
  //
  SlpFrame& getFrame(uint32_t frame=0);
  
private: 
  //SlpFile();
  
  bool loaded_;
  
  uint32_t id_;
  uint32_t len_;
  
  uint32_t num_frames_;
  
  typedef std::vector<SlpFrame> FrameVector;
  FrameVector frames_;
  
  static Logger &log;
  
  //----------------------------------------------------------------------------
  virtual void serializeObject(void);
  
  //----------------------------------------------------------------------------
  /// Loads the file and its frames.
  //
  void loadFile(void);
  
  //----------------------------------------------------------------------------
  void readHeader();
};

typedef boost::shared_ptr<SlpFile> SlpFilePtr;

}

#endif // GENIE_SLPFILE_H