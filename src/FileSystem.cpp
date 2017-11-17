//
// Created by aviran on 12/11/17.
//
#include "../include/FileSystem.h"
#include "../include/GlobalVariables.h"

FileSystem::FileSystem():rootDirectory(new Directory("Root", nullptr)),workingDirectory(nullptr){
    workingDirectory = this->rootDirectory;
}

Directory& FileSystem::getRootDirectory() const {
    return *rootDirectory;
}

Directory& FileSystem::getWorkingDirectory() const {
    return *workingDirectory;
}

void FileSystem::setWorkingDirectory(Directory *newWorkingDirectory) {
    workingDirectory = newWorkingDirectory;
}


//............................
//.......RULE OF 5............
//............................

FileSystem::~FileSystem() { //Destructor
    delete(rootDirectory);
    if (verbose==1 || verbose==3)cout << "~FileSystem()" << endl;
}

//Copy Constructor
FileSystem::FileSystem(const FileSystem &other):rootDirectory(nullptr),workingDirectory(nullptr) {
    
    Directory* temp = &other.getRootDirectory();
    rootDirectory = new Directory(*temp);
    temp = &other.getWorkingDirectory();
    workingDirectory = new Directory(*temp);

    if (verbose==1 || verbose==3)cout << "FileSystem(const FileSystem& other)" << endl;
}

FileSystem& FileSystem::operator=(const FileSystem &rhs) {

    rootDirectory = &rhs.getRootDirectory();
    workingDirectory = &rhs.getWorkingDirectory();

    if (verbose==1 || verbose==3)cout << "FileSystem& operator=(const FileSystem& rhs)" << endl;
    return *this;
}

FileSystem& FileSystem::operator=(FileSystem &&rhs) {

    rootDirectory = &rhs.getRootDirectory();
    workingDirectory = &rhs.getWorkingDirectory();

    if (verbose==1 || verbose==3)cout << "FileSystem& operator=(FileSystem&& rhs)" << endl;
    return *this;
}

FileSystem::FileSystem(FileSystem &&rhs):rootDirectory(&rhs.getRootDirectory()),workingDirectory(&rhs.getWorkingDirectory()) {

    if (verbose==1 || verbose==3)cout << "FileSystem(FileSystem&& rhs)" << endl;
}


