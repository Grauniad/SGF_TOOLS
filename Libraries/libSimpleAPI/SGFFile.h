#ifndef __SGF_TOOLS_LIBRARIES__LIB_SIMPLE_API_H__
#define __SGF_TOOLS_LIBRARIES__LIB_SIMPLE_API_H__

#include "stdReader.h"

class SGFFile  {
public:
    static SGFFile OpenFile(const string& path);

    string SGF() const;

    string Name() const;

    string Path() const;

    string Directory() const;
private:
    SGFFile (): sgfContents(""), path("") {}

    string sgfContents;
    string path;
};

#endif
