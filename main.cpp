 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 1)
 */

struct Human
{
    int age;
    double heightInCM;
    int numberOfPets;

    struct Pet 
    {
        bool isCat;
        bool isDog;
        int age;
    };

    bool isPetHungry( Pet pet);
};

/*
 2)
 */

struct Synthesizer 
{
    int polyphony;
    bool multitimbral;

    struct Sequencer
    {
        bool isPlaying = 0;
        bool playForward = 1;
        bool playReverse = 0;
        void playSequence(int sequence);
    };

    Sequencer sequencer;
    void playNote(int frequency);
};

/*
 3)
 */

struct Playlist 
{
    bool isSharable = 1;
    int songs;
    double idOfCoverImage = 8717241; //ID for default image

    bool addSongToPlaylist(int id);
    bool deleteSongFromPlaylist(int id);
    int listSongsInPlaylist();
};

/*
 4)
 */

struct Student
{
    Human student;
    float currentGPA;

    struct Class
    { 
        float currentGrade;
        int daysMissed;
        void addAssignment(double assignmentID, int grade);
        void addMissedDay(bool excused);
    };

    double calculateGPA();
    double calculateTotalDaysMissed();
};

/*
 5)
 */

struct RadioShow
{
    char showDays;
    int showTime;
    double hostID;

    void updateShowTime(double hostID, char updatedShowDay, int updatedShowTime);
};


/*
 6)
 */

struct Driver
{
    Human owner;
    bool licenseIsValid;
    int numberOfViolations;
    int numberOfCars;

    struct Car
    {
        bool isRegistered;
        bool isSmogged;

        bool registerCar();
        bool smogCar();
    };

    bool isDriverAllowedToDrive();
    int addCarToDriver(Car car);
};

/*
 7)
 */

struct Bike
{
    int numberOfGears;
    bool hasDiscBrakes;
    bool hasCarbonFrame;
    Human owner;
};

/*
 8)
 */

struct Artist
{
    double genreId;
    bool isActive;
    Human artist;

    struct Album 
    {
        int numberOfTracks;
        bool isReleased;
    };

    bool addAlbumToArtist(int numberOfTracks, bool isReleased);
};

/*
 9)
 */

struct Patient
{
    Human patient;
    bool hasHadAnnual;
    double doctorId;

    struct Visit 
    {
        int lastVisitDate;
        float icdCode;
        char icdPrefix;
    };

    bool addVisit(Visit visit, double doctor);
    /* why can't I use doctorId as a default? */
};

/*
 10)
 */

struct Band
{
    Artist member1;
    Artist member2;
    Driver tourDriver;
    RadioShow promotionalRadioShow;
};


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
