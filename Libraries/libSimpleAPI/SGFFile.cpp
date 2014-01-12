#include "SGFFile.h"
#include "OSTools.h"
#include "dataVector.h"
#include "binaryReader.h"

SGFFile SGFFile::OpenFile(const string& path) {
    IFStreamReader file(path.c_str());
    BinaryReader reader(file);

    SGFFile sgf;
    sgf.path = path;


    /*
     * Read the SGF...
     */
    static DataVector data(file.Size());
    data.ReserveAtLeast(file.Size());
    data[file.Size()] = '\0';

    BinaryWriter writer(data);
    reader.Read(writer,file.Size());

    sgf.sgfContents = data.StringData();

    // We're done with it
    return std::move(sgf);
}

string SGFFile::SGF() const {
    return this->sgfContents;
}

string SGFFile::Directory() const {
    return OS::Dirname(this->path);
}

string SGFFile::Name() const {
    return OS::Basename(this->path);
}

string SGFFile::Path() const {
    return this->path;
}

