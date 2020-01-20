/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};

/*
 1)
 */

struct Person{ FIXME curly braces go on their own line. See Readme.MD for course coding style
    int age;
    double heightInCM;
    int numberOfPets;

    struct Pet { FIXME curly braces go on their own line. See Readme.MD for course coding style
        bool isCat;
        bool isDog;
        int age;
    };

    bool isPetHungry( Pet pet);
};

/*
 2)
 */

struct Synthesizer { FIXME curly braces go on their own line. See Readme.MD for course coding style
    int polyphony;
    bool multitimbral;

    struct Sequencer { FIXME curly braces go on their own line. See Readme.MD for course coding style
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

struct Playlist { FIXME curly braces go on their own line. See Readme.MD for course coding style
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

struct Student{ FIXME curly braces go on their own line. See Readme.MD for course coding style
    Person student;
    float currentGPA;

    struct Class { FIXME curly braces go on their own line. See Readme.MD for course coding style
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

struct RadioShow { FIXME curly braces go on their own line. See Readme.MD for course coding style
    char showDays;
    int showTime;
    double hostID;

    void updateShowTime(double hostID, char updatedShowDay, int updatedShowTime);
};


/*
 6)
 */

struct Driver{ FIXME curly braces go on their own line. See Readme.MD for course coding style
    Person owner;
    bool licenseIsValid;
    int numberOfViolations;
    int numberOfCars;

    struct Car { FIXME curly braces go on their own line. See Readme.MD for course coding style
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

struct Bike { FIXME curly braces go on their own line. See Readme.MD for course coding style
    int numberOfGears;
    bool hasDiscBrakes;
    bool hasCarbonFrame;
    Person owner;
};

/*
 8)
 */

struct Artist { FIXME curly braces go on their own line. See Readme.MD for course coding style
    double genreId;
    bool isActive;
    Person artist;

    struct Album { FIXME curly braces go on their own line. See Readme.MD for course coding style
        int numberOfTracks;
        bool isReleased;
    };

    bool addAlbumToArtist(int numberOfTracks, bool isReleased);
};

/*
 9)
 */

struct Patient { FIXME curly braces go on their own line. See Readme.MD for course coding style
    Person patient;
    bool hasHadAnnual;
    double doctorId;

    struct Visit { FIXME curly braces go on their own line. See Readme.MD for course coding style
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

struct Band { FIXME curly braces go on their own line. See Readme.MD for course coding style
    Artist member1;
    Artist member2;
    Driver tourDriver;
    RadioShow promotionalRadioShow;
}


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
