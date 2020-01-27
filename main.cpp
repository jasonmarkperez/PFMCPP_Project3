
#include <iostream>
#include <vector>
using namespace std;
/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate a few of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.


/*
 1)
 */
 
struct Pet 
{
    int age;
    bool isCat, isDog, isPetHappy;
    bool isPetHungry = true;
    void feedPet();
    void status();
};

struct Human
{
    Pet pet;
    string name;

    bool licenseIsValid;
    bool hasBike;
    int numberOfViolations;
    int numberOfCars = 0;
    // Car car;
    bool isDriverAllowedToDrive();
    bool isPetHungry(Pet);
};

bool Human::isPetHungry(Pet ourPet)
{
    if(ourPet.isPetHungry)
    {
        std::cout << "Pet is hungry!" << std::endl;
        return true;
    }
    else 
    {
        return false;
    }
}

void Pet::feedPet()
{
    isPetHungry = false;
    isPetHappy = true;
}

void Pet::status(){
    cout << isPetHungry << endl;
    cout << isPetHappy << endl;
}

/*
 2)
 */

struct Sequencer
{
    bool isPlaying = 0;
    bool playForward = 1;
    bool playReverse = 0;
    vector<int> notes;

    void recordNote(int);
    void playBack();
};

struct Synthesizer 
{
    unsigned int polyphony = 0;
    unsigned int notesOn = 0;
    bool multitimbral;

    Sequencer sequencer;
    void noteOn();
    void noteOff();
};

void Synthesizer::noteOn()
{
    if(notesOn < polyphony) {
        ++ notesOn;
    }
}

void Synthesizer::noteOff()
{
    -- notesOn;
}


void Sequencer::recordNote(int note)
{
    notes.push_back(note);
}

void Sequencer::playBack()
{
    for( auto& n : notes )
    {
        cout << n << endl; 
    }
}

/*
 3)
 */

struct Playlist 
{
    bool isSharable = 1;
    vector<int> songs;
    double idOfCoverImage = 8717241; //ID for default image

    void addSongToPlaylist(int);
    void deleteSongFromPlaylist(int);
    void listSongsInPlaylist();
};

void Playlist::listSongsInPlaylist()
{
    for( auto& s : songs )
    {
        cout << s << endl; 
    }
}

void Playlist::addSongToPlaylist(int id)
{
    songs.push_back(id);
}

/*
 4)
 */

struct Student
{
    string name;
    float currentGPA;

    double calculateGPA();
    double calculateTotalDaysMissed();
};


struct Class
{
    vector<string> students;
    float currentGrade;
    int daysMissed = 0;

    void addMissedDay();
    void addStudent(Student);
};


void Class::addMissedDay()
{
    ++daysMissed;
}

void Class::addStudent(Student student)
{
    students.push_back(student.name);
}

/*
 5)
 */

struct RadioShow
{
    string showDay;
    string featuredBand;
    double showTime;
    int hostID;
    void updateShowTime(int, string, double);
};

void RadioShow::updateShowTime(int updatedHostID, string updatedShowDay, double updatedShowTime)
{
    hostID = updatedHostID;
    showDay = updatedShowDay;
    showTime = updatedShowTime;
}

/*
 6)
 */

struct Car
{
    string driverName;
    bool isRegistered;
    bool isSmogged;

    void registerCar();
    void smogCar();
    void addDriver(Human);
};

void Car::smogCar()
{
    isSmogged = true;
}

void Car::registerCar()
{   
    isRegistered = true;
}

void Car::addDriver(Human human)
{
    driverName = human.name;
    ++ human.numberOfCars;
}


/*
 7)
 */

struct Bike
{
    int numberOfGears;
    string bikeOwner;
    bool hasDiscBrakes;
    bool hasCarbonFrame;
    void addBicyclist(Human);
};

void Bike::addBicyclist(Human human)
{
    human.hasBike = true;
    bikeOwner = human.name;
}

/*
 8)
 */

struct Album 
{
    int numberOfTracks;
    bool isReleased;
};

struct Artist
{
    Album album;
    double genreId;
    bool isActive;

    void addAlbumToArtist(Album);
};

void Artist::addAlbumToArtist(Album addedAlbum)
{
    album = addedAlbum;
}

/*
 9)
 */

struct Visit 
{
    int visitDate;
    float icdCode;
    char icdPrefix;
};

struct Patient
{
    Human patient;
    bool hasHadAnnual;
    string doctor;
    int lastVisitDate;

    void addVisit(Visit, string);
};

void Patient::addVisit(Visit visit, string visitDoctor)
{
    lastVisitDate = visit.visitDate;
    doctor = visitDoctor;
}

/*
 10)
 */

struct Band
{
    string name;
    Artist member1;
    Artist member2;
    RadioShow promotionalRadioShow;
    void addBandToRadioshow(RadioShow);
};

void Band::addBandToRadioshow(RadioShow rs)
{
    rs.featuredBand = name;
}

int main()
{
    Example::main();
}
